#include "mappeurpieces.h"
#include "Modeles/piece.h"

#include <QVariant>

MappeurPieces::MappeurPieces(QSqlDatabase* a_bd, QObject* parent) :
    QObject(parent) {
    bd = a_bd;
}

Piece *MappeurPieces::getPiece(int id) {
    Piece* piece = NULL;
    QString requete = "SELECT * FROM pieces WHERE id="+QString::number(id);
    QSqlQuery* commande = new QSqlQuery(requete, *bd);
    if (commande->next()) {
        piece = mapper(commande->record());
    }
    return piece;
}

Piece *MappeurPieces::mapper(QSqlRecord ligne) {
    return new Piece(ligne.value("id").toInt(),
                     ligne.value("nom").toString(),
                     ligne.value("description").toString(),
                     ligne.value("prix").toInt(), this);
}

QList<Piece*>* MappeurPieces::getPieces(void) {
    QList<Piece*>* liste = new QList<Piece*>();
    QString requete = "SELECT * FROM pieces";
    QSqlQuery* commande = new QSqlQuery(requete, *bd);
    while (commande->next()) {
        Piece* piece = mapper(commande->record());
        liste->append(piece);
    }
    return liste;
}
