#include "controleurongletactions.h"

#include "Controleurs/application.h"
#include "Controleurs/controleuractions.h"
#include "Controleurs/controleurensembles.h"
#include "Controleurs/requetessql.h"
#include "Mappeurs/mappeuractions.h"
#include "Vues/fragment.h"

#include <QHeaderView>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSplitter>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>

ControleurOngletActions::ControleurOngletActions(QObject* parent) : QObject(parent) {}

void ControleurOngletActions::charger(QWidget* vue)
{
    splitter = new QSplitter(Qt::Vertical, vue);
    splitter->setChildrenCollapsible(false);
    vue->layout()->addWidget(splitter);
    configurerFragmentActions();
    configurerFragmentEnsembles();
    fragmentActions->champ()->setFocus();
    peuplerActions();
    peuplerEnsembles();
}

// Actions

void ControleurOngletActions::configurerFragmentActions()
{
    fragmentActions = new Fragment(splitter);
    fragmentActions->setEtiquette(tr("Actions"));
    fragmentActions->setTexteCaseCocher(tr("Afficher toutes les actions"));
    fragmentActions->boutonVoir()->deleteLater();

    connect(fragmentActions, SIGNAL(clicCreer()), this, SLOT(creerAction()));
    connect(fragmentActions, SIGNAL(clicEditer()), this, SLOT(modifierAction()));
    connect(fragmentActions, SIGNAL(caseCochee()), this, SLOT(desactiverCritereActions()));
    connect(fragmentActions, SIGNAL(caseDecochee()), this, SLOT(activerCritereActions()));
    connect(fragmentActions, SIGNAL(rechercher(QString)), this, SLOT(filtrerActions(QString)));
    connect(fragmentActions, SIGNAL(doubleClicModele()), this, SLOT(modifierAction()));
    connect(Application::get(), SIGNAL(actionModifiee()), this, SLOT(rafraichirActions()));
    connect(Application::get(), SIGNAL(rafraichirTout()), this, SLOT(rafraichirActions()));
    connect(Application::get(), SIGNAL(nombreActionsChange()), this, SLOT(rechargerActions()));
    fragmentActions->setCaseCochee(true);

    configurerBoutonEtat();
    configurerBoutonSupprimerAction();
}

void ControleurOngletActions::configurerBoutonEtat()
 {
    boutonEtat = fragmentActions->ajouterBouton(3, tr("Changer l'état"), QIcon(":/Images/reverse"));
    boutonEtat->setEnabled(false);
    connect(boutonEtat, SIGNAL(clicked()), this, SLOT(changerEtatAction()));
}

void ControleurOngletActions::configurerBoutonSupprimerAction()
{
    boutonSupprimerAction = fragmentActions->ajouterBoutonNonConnecte(4, tr("Supprimer"), QIcon(":/Images/edit-delete"));
    boutonSupprimerAction->setEnabled(false);
    connect(fragmentActions, SIGNAL(selectionValide(bool)), this, SLOT(activerBoutonSupprimerAction(bool)));
    connect(boutonSupprimerAction, SIGNAL(clicked()), this, SLOT(supprimerAction()));
}

void ControleurOngletActions::peuplerActions()
{
    QSqlQueryModel* actions = new QSqlQueryModel(this);
    actions->setQuery(*requeteActions, *Application::bd);
    fragmentActions->peuplerTableau(actions);
    fragmentActions->cacherColonneId();
    fragmentActions->tableau()->horizontalHeader()->stretchLastSection();
}

void ControleurOngletActions::filtrerActions(const QString &filtre)
{
    if (filtre.isEmpty()) {
        peuplerActions();
    } else {
        QSqlQuery requete = QSqlQuery(*Application::bd);
        requete.prepare(*requeteActionsFiltre);
        const QString meta = *RequetesSQL::meta;
        requete.bindValue(":filtre", meta + filtre + meta);
        requete.exec();
        QSqlQueryModel* resultats = new QSqlQueryModel(this);
        resultats->setQuery(requete);
        fragmentActions->peuplerTableau(resultats);
        fragmentActions->cacherColonneId();
        fragmentActions->tableau()->horizontalHeader()->stretchLastSection();
    }
}

