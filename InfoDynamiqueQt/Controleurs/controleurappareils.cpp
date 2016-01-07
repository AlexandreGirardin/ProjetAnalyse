#include "controleurappareils.h"
#include "ui_vueprincipale.h"

#include "Controleurs/controleurbd.h"

#include <QSqlQueryModel>

ControleurAppareils::ControleurAppareils(VuePrincipale* vuePrincipale, QObject* parent)
    : QObject(parent) {
    fragment = new VueFragment();
    fragment->getEtiquette()->setText(tr("Appareils"));
    fragment->getCaseCocher()->hide();
    vuePrincipale->getUi()->ongletAppareils->layout()->addWidget(fragment);
    definirCommandes();
    QObject::connect(fragment, SIGNAL(rechercher(QString)), this, SLOT(filtrerAppareils(QString)));
}

void ControleurAppareils::definirCommandes() {
    commandeAppareils = new QString(
            "SELECT\
                a.id AS '#',\
                f.nom AS 'Fabricant',\
                COALESCE(fi.nbO, 0) as 'Fiches',\
                a.description AS 'Description'\
            FROM\
                appareils a\
            LEFT OUTER JOIN\
                (select id, nom from fabricants) f\
            ON\
                a.idFabricant = f.id\
            LEFT OUTER JOIN\
                (select idAppareil, count(id) as 'nbO' from fiches group by idAppareil) fi\
            ON\
                a.id = fi.idAppareil");
    commandeFiltrerAppareils = new QString(*commandeAppareils +
                                           QString(" WHERE a.id LIKE :filtre\
                                                   OR f.nom LIKE :filtre\
                                                   OR a.description LIKE :filtre"));
}

void ControleurAppareils::peuplerAppareils() {
    QSqlQueryModel* appareils = new QSqlQueryModel(this);
    const QSqlDatabase bd = QSqlDatabase::database(ControleurBD::nomBd());
    appareils->setQuery(*commandeAppareils, bd);
    fragment->peuplerTableau(appareils);
}

void ControleurAppareils::modifierAppareil() {

}

void ControleurAppareils::voirAppareil() {
}

void ControleurAppareils::filtrerAppareils(QString filtre) {
    if (filtre.isEmpty()) {
        peuplerAppareils();
    } else {
        QSqlQuery requete = QSqlQuery(QSqlDatabase::database(ControleurBD::nomBd()));
        requete.prepare(*commandeFiltrerAppareils);
        const QString* meta = ControleurBD::meta();
        requete.bindValue(":filtre", *meta + filtre + *meta);
        requete.exec();
        QSqlQueryModel* resultats = new QSqlQueryModel(this);
        resultats->setQuery(requete);
        fragment->peuplerTableau(resultats);
    }
}

