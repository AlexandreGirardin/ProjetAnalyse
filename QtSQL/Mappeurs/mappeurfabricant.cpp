#include "mappeurfabricant.h"
#include <QSqlRecord>


MappeurFabricant::MappeurFabricant(GestionnaireConnexion *a_gc, QObject *parent) :
    QObject(parent)
{
    gc = a_gc;
}

Fabricant* MappeurFabricant::getFabricant(int a_id)
{
    Fabricant *fabricant = NULL;
    QString requete = "SELECT * FROM fabricants WHERE id="+QString::number(a_id);
    QSqlQuery commande = gc->requete(requete);
    int colId = commande.record().indexOf("id");
    int colNom = commande.record().indexOf("nom");
    if (commande.next()) {
        fabricant = new Fabricant(commande.value(colId).toInt(), commande.value(colNom).toString(), this);
    }
    return fabricant;
}

QList<Fabricant *> MappeurFabricant::getFabricants()
{
    QList<Fabricant*> liste;
    QString requete = "SELECT * FROM fabricants";
    QSqlQuery commande = gc->requete(requete);
    int colId = commande.record().indexOf("id");
    int colNom = commande.record().indexOf("nom");
    while (commande.next()) {
        Fabricant *fabricant = new Fabricant(commande.value(colId).toInt(), commande.value(colNom).toString(), this);
        liste.append(fabricant);
    }
    return liste;
}
