#include "mappeurpieces.h"

#include <QVariant>

#include "Modeles/piece.h"

MappeurPieces::MappeurPieces(QSqlDatabase* a_bd, QObject *parent) :
    QObject(parent)
{
    bd = *a_bd;
}

Piece *MappeurPieces::getPiece(int id)
{
    Piece *piece = NULL;
    QString requete = "SELECT * FROM pieces WHERE id="+QString::number(id);
    QSqlQuery *commande = new QSqlQuery(requete, bd);
//    QSqlQuery commande = gc.requete(requete);
    if (commande->next()) {
        piece = new Piece(commande->value(0).toInt(), commande->value(1).toString(), commande->value(2).toString(), commande->value(3).toInt(), this);
    }
    return piece;
}

QList<Piece*> MappeurPieces::getPieces(void) {
    QList<Piece*> liste;
    QString requete = "SELECT * FROM pieces";
    QSqlQuery *commande = new QSqlQuery(requete, bd);
    while (commande->next()) {
        Piece *piece = new Piece(commande->value(0).toInt(), commande->value(1).toString(), commande->value(2).toString(), commande->value(3).toInt(), this);
        liste.append(piece);
    }
    return liste;
}
