#include "Mappeurs/mappeurpieces.h"

#include "Controleurs/application.h"
#include "Mappeurs/aidemappeurs.h"
#include "Modeles/fiche.h"
#include "Modeles/piece.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

Piece* MappeurPieces::get(const int &id)
{
    Piece* piece = NULL;
    QSqlQuery requete("SELECT * FROM pieces WHERE id=:id", *Application::bd);
    requete.bindValue(":id", id);
    requete.exec();
    if (requete.next()) {
        piece = mapper(requete.record());
    }
    return piece;
}

QList<Piece*>* MappeurPieces::get()
{
    QSqlQuery requete(QSqlQuery("SELECT * FROM pieces", *Application::bd));
    return mapper(requete);
}

QList<Piece*>* MappeurPieces::piecesPourFiche(const int &idFiche)
{
    QSqlQuery requete(*Application::bd);
    requete.prepare("SELECT * FROM pieces p\
                    WHERE p.id IN\
                        (SELECT idPiece FROM fichesPieces fp\
                         WHERE fp.idFiche=:idFiche)\
                    ORDER BY p.nom ASC");
    requete.bindValue(":idFiche", idFiche);
    requete.exec();
    return mapper(requete);
}

bool MappeurPieces::inserer(Piece* piece, const int &idFiche)
{
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    const QString commandeFiche("INSERT INTO pieces (id, nom, description, prix) VALUES (:id, :nom, :description, :prix)");
    bool succes = ecrire(piece, commandeFiche);
    piece->setId(AideMappeurs::derniereInsertion());
    if (succes) {
        QSqlQuery requete(*Application::bd);
        requete.prepare("INSERT INTO fichespieces (idFiche, idPiece) VALUES (:idFiche, :idPiece)");
        requete.bindValue(":idFiche", idFiche);
        requete.bindValue(":idPiece", piece->id());
        succes = requete.exec();
        if (!succes) {
            Application::erreurEcriture(requete.lastError().text() + "\n" + requete.lastQuery());
        }
    }
    if (succes) {
        bd.commit();
    } else {
        bd.rollback();
    }
    return succes;
}

bool MappeurPieces::inserer(const QList<Piece*>* pieces, const int &idFiche)
{
    bool succes = true;
    for (QList<Piece*>::const_iterator i = pieces->constBegin(); i != pieces->constEnd() && succes; ++i) {
        succes = inserer(*i, idFiche);
    }
    return succes;
}

bool MappeurPieces::mettreAJour(const Piece* piece)
{
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    const QString commande("UPDATE pieces\
                           SET\
                               nom=:nom,\
                               description=:description,\
                               prix=:prix\
                           WHERE id=:id");
    bool succes = ecrire(piece, commande);
    if (succes) {
        bd.commit();
    } else {
        bd.rollback();
    }
    return succes;
}

bool MappeurPieces::supprimer(const Piece* piece)
{
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    const QString commandeFiche("DELETE FROM fichesPieces WHERE idPiece=:id");
    bool succes = ecrire(piece, commandeFiche);
    if (succes) {
        const QString commandePiece("DELETE FROM pieces WHERE id=:id");
        succes = ecrire (piece, commandePiece);
    }
    if (succes) {
        bd.commit();
    } else {
        bd.rollback();
    }
    return succes;
}

bool MappeurPieces::supprimer(const QList<Piece*>* pieces)
{
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    const QString commandeFiche("DELETE FROM fichesPieces WHERE idPiece=:id");
    const QString commandePiece("DELETE FROM pieces WHERE id=:id");
    bool succes = true;
    for (QList<Piece*>::const_iterator i = pieces->constBegin(); i != pieces->constEnd() && succes; ++i) {
        succes = ecrire(*i, commandeFiche);
        if (succes) {
            succes = ecrire (*i, commandePiece);
        }
    }
    if (succes) {
        bd.commit();
    } else {
        bd.rollback();
    }
    return succes;
}

bool MappeurPieces::syncPieces(const Fiche* fiche) {
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    bool succes = false;
    if (supprimer(piecesPourFiche(fiche->id())) && inserer(fiche->pieces(), fiche->id())) {
        succes = true;
    }
    if (succes) {
        bd.commit();
    } else {
        bd.rollback();
    }
    return succes;
}

Piece* MappeurPieces::mapper(const QSqlRecord &ligne)
{
    Piece* piece = new Piece();
    piece->setId(ligne.value("id").toInt());
    piece->setNom(ligne.value("nom").toString());
    piece->setDescription(ligne.value("description").toString());
    piece->setPrixInt(ligne.value("prix").toInt());
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
        piece->setPrixInt(ligne.value(colPrix).toInt());
        liste->append(piece);
    }
    return liste;
}

QSqlQuery* MappeurPieces::preparerRequete(const Piece* piece, const QString &commande)
{
    QSqlQuery* requete = new QSqlQuery(*Application::bd);
    requete->prepare(commande);
    requete->bindValue(":id", piece->id());
    requete->bindValue(":nom", piece->nom());
    requete->bindValue(":prix", piece->prixInt());
    requete->bindValue(":description", piece->description());
    return requete;
}

bool MappeurPieces::ecrire(const Piece* piece, const QString &commande)
{
    QSqlQuery* requete = preparerRequete(piece, commande);
    const bool succes = requete->exec();
    if (!succes) {
        Application::erreurEcriture(requete->lastError().text() + "\n" + requete->lastQuery());
    }
    delete requete;
    return succes;
}
