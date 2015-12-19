#include "Mappeurs/mappeurfabricants.h"

#include <QVariant>
#include <QtSql/QSqlQuery>

MappeurFabricants::MappeurFabricants(QSqlDatabase* a_bd, QObject* parent) :
    QObject(parent) {
    bd = a_bd;
}

Fabricant* MappeurFabricants::getFabricant(int id) {
    Fabricant* fabricant = NULL;
    QString requete = "SELECT * FROM fabricants WHERE id="+QString::number(id);
    QSqlQuery* commande = new QSqlQuery(requete,* bd);
    if (commande->next()) {
        fabricant = mapper(commande->record());
    }
    return fabricant;
}

Fabricant* MappeurFabricants::mapper(QSqlRecord ligne) {
    return new Fabricant(ligne.value("id").toInt(),
                     ligne.value("nom").toString(), this);
}

QList<Fabricant*>* MappeurFabricants::getFabricants() {
    QList<Fabricant*>* liste = new QList<Fabricant*>();
    QString requete = "SELECT * FROM fabricants";
    QSqlQuery* commande = new QSqlQuery(requete,* bd);
    QSqlRecord ligne = commande->record();
    int colId = ligne.indexOf("id");
    int colNom = ligne.indexOf("nom");
    while (commande->next()) {
        ligne = commande->record();
        Fabricant* fabricant = new Fabricant(ligne.value(colId).toInt(),
                                             ligne.value(colNom).toString(), this);
        liste->append(fabricant);
    }
    return liste;
}
