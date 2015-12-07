#include "mappeurtechniciens.h"
#include "Modeles/technicien.h"

#include <QVariant>

MappeurTechniciens::MappeurTechniciens(QSqlDatabase *a_bd, QObject *parent) :
    QObject(parent) {
    bd = a_bd;
}

Technicien* MappeurTechniciens::getTechnicien(int a_id)
{
    Technicien* technicien = NULL;
    QString requete = "SELECT * FROM techniciens WHERE id="+QString::number(a_id);
    QSqlQuery* commande = new QSqlQuery(requete, *bd);
    if (commande->next()) {
        technicien = mapper(commande->record());
    }
    return technicien;
}

Technicien* MappeurTechniciens::mapper(QSqlRecord ligne) {
    return new Technicien(ligne.value("id").toInt(),
                     ligne.value("nom").toString(), this);
}

QList<Technicien*>* MappeurTechniciens::getTechniciens(void) {
    QList<Technicien*>* liste = new QList<Technicien*>;
    QString requete = "SELECT * FROM techniciens";
    QSqlQuery* commande = new QSqlQuery(requete, *bd);
    QSqlRecord ligne = commande->record();
    int colId = ligne.indexOf("id");
    int colNom = ligne.indexOf("nom");
    while (commande->next()) {
        ligne = commande->record();
        Technicien* technicien = new Technicien(ligne.value(colId).toInt(),
                                 ligne.value(colNom).toString(), this);
        liste->append(technicien);
    }
    return liste;
}


