#include "controleurongletactions.h"

#include "Controleurs/application.h"
#include "Controleurs/requetessql.h"
#include "Mappeurs/mappeuractions.h"

#include <QHeaderView>
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
    fragmentActions->setEtiquette(tr("Actions"));
    fragmentActions->caseCocher()->setText(tr("Afficher toutes les actions"));
    fragmentActions->boutonVoir()->deleteLater();

    QObject::connect(fragmentActions, SIGNAL(clicCreer()), this, SLOT(creerAction()));
    QObject::connect(fragmentActions, SIGNAL(clicEditer()), this, SLOT(modifierAction()));
    QObject::connect(fragmentActions, SIGNAL(caseCochee()), this, SLOT(desactiverCritereActions()));
    QObject::connect(fragmentActions, SIGNAL(caseDecochee()), this, SLOT(activerCritereActions()));
    QObject::connect(fragmentActions, SIGNAL(rechercher(QString)), this, SLOT(filtrerActions(QString)));
    QObject::connect(fragmentActions, SIGNAL(doubleClicModele()), this, SLOT(modifierAction()));
    QObject::connect(Application::getInstance(), SIGNAL(actionModifiee()), this, SLOT(rafraichirActions()));
    QObject::connect(Application::getInstance(), SIGNAL(nombreActionsChange()), this, SLOT(rechargerActions()));

    configurerBoutonEtat();
    configurerBoutonSupprimerAction();
}

void ControleurOngletActions::configurerBoutonEtat()
 {
    boutonEtat = fragmentActions->ajouterBouton(3, tr("Changer l'état"), QIcon(":/Images/reverse"));
    boutonEtat->setEnabled(false);
    QObject::connect(boutonEtat, SIGNAL(clicked()), this, SLOT(changerEtatAction()));
}

void ControleurOngletActions::configurerBoutonSupprimerAction()
{
    boutonSupprimerAction = fragmentActions->ajouterBoutonNonConnecte(4, tr("Supprimer"), QIcon(":/Images/edit-delete"));
    boutonSupprimerAction->setEnabled(false);
    QObject::connect(fragmentActions, SIGNAL(selectionValide(bool)), this, SLOT(activerBoutonSupprimerAction(bool)));
    QObject::connect(boutonSupprimerAction, SIGNAL(clicked()), this, SLOT(supprimerAction()));
}

void ControleurOngletActions::peuplerActions()
{
    QSqlQueryModel* actions = new QSqlQueryModel(this);
    actions->setQuery(*requeteActions, *Application::bd);
    fragmentActions->peuplerTableau(actions);
    fragmentActions->tableau()->hideColumn(0);
    fragmentActions->tableau()->horizontalHeader()->stretchLastSection();
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
        fragmentActions->tableau()->hideColumn(0);
        fragmentActions->tableau()->resizeColumnsToContents();
    }
}

void ControleurOngletActions::creerAction()
{
    ControleurActions::creerAction();
}

void ControleurOngletActions::modifierAction()
{
    if (fragmentActions->idModele() != -1) {
        ControleurActions::modifierAction(fragmentActions->idModele());
    }
}

void ControleurOngletActions::changerEtatAction()
{
    if (fragmentActions->idModele() != -1) {
        ControleurActions::changerEtat(fragmentActions->idModele());
    }
}

void ControleurOngletActions::supprimerAction()
{
    if (fragmentActions->idModele() != -1) {
        ControleurActions::effacerAction(fragmentActions->idModele());
    }
}

void ControleurOngletActions::activerBoutonSupprimerAction(const bool &actif)
{
    if (!actif) {
        boutonSupprimerAction->setEnabled(false);
    } else {
        if (MappeurActions::nombreTachesPourAction(fragmentActions->idModele()) == 0) {
            boutonSupprimerAction->setEnabled(true);
            boutonSupprimerAction->setToolTip("");
        } else {
            boutonSupprimerAction->setEnabled(false);
            boutonSupprimerAction->setToolTip(tr("Cette action ne peut pas être supprimée."));
        }
    }
}

