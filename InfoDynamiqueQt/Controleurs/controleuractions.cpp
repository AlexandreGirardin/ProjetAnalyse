#include "controleuractions.h"
#include "ui_vueprincipale.h"

#include "Controleurs/application.h"
#include "Controleurs/controleurbd.h"

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
    QObject::connect(this, SIGNAL(donneesModifiees()), this, SLOT(recharger()));
    QObject::connect(fragmentEnsembles, SIGNAL(clicCreer()), controleurEnsemble, SLOT(modifierEnsemble()));
}

void ControleurActions::assignerAction(VueGestionAction* vue, Action* action) const
{
    vue->setNom(action->getNom());
    vue->setDescription(action->getDescription());
    vue->setEtat(action->getEtat());
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

void ControleurActions::filtrerActions(QString filtre)
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
        VueGestionAction* vue = new VueGestionAction(Application::getVuePrincipale());
        assignerAction(vue, action);
        if (vue->exec()) {
            action->setNom(vue->getNom());
            action->setDescription(vue->getDescription());
            action->setEtat(vue->getEtat());
            if (Application::actions->mettreAJour(action)) {
                emit donneesModifiees();
            }
        }
    }
    action->deleteLater();
}

void ControleurActions::voirAction()
{
    Action* action = Application::actions->getAction(fragmentActions->getIdModele());
    if (action != NULL) {
        VueGestionAction* vue = new VueGestionAction(Application::getVuePrincipale());
        assignerAction(vue, action);
        vue->setLectureSeule(true);
        vue->show();
    }
    action->deleteLater();
}

void ControleurActions::changerEtat()
{
    Action* action = Application::actions->getAction(fragmentActions->getIdModele());
    if (action != NULL) {
        action->setEtat(!action->getEtat());
        if (Application::actions->mettreAJour(action)) {
            emit donneesModifiees();
        }
    }
    action->deleteLater();
}

void ControleurActions::recharger()
{
    filtrerActions(fragmentActions->getFiltre());
}

