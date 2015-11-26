#include "fabriquefabricant.h"

FabriqueFabricant::FabriqueFabricant(GestionnaireConnexion *a_gc, QObject *parent) :
    QObject(parent)
{
    gc = a_gc;
}

Fabricant* FabriqueFabricant::getFabricant(int id)
{
    Fabricant *fabricant = NULL;
    QString requete = "SELECT * FROM fabricants WHERE id="+QString::number(id);
    QSqlQuery commande = gc->requete(requete);
    if (commande.next()) {
        fabricant = new Fabricant(commande.value(0).toInt(), commande.value(1).toString());
    }
    return fabricant;
}

QList<Fabricant *> FabriqueFabricant::getFabricants()
{
    QList<Fabricant*> liste;
    QString requete = "SELECT * FROM fabricants";
    QSqlQuery commande = gc->requete(requete);
    while (commande.next()) {
        Fabricant *fabricant = new Fabricant(commande.value(0).toInt(), commande.value(1).toString());
        liste.append(fabricant);
    }
    return liste;
}