void ControleurOngletActions::creerAction()
{
    int id = ControleurActions::creerAction();
    if (id != -1) {
        fragmentActions->selectionnerModeleParId(id);
    }
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
        int usages = MappeurActions::tachesPourAction(fragmentActions->idModele());
        if (usages == 0) {
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

void ControleurOngletActions::desactiverCritereActions()
{
    requeteActions = RequetesSQL::afficherToutesActions;
    requeteActionsFiltre = RequetesSQL::filtrerToutesActions;
    filtrerActions(fragmentActions->filtre());
}

void ControleurOngletActions::rafraichirActions()
{
    int selection = fragmentActions->rangeeSelectionnee();
    rechargerActions();
    fragmentActions->selectionnerRangee(selection);
}

// Ensembles

void ControleurOngletActions::configurerFragmentEnsembles()
{
    fragmentEnsembles = new Fragment(splitter);
    fragmentEnsembles->setEtiquette(tr("Ensembles"));
    fragmentEnsembles->retirerCaseCocher();
    QPushButton* boutonSupprimer = fragmentEnsembles->ajouterBouton(4, tr("Supprimer"), QIcon(":/Images/edit-delete"));
    connect(Application::get(), SIGNAL(ensembleModifie()), this, SLOT(ensembleModifie()));
    connect(fragmentEnsembles, SIGNAL(clicCreer()), this, SLOT(creerEnsemble()));
    connect(fragmentEnsembles, SIGNAL(clicEditer()), this, SLOT(modifierEnsemble()));
    connect(fragmentEnsembles, SIGNAL(doubleClicModele()), this, SLOT(voirEnsemble()));
    connect(fragmentEnsembles, SIGNAL(clicVoir()), this, SLOT(voirEnsemble()));
    connect(fragmentEnsembles, SIGNAL(rechercher(QString)), this, SLOT(filtrerEnsembles(QString)));
    connect(boutonSupprimer, SIGNAL(clicked()), this, SLOT(supprimerEnsemble()));
    connect(Application::get(), SIGNAL(rafraichirTout()), this, SLOT(rechargerEnsembles()));
    connect(Application::get(), SIGNAL(nombreEnsemblesModifie()), this, SLOT(rechargerEnsembles()));
    connect(Application::get(), SIGNAL(nombreActionsChange()), this, SLOT(rechargerEnsembles()));
}

void ControleurOngletActions::peuplerEnsembles()
{
    QSqlQueryModel* ensembles = new QSqlQueryModel(this);
    ensembles->setQuery(*RequetesSQL::afficherEnsembles, *Application::bd);
    fragmentEnsembles->peuplerTableau(ensembles);
    fragmentEnsembles->cacherColonneId();
}

void ControleurOngletActions::filtrerEnsembles(const QString &filtre)
{
    if (filtre.isEmpty()) {
        peuplerEnsembles();
    } else {
        QSqlQuery requete = QSqlQuery(*Application::bd);
        requete.prepare(*RequetesSQL::filtrerEnsembles);
        const QString meta = *RequetesSQL::meta;
        requete.bindValue(":filtre", meta + filtre + meta);
        requete.exec();
        QSqlQueryModel* resultats = new QSqlQueryModel(this);
        resultats->setQuery(requete);
        fragmentEnsembles->peuplerTableau(resultats);
        fragmentEnsembles->cacherColonneId();
    }
}

void ControleurOngletActions::creerEnsemble()
{
    int id = ControleurEnsembles::creerEnsemble();
    if (id != -1) {
        fragmentEnsembles->selectionnerModeleParId(id);
    }
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
    int selection = fragmentEnsembles->rangeeSelectionnee();
    rechargerEnsembles();
    fragmentEnsembles->selectionnerRangee(selection);
}
