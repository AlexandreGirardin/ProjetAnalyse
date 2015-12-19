#include "controleuractions.h"
#include "ui_vueprincipale.h"

#include <QSqlQueryModel>

ControleurActions::ControleurActions(VuePrincipale* vuePrincipale, QObject* parent)
    : QObject(parent) {
    splitter = new QSplitter(Qt::Vertical, vuePrincipale->getUi()->ongletActions);
    vuePrincipale->getUi()->ongletActions->layout()->addWidget(splitter);

    configurerFragmentActions();
    configurerFragmentEnsembles();

    requeteActions = new QString("select * from actions");
    requeteEnsembles = new QString("select * from ensembles");

    peuplerActions();
    peuplerAppareils();
}

void ControleurActions::configurerFragmentActions() {
    fragmentActions = new VueFragment(splitter);
    fragmentActions->getEtiquette()->setText(tr("Actions"));
    fragmentActions->getCaseCocher()->setText(tr("Afficher toutes les actions"));
}

void ControleurActions::configurerFragmentEnsembles() {
    fragmentEnsembles = new VueFragment(splitter);
    fragmentEnsembles->getEtiquette()->setText(tr("Ensembles"));
    fragmentEnsembles->getCaseCocher()->setHidden(true);
}

void ControleurActions::peuplerActions() {
    QSqlQueryModel* actions = new QSqlQueryModel(this);
    const QSqlDatabase bd = QSqlDatabase::database("dossiers");
    actions->setQuery(*requeteActions, bd);
    fragmentActions->peuplerTableau(actions);
}

void ControleurActions::peuplerAppareils() {
    QSqlQueryModel* ensembles = new QSqlQueryModel(this);
    const QSqlDatabase bd = QSqlDatabase::database("dossiers");
    ensembles->setQuery(*requeteEnsembles, bd);
    fragmentEnsembles->peuplerTableau(ensembles);
}

