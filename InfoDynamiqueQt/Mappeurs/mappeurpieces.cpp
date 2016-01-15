#include "Mappeurs/mappeurpieces.h"

#include <QVariant>
#include <QtSql/QSqlQuery>

#include "Controleurs/application.h"

MappeurPieces::MappeurPieces(QObject* parent) :
    QObject(parent)
{
}

Piece* MappeurPieces::getPiece(int id)
{
    Piece* piece = NULL;
    QString requete = "SELECT * FROM pieces WHERE id="+QString::number(id);
    QSqlQuery* commande = new QSqlQuery(requete, *Application::bd);
    if (commande->next()) {
        piece = mapper(commande->record());
    }
    return piece;
}

Piece* MappeurPieces::mapper(QSqlRecord ligne)
{
    return new Piece(ligne.value("id").toInt(),
                     ligne.value("nom").toString(),
                     ligne.value("description").toString(),
                     ligne.value("prix").toInt(), this);
}

QList<Piece*>* MappeurPieces::getPieces(void)
{
    QList<Piece*>* liste = new QList<Piece*>();
    QString requete = "SELECT * FROM pieces";
    QSqlQuery* commande = new QSqlQuery(requete, *Application::bd);
    QSqlRecord ligne = commande->record();
    int colId = ligne.indexOf("id");
    int colNom = ligne.indexOf("nom");
    int colDesc = ligne.indexOf("description");
    int colPrix = ligne.indexOf("prix");
    while (commande->next()) {
        ligne = commande->record();
        Piece* piece = new Piece(ligne.value(colId).toInt(),
                                 ligne.value(colNom).toString(),
                                 ligne.value(colDesc).toString(),
                                 ligne.value(colPrix).toInt(), this);
        liste->append(piece);
    }
    return liste;
}
