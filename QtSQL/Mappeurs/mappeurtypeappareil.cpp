#include "mappeurtypeappareil.h"

MappeurTypeAppareil::MappeurTypeAppareil(GestionnaireConnexion *a_gc, QObject *parent) :
    QObject(parent)
{
    gc = a_gc;
}

TypeAppareil *MappeurTypeAppareil::getTypeAppareil(int id)
{
    TypeAppareil *typeAppareil = NULL;
    QString requete = "SELECT * FROM types WHERE id="+QString::number(id);
    QSqlQuery commande = gc->requete(requete);
    if (commande.next()) {
        typeAppareil = new TypeAppareil(commande.value(0).toInt(), commande.value(1).toString(), this);
    }
    return typeAppareil;
}

QList<TypeAppareil*> MappeurTypeAppareil::getTypesAppareil(void) {
    QList<TypeAppareil*> liste;
    QString requete = "SELECT * FROM types";
    QSqlQuery commande = gc->requete(requete);
    while (commande.next()) {
        TypeAppareil *typeAppareil = new TypeAppareil(commande.value(0).toInt(), commande.value(1).toString(), this);
        liste.append(typeAppareil);
    }
    return liste;
}
