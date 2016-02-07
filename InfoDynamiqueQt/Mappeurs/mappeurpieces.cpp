#include "Mappeurs/mappeurpieces.h"

#include "Controleurs/application.h"

MappeurPieces::MappeurPieces(QObject* parent) : QObject(parent) {}

Piece* MappeurPieces::getPiece(const int &id)
{
    Piece* piece = NULL;
    QString commande("SELECT * FROM pieces WHERE id=:id");
    QSqlQuery requete(*Application::bd);
    requete.prepare(commande);
    requete.bindValue(":id", id);
    requete.exec();
    if (requete.next()) {
        piece = mapper(requete.record());
    }
    return piece;
}

QList<Piece*>* MappeurPieces::getPieces()
{
    QSqlQuery requete(QSqlQuery("SELECT * FROM pieces", *Application::bd));
    return mapper(requete);
}

Piece* MappeurPieces::mapper(const QSqlRecord &ligne)
{
    Piece* piece = new Piece();
    piece->setId(ligne.value("id").toInt());
    piece->setNom(ligne.value("nom").toString());
    piece->setDescription(ligne.value("description").toString());
    piece->setPrix(ligne.value("prix").toInt());
    return piece;
}

QList<Piece*>* MappeurPieces::mapper(QSqlQuery &requete)
{
    QList<Piece*>* liste = new QList<Piece*>;
    QSqlRecord ligne = requete.record();
    int colId = ligne.indexOf("id");
    int colNom = ligne.indexOf("nom");
    int colDesc = ligne.indexOf("description");
    int colPrix = ligne.indexOf("prix");
    while (requete.next()) {
        ligne = requete.record();
        Piece* piece = new Piece();
        piece->setId(ligne.value(colId).toInt());
        piece->setNom(ligne.value(colNom).toString());
        piece->setDescription(ligne.value(colDesc).toString());
        piece->setPrix(ligne.value(colPrix).toInt());
        liste->append(piece);
    }
    return liste;
}
