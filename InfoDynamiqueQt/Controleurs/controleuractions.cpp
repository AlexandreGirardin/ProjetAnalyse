#include "controleuractions.h"
#include "ui_vueprincipale.h"

#include "Controleurs/application.h"
#include "Controleurs/controleurbd.h"
#include "Vues/vueensemble.h"
#include "Vues/vuegestionensemble.h"

#include <QMessageBox>
#include <QSqlQueryModel>
#include <QDebug>

ControleurActions::ControleurActions(QWidget* vue)
    : QObject(vue)
{
    controleurEnsemble = new ControleurGestionEnsemble(this);

    splitter = new QSplitter(Qt::Vertical, vue);
    splitter->setChildrenCollapsible(false);
    vue->layout()->addWidget(splitter);

    configurerFragmentActions();
    configurerFragmentEnsembles();

    requeteActions = RequetesSQL::afficherActionsActives;
    requeteActionsFiltre = RequetesSQL::filtrerActionsActives;
}

void ControleurActions::configurerFragmentActions()
{
    fragmentActions = new VueFragment(splitter);
    fragmentActions->setEtiquette(tr("Actions"));
    fragmentActions->getCaseCocher()->setText(tr("Afficher toutes les actions"));

    QPushButton* boutonEtat = fragmentActions->ajouterBouton(4);
    boutonEtat->setText(tr("Changer l'état"));
    boutonEtat->setIcon(QIcon(":/Images/reverse"));
    boutonEtat->setEnabled(false);

    QObject::connect(fragmentActions, SIGNAL(clicEditer()), this, SLOT(modifierAction()));
    QObject::connect(fragmentActions, SIGNAL(clicVoir()), this, SLOT(voirAction()));
    QObject::connect(fragmentActions, SIGNAL(caseCochee()), this, SLOT(desactiverCritereActions()));
    QObject::connect(fragmentActions, SIGNAL(caseDecochee()), this, SLOT(activerCritereActions()));
    QObject::connect(fragmentActions, SIGNAL(rechercher(QString)), this, SLOT(filtrerActions(QString)));
    QObject::connect(boutonEtat, SIGNAL(clicked()), this, SLOT(changerEtat()));
}

void ControleurActions::configurerFragmentEnsembles()
{
    fragmentEnsembles = new VueFragment(splitter);
    fragmentEnsembles->setEtiquette(tr("Ensembles"));
    fragmentEnsembles->getCaseCocher()->setHidden(true);
    QPushButton* boutonSupprimer = fragmentEnsembles->ajouterBouton(4);
    boutonSupprimer->setText(tr("Supprimer"));
    boutonSupprimer->setIcon(QIcon(":/Images/edit-delete"));
    QObject::connect(this, SIGNAL(ensemblesModifies()), this, SLOT(peuplerEnsembles()));
    QObject::connect(this, SIGNAL(actionsModifiees()), this, SLOT(recharger()));
    QObject::connect(fragmentEnsembles, SIGNAL(clicCreer()), this, SLOT(creerEnsemble()));
    QObject::connect(fragmentEnsembles, SIGNAL(clicEditer()), this, SLOT(modifierEnsemble()));
    QObject::connect(fragmentEnsembles, SIGNAL(doubleClicModele()), this, SLOT(modifierEnsemble()));
    QObject::connect(fragmentEnsembles, SIGNAL(clicVoir()), this, SLOT(voirEnsemble()));
    QObject::connect(boutonSupprimer, SIGNAL(clicked()), this, SLOT(supprimerEnsemble()));
}

void ControleurActions::assignerAction(VueGestionAction* vue, const Action *action) const
{
    vue->setNom(action->nom());
    vue->setDescription(action->description());
    vue->setEtat(action->etat());
}

void ControleurActions::peuplerActions()
{
    QSqlQueryModel* actions = new QSqlQueryModel(this);
    actions->setQuery(*requeteActions, *Application::bd);
    fragmentActions->peuplerTableau(actions);
    fragmentActions->getTableau()->hideColumn(0);
}

void ControleurActions::peuplerEnsembles()
{
    QSqlQueryModel* ensembles = new QSqlQueryModel(this);
    ensembles->setQuery(*RequetesSQL::afficherEnsembles, *Application::bd);
    fragmentEnsembles->peuplerTableau(ensembles);
    fragmentEnsembles->getTableau()->hideColumn(0);
}

void ControleurActions::activerCritereActions()
{
    requeteActions = RequetesSQL::afficherActionsActives;
    requeteActionsFiltre = RequetesSQL::filtrerActionsActives;
    filtrerActions(fragmentActions->getFiltre());
}

void ControleurActions::desactiverCritereActions() {
    requeteActions = RequetesSQL::afficherToutesActions;
    requeteActionsFiltre = RequetesSQL::filtrerToutesActions;
    filtrerActions(fragmentActions->getFiltre());
}

