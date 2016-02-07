#include "controleurongletactions.h"

#include "Controleurs/application.h"

#include <QLayout>
#include <QSqlQueryModel>

ControleurOngletActions::ControleurOngletActions(QWidget* vue)
    : QObject(vue)
{
    splitter = new QSplitter(Qt::Vertical, vue);
    splitter->setChildrenCollapsible(false);
    vue->layout()->addWidget(splitter);
    configurerFragmentActions();
    configurerFragmentEnsembles();
    fragmentActions->champ()->setFocus();
}

// Actions

void ControleurOngletActions::configurerFragmentActions()
{
    requeteActions = RequetesSQL::afficherActionsActives;
    requeteActionsFiltre = RequetesSQL::filtrerActionsActives;
    fragmentActions = new Fragment(splitter);
    controleurActions = new ControleurActions(fragmentActions);
    fragmentActions->setEtiquette(tr("Actions"));
    fragmentActions->caseCocher()->setText(tr("Afficher toutes les actions"));

    QPushButton* boutonEtat = fragmentActions->ajouterBouton(4);
    boutonEtat->setText(tr("Changer l'état"));
    boutonEtat->setIcon(QIcon(":/Images/reverse"));
    boutonEtat->setEnabled(false);

    QObject::connect(fragmentActions, SIGNAL(clicEditer()), this, SLOT(modifierAction()));
    QObject::connect(fragmentActions, SIGNAL(clicCreer()), controleurActions, SLOT(creerAction()));
    QObject::connect(fragmentActions, SIGNAL(clicVoir()), this, SLOT(voirAction()));
    QObject::connect(fragmentActions, SIGNAL(caseCochee()), this, SLOT(desactiverCritereActions()));
    QObject::connect(fragmentActions, SIGNAL(caseDecochee()), this, SLOT(activerCritereActions()));
    QObject::connect(fragmentActions, SIGNAL(rechercher(QString)), this, SLOT(filtrerActions(QString)));
    QObject::connect(boutonEtat, SIGNAL(clicked()), this, SLOT(changerEtatAction()));
    QObject::connect(fragmentActions, SIGNAL(doubleClicModele()), this, SLOT(voirAction()));
}

void ControleurOngletActions::peuplerActions()
{
    QSqlQueryModel* actions = new QSqlQueryModel(this);
    actions->setQuery(*requeteActions, *Application::bd);
    fragmentActions->peuplerTableau(actions);
    fragmentActions->getTableau()->hideColumn(0);
}

void ControleurOngletActions::filtrerActions(const QString &filtre)
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
        fragmentActions->getTableau()->resizeColumnsToContents();
    }
}

void ControleurOngletActions::modifierAction()
{
    if (fragmentActions->getIdModele() != -1) {
        controleurActions->modifierAction(fragmentActions->getIdModele());
    }
}

void ControleurOngletActions::voirAction()
{
    if (fragmentActions->getIdModele() != -1) {
        controleurActions->voirAction(fragmentActions->getIdModele());
    }
}

void ControleurOngletActions::changerEtatAction()
{
    if (fragmentActions->getIdModele() != -1) {
        controleurActions->changerEtat(fragmentActions->getIdModele());
    }
}

void ControleurOngletActions::rechargerActions()
{
    filtrerActions(fragmentActions->getFiltre());
}

void ControleurOngletActions::activerCritereActions()
{
    requeteActions = RequetesSQL::afficherActionsActives;
    requeteActionsFiltre = RequetesSQL::filtrerActionsActives;
    filtrerActions(fragmentActions->getFiltre());
}

void ControleurOngletActions::desactiverCritereActions() {
    requeteActions = RequetesSQL::afficherToutesActions;
    requeteActionsFiltre = RequetesSQL::filtrerToutesActions;
    filtrerActions(fragmentActions->getFiltre());
}

// Ensembles

void ControleurOngletActions::configurerFragmentEnsembles()
{
    fragmentEnsembles = new Fragment(splitter);
    controleurEnsembles = new ControleurGestionEnsemble(fragmentEnsembles);
    fragmentEnsembles->setEtiquette(tr("Ensembles"));
    fragmentEnsembles->caseCocher()->setHidden(true);
    QPushButton* boutonSupprimer = fragmentEnsembles->ajouterBouton(4);
    boutonSupprimer->setText(tr("Supprimer"));
    boutonSupprimer->setIcon(QIcon(":/Images/edit-delete"));
    QObject::connect(controleurEnsembles, SIGNAL(ensemblesModifies()), this, SLOT(peuplerEnsembles()));
    QObject::connect(controleurActions, SIGNAL(actionsModifiees()), this, SLOT(rechargerActions()));
    QObject::connect(fragmentEnsembles, SIGNAL(clicCreer()), controleurEnsembles, SLOT(creerEnsemble()));
    QObject::connect(fragmentEnsembles, SIGNAL(clicEditer()), this, SLOT(modifierEnsemble()));
    QObject::connect(fragmentEnsembles, SIGNAL(doubleClicModele()), this, SLOT(voirEnsemble()));
    QObject::connect(fragmentEnsembles, SIGNAL(clicVoir()), this, SLOT(voirEnsemble()));
    QObject::connect(fragmentEnsembles, SIGNAL(rechercher(QString)), this, SLOT(filtrerEnsembles(QString)));
    QObject::connect(boutonSupprimer, SIGNAL(clicked()), this, SLOT(supprimerEnsemble()));
}

void ControleurOngletActions::peuplerEnsembles()
{
    QSqlQueryModel* ensembles = new QSqlQueryModel(this);
    ensembles->setQuery(*RequetesSQL::afficherEnsembles, *Application::bd);
    fragmentEnsembles->peuplerTableau(ensembles);
    fragmentEnsembles->getTableau()->hideColumn(0);
}

void ControleurOngletActions::filtrerEnsembles(const QString &filtre)
{
    if (filtre.isEmpty()) {
        peuplerEnsembles();
    } else {
        QSqlQuery requete = QSqlQuery(*Application::bd);
        requete.prepare(*RequetesSQL::filtrerEnsembles);
        const QString meta = *ControleurBD::meta;
        requete.bindValue(":filtre", meta + filtre + meta);
        requete.exec();
        QSqlQueryModel* resultats = new QSqlQueryModel(this);
        resultats->setQuery(requete);
        fragmentEnsembles->peuplerTableau(resultats);
        fragmentEnsembles->getTableau()->hideColumn(0);
    }
}

void ControleurOngletActions::modifierEnsemble()
{
    if (fragmentEnsembles->getIdModele() != -1) {
        controleurEnsembles->modifierEnsemble(fragmentEnsembles->getIdModele());
    }
}

void ControleurOngletActions::voirEnsemble()
{
    if (fragmentEnsembles->getIdModele() != -1) {
        controleurEnsembles->voirEnsemble(fragmentEnsembles->getIdModele());
    }
}

void ControleurOngletActions::supprimerEnsemble()
{
    if (fragmentEnsembles->getIdModele() != -1) {
        controleurEnsembles->supprimerEnsemble(fragmentEnsembles->getIdModele());
    }
}

void ControleurOngletActions::rechargerEnsembles()
{
    filtrerEnsembles(fragmentEnsembles->getFiltre());
}
