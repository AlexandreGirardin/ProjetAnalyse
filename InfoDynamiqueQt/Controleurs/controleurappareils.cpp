#include "controleurappareils.h"
#include "ui_vueprincipale.h"

#include <QSqlQueryModel>

ControleurAppareils::ControleurAppareils(VuePrincipale* vuePrincipale, QObject* parent)
    : QObject(parent) {
    fragment = new VueFragment();
    fragment->getEtiquette()->setText(tr("Appareils"));
    fragment->getCaseCocher()->hide();
    vuePrincipale->getUi()->ongletAppareils->layout()->addWidget(fragment);
    requeteAppareils = new QString("select * from appareils");
    peuplerAppareils();
}

void ControleurAppareils::peuplerAppareils() {
    QSqlQueryModel* appareils = new QSqlQueryModel(this);
    const QSqlDatabase bd = QSqlDatabase::database("dossiers");
    appareils->setQuery(*requeteAppareils, bd);
    fragment->peuplerTableau(appareils);
}

void ControleurAppareils::modifierAppareil() {

}

void ControleurAppareils::voirAppareil() {
}

