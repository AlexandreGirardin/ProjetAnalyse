#include "mappeurtypeappareil.h"
#include <QSqlRecord>


MappeurTypeAppareil::MappeurTypeAppareil(GestionnaireConnexion *a_gc, QObject *parent) :
    QObject(parent)
{
    gc = a_gc;
}

TypeAppareil *MappeurTypeAppareil::getTypeAppareil(int a_id)
{
    TypeAppareil *typeAppareil = NULL;
    QString requete = "SELECT * FROM types WHERE id="+QString::number(a_id);
    QSqlQuery commande = gc->requete(requete);
    int colId = commande.record().indexOf("id");
    int colNom = commande.record().indexOf("nom");
    if (commande.next()) {
        typeAppareil = new TypeAppareil(commande.value(colId).toInt(), commande.value(colNom).toString(), this);
    }
    return typeAppareil;
}

QList<TypeAppareil*> MappeurTypeAppareil::getTypesAppareil(void) {
    QList<TypeAppareil*> liste;
    QString requete = "SELECT * FROM types";
    QSqlQuery commande = gc->requete(requete);
    int colId = commande.record().indexOf("id");
    int colNom = commande.record().indexOf("nom");
    while (commande.next()) {
        TypeAppareil *typeAppareil = new TypeAppareil(commande.value(colId).toInt(), commande.value(colNom).toString(), this);
        liste.append(typeAppareil);
    }
    return liste;
}