void ControleurOngletActions::rechargerActions()
{
    filtrerActions(fragmentActions->filtre());
}

void ControleurOngletActions::activerCritereActions()
{
    requeteActions = RequetesSQL::afficherActionsActives;
    requeteActionsFiltre = RequetesSQL::filtrerActionsActives;
    filtrerActions(fragmentActions->filtre());
}

void ControleurOngletActions::desactiverCritereActions() {
    requeteActions = RequetesSQL::afficherToutesActions;
    requeteActionsFiltre = RequetesSQL::filtrerToutesActions;
    filtrerActions(fragmentActions->filtre());
}

// Ensembles

void ControleurOngletActions::configurerFragmentEnsembles()
{
    fragmentEnsembles = new Fragment(splitter);
    fragmentEnsembles->setEtiquette(tr("Ensembles"));
    fragmentEnsembles->caseCocher()->setHidden(true);
    QPushButton* boutonSupprimer = fragmentEnsembles->ajouterBouton(4, tr("Supprimer"), QIcon(":/Images/edit-delete"));
    QObject::connect(Application::getInstance(), SIGNAL(ensembleModifie()), this, SLOT(ensembleModifie()));
    QObject::connect(fragmentEnsembles, SIGNAL(clicCreer()), this, SLOT(creerEnsemble()));
    QObject::connect(fragmentEnsembles, SIGNAL(clicEditer()), this, SLOT(modifierEnsemble()));
    QObject::connect(fragmentEnsembles, SIGNAL(doubleClicModele()), this, SLOT(voirEnsemble()));
    QObject::connect(fragmentEnsembles, SIGNAL(clicVoir()), this, SLOT(voirEnsemble()));
    QObject::connect(fragmentEnsembles, SIGNAL(rechercher(QString)), this, SLOT(filtrerEnsembles(QString)));
    QObject::connect(boutonSupprimer, SIGNAL(clicked()), this, SLOT(supprimerEnsemble()));
    QObject::connect(Application::getInstance(), SIGNAL(nombreEnsemblesModifie()), this, SLOT(rechargerEnsembles()));
    QObject::connect(Application::getInstance(), SIGNAL(nombreActionsChange()), this, SLOT(rechargerEnsembles()));
}

void ControleurOngletActions::rafraichirActions()
{
    int selection = fragmentActions->tableau()->currentIndex().row();
    rechargerActions();
    fragmentActions->tableau()->selectRow(selection);
}

void ControleurOngletActions::peuplerEnsembles()
{
    QSqlQueryModel* ensembles = new QSqlQueryModel(this);
    ensembles->setQuery(*RequetesSQL::afficherEnsembles, *Application::bd);
    fragmentEnsembles->peuplerTableau(ensembles);
    fragmentEnsembles->tableau()->hideColumn(0);
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
        fragmentEnsembles->tableau()->hideColumn(0);
    }
}

void ControleurOngletActions::creerEnsemble()
{
    ControleurEnsembles::creerEnsemble();
}

void ControleurOngletActions::modifierEnsemble()
{
    if (fragmentEnsembles->idModele() != -1) {
        ControleurEnsembles::modifierEnsemble(fragmentEnsembles->idModele());
    }
}

void ControleurOngletActions::voirEnsemble()
{
    if (fragmentEnsembles->idModele() != -1) {
        ControleurEnsembles::voirEnsemble(fragmentEnsembles->idModele());
    }
}

void ControleurOngletActions::supprimerEnsemble()
{
    if (fragmentEnsembles->idModele() != -1) {
        ControleurEnsembles::supprimerEnsemble(fragmentEnsembles->idModele());
    }
}

void ControleurOngletActions::rechargerEnsembles()
{
    filtrerEnsembles(fragmentEnsembles->filtre());
}

void ControleurOngletActions::ensembleModifie()
{
    int selection = fragmentEnsembles->tableau()->currentIndex().row();
    rechargerEnsembles();
    fragmentEnsembles->tableau()->selectRow(selection);
}