void ControleurActions::filtrerActions(const QString &filtre)
{
    if (filtre.isEmpty()) {
        peuplerActions();
    } else {
        QSqlQuery requete = QSqlQuery(*Application::bd);
        requete.prepare(*requeteActionsFiltre);
        const QString meta = *ControleurBD::meta;
        requete.bindValue(":filtre", meta + filtre + meta);
        requete.exec();
        QSqlQueryModel* resultats = new QSqlQueryModel(this);
        resultats->setQuery(requete);
        fragmentActions->peuplerTableau(resultats);
        fragmentActions->getTableau()->hideColumn(0);
    }
}

void ControleurActions::modifierAction()
{
    Action* action = Application::actions->getAction(fragmentActions->getIdModele());
    if (action != NULL) {
        VueGestionAction* vue = new VueGestionAction(Application::vuePrincipale());
        assignerAction(vue, action);
        if (vue->exec()) {
            action->setNom(vue->getNom());
            action->setDescription(vue->getDescription());
            action->setEtat(vue->getEtat());
            if (Application::actions->mettreAJour(action)) {
                emit actionsModifiees();
            }
        }
    }
    action->deleteLater();
}

void ControleurActions::voirAction() const
{
    Action* action = Application::actions->getAction(fragmentActions->getIdModele());
    if (action != NULL) {
        VueGestionAction* vue = new VueGestionAction(Application::vuePrincipale());
        assignerAction(vue, action);
        vue->setLectureSeule(true);
        QObject::connect(vue, SIGNAL(finished(int)), vue, SLOT(deleteLater()));
        vue->show();
    }
    action->deleteLater();
}

void ControleurActions::changerEtat()
{
    Action* action = Application::actions->getAction(fragmentActions->getIdModele());
    if (action != NULL) {
        action->setEtat(!action->etat());
        if (Application::actions->mettreAJour(action)) {
            emit actionsModifiees();
        }
    }
    action->deleteLater();
}

void ControleurActions::recharger()
{
    filtrerActions(fragmentActions->getFiltre());
}

void ControleurActions::creerEnsemble()
{
    VueGestionEnsemble* vue = new VueGestionEnsemble(Application::vuePrincipale());
    QList<Action*>* actionsHorsEnsemble = Application::actions->getActions();
    vue->setActionsHorsEnsemble(actionsHorsEnsemble);
    delete actionsHorsEnsemble;
    if (vue->exec() == vue->Accepted) {
        EnsembleActions* ensemble = new EnsembleActions(vue);
        ensemble->setNom(vue->getNom());
        ensemble->setDescription(vue->getDescription());
        ensemble->setActions(vue->getActionsDansEnsemble());
        if (Application::ensembles->inserer(ensemble)) {
            emit ensemblesModifies();
        } else {
            qDebug() << "Pas marché :(";
        }
        vue->deleteLater();
    }
}

void ControleurActions::supprimerEnsemble()
{
    EnsembleActions* ensemble = Application::ensembles->getEnsemble(fragmentEnsembles->getIdModele());
    QMessageBox* confirmation = new QMessageBox(QMessageBox::Warning,
                    tr("Confirmation de la suppression"),
                    tr("Supprimer l'ensemble «") + ensemble->nom()+"» ?",
                    QMessageBox::Apply | QMessageBox::Cancel);
    if (confirmation->exec() == confirmation->Apply) {
        if (Application::ensembles->supprimer(ensemble)) {
            emit ensemblesModifies();
        }
    }
    confirmation->deleteLater();
    ensemble->deleteLater();
}

void ControleurActions::modifierEnsemble()
{
    EnsembleActions* ensemble = Application::ensembles->getEnsemble(fragmentEnsembles->getIdModele());
    VueGestionEnsemble* vue = new VueGestionEnsemble(Application::vuePrincipale());
    QList<Action*>* actionsHorsEnsemble = Application::actions->actionsHorsEnsemble(ensemble->id());
    vue->setActionsHorsEnsemble(actionsHorsEnsemble);
    vue->setActionsDansEnsemble(ensemble->getActions());
    vue->setNom(ensemble->nom());
    vue->setDescription(ensemble->description());
    delete actionsHorsEnsemble;
    if (vue->exec() == vue->Accepted) {
        ensemble->setNom(vue->getNom());
        ensemble->setDescription(vue->getDescription());
        ensemble->setActions(vue->getActionsDansEnsemble());
        if (Application::ensembles->mettreAJour(ensemble)) {
            emit ensemblesModifies();
        } else {
            qDebug() << "Pas marché :(";
        }
        vue->deleteLater();
    }
}

void ControleurActions::voirEnsemble()
{
    VueEnsemble* vue = new VueEnsemble(Application::vuePrincipale());
    QObject::connect(vue, SIGNAL(finished(int)), vue, SLOT(deleteLater()));
    vue->show();
}

