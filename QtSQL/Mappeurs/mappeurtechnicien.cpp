#include "mappeurtechnicien.h"
#include <QSqlRecord>

MappeurTechnicien::MappeurTechnicien(GestionnaireConnexion *a_gc, QObject *parent) :
    QObject(parent)
{
    gc = a_gc;
}

Technicien *MappeurTechnicien::getTechnicien(int id)
{
    Technicien *technicien = NULL;
    QString requete = "SELECT * FROM techniciens WHERE id="+QString::number(id);
    QSqlQuery commande = gc->requete(requete);
    int colId = commande.record().indexOf("id");
    int colNom = commande.record().indexOf("nom");
    if (commande.next()) {
        technicien = new Technicien(commande.value(colId).toInt(), commande.value(colNom).toString(), this);
    }
    return technicien;
}

QList<Technicien*> MappeurTechnicien::getTechniciens(void) {
    QList<Technicien*> liste;
    QString requete = "SELECT * FROM techniciens";
    QSqlQuery commande = gc->requete(requete);
    int colId = commande.record().indexOf("id");
    int colNom = commande.record().indexOf("nom");
    while (commande.next()) {
        Technicien *technicien = new Technicien(commande.value(colId).toInt(), commande.value(colNom).toString(), this);
        liste.append(technicien);
    }
    return liste;
}


