#include "Controleurs/controleurfiches.h"
#include "ui_vueprincipale.h"

#include "Controleurs/controleurbd.h"

#include <QSqlQueryModel>

ControleurFiches::ControleurFiches(VuePrincipale* vuePrincipale, QObject* parent)
    : QObject(parent) {
    fragment = new VueFragment();
    fragment->getEtiquette()->setText(tr("Fiches"));
    fragment->getCaseCocher()->setText(tr("Afficher toutes les fiches"));
    vuePrincipale->getUi()->ongletFiches->layout()->addWidget(fragment);
    requeteFiches = new QString("select * from fiches");
}

void ControleurFiches::peuplerFiches() {
    QSqlQueryModel* fiches = new QSqlQueryModel(this);
    const QSqlDatabase bd = QSqlDatabase::database(ControleurBD::nomBd());
    fiches->setQuery(*requeteFiches, bd);
    fragment->peuplerTableau(fiches);

}

void ControleurFiches::modifierFiche() {

}

void ControleurFiches::voirFiche() {
}

