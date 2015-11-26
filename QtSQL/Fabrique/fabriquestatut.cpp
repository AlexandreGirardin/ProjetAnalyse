#include "fabriquestatut.h"

FabriqueStatut::FabriqueStatut(GestionnaireConnexion *a_gc,QObject *parent) : QObject(parent)
{
    gc = a_gc;
}

Statut *FabriqueStatut::getStatut(int id)
{
    Statut *statut;
    QString requete = "SELECT * FROM statutsFiche WHERE id="+QString::number(id);
    QSqlQuery commande = gc->requete(requete);
    if (commande.next()) {
        statut = new Statut(commande.value(0).toInt(), commande.value(1).toString());
    }
    return statut;
}
