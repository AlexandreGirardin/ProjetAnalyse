#include "Controleurs/controleurfiches.h"
#include "ui_vueprincipale.h"

#include <QSqlQueryModel>

ControleurFiches::ControleurFiches(VuePrincipale* vuePrincipale, QObject* parent)
    : QObject(parent) {
    fragment = new VueFragment();
    fragment->getEtiquette()->setText("Fiches");
    fragment->getCaseCocher()->setText("Afficher toutes les fiches");
    vuePrincipale->getUi()->ongletFiches->layout()->addWidget(fragment);
    requeteFiches = new QString("select * from fiches");
    peuplerFiches();
}

void ControleurFiches::peuplerFiches() {
    QSqlQueryModel* fiches = new QSqlQueryModel(this);
    const QSqlDatabase bd = QSqlDatabase::database("dossiers");
    fiches->setQuery(*requeteFiches, bd);
    fragment->peuplerTableau(fiches);

}

void ControleurFiches::modifierFiche() {

}

void ControleurFiches::voirFiche() {
}

