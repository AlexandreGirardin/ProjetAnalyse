#include "mappeurpiece.h"
#include <QSqlRecord>

MappeurPiece::MappeurPiece(GestionnaireConnexion *a_gc, QObject *parent) :
    QObject(parent)
{
    gc = a_gc;
}

Piece *MappeurPiece::getPiece(int id)
{
    Piece *piece = NULL;
    QString requete = "SELECT * FROM pieces WHERE id="+QString::number(id);
    QSqlQuery commande = gc->requete(requete);
    int colId = commande.record().indexOf("id");
    int colNom = commande.record().indexOf("nom");
    int colDescription = commande.record().indexOf("description");
    int colPrix = commande.record().indexOf("prix");
    if (commande.next()) {
        piece = new Piece(commande.value(colId).toInt(), commande.value(colNom).toString(), commande.value(colDescription).toString(), commande.value(colPrix).toInt(), this);
    }
    return piece;
}

QList<Piece*> MappeurPiece::getPieces(void) {
    QList<Piece*> liste;
    QString requete = "SELECT * FROM pieces";
    QSqlQuery commande = gc->requete(requete);
    int colId = commande.record().indexOf("id");
    int colNom = commande.record().indexOf("nom");
    int colDescription = commande.record().indexOf("description");
    int colPrix = commande.record().indexOf("prix");
    while (commande.next()) {
        Piece *piece = new Piece(commande.value(colId).toInt(), commande.value(colNom).toString(), commande.value(colDescription).toString(), commande.value(colPrix).toInt(), this);
        liste.append(piece);
    }
    return liste;
}
