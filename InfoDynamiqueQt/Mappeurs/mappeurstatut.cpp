#include "mappeurstatut.h"

MappeurStatut::MappeurStatut(GestionnaireConnexion *a_gc,QObject *parent) : QObject(parent)
{
    gc = a_gc;
}

Statut *MappeurStatut::getStatutFiche(int id)
{
    Statut *statut = NULL;
    QString requete = "SELECT * FROM statutsFiche WHERE id="+QString::number(id);
    QSqlQuery commande = gc->requete(requete);
    if (commande.next()) {
        statut = new Statut(commande.value(0).toInt(), commande.value(1).toString());
    }
    return statut;
}

QList<Statut*> MappeurStatut::getStatutsFiche(void) {
    QList<Statut*> liste;
    QString requete = "SELECT * FROM statutsFiche";
    QSqlQuery commande = gc->requete(requete);
    while (commande.next()) {
        Statut *statut = new Statut(commande.value(0).toInt(), commande.value(1).toString(), this);
        liste.append(statut);
    }
    return liste;
}

Statut *MappeurStatut::getStatutAction(int id)
{
    Statut *statut = NULL;
    QString requete = "SELECT * FROM statutsAction WHERE id="+QString::number(id);
    QSqlQuery commande = gc->requete(requete);
    if (commande.next()) {
        statut = new Statut(commande.value(0).toInt(), commande.value(1).toString());
    }
    return statut;
}

QList<Statut*> MappeurStatut::getStatutsAction(void) {
    QList<Statut*> liste;
    QString requete = "SELECT * FROM statutsAction";
    QSqlQuery commande = gc->requete(requete);
    while (commande.next()) {
        Statut *statut = new Statut(commande.value(0).toInt(), commande.value(1).toString(), this);
        liste.append(statut);
    }
    return liste;
}
