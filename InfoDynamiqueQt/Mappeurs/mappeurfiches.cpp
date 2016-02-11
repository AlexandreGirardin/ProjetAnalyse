#include "Mappeurs/mappeurfiches.h"
#include "Mappeurs/mappeurpieces.h"
#include "Mappeurs/mappeurstatuts.h"
#include "Mappeurs/mappeurtaches.h"
#include "Mappeurs/mappeurtechniciens.h"

#include "Controleurs/application.h"

#include <QDebug>
#include <QSqlError>

MappeurFiches::MappeurFiches(QObject* parent) : QObject(parent)
{
}

Fiche *MappeurFiches::getFiche(const int &id)
{
    Fiche* fiche = NULL;
    QString commande("SELECT * FROM fiches WHERE id=:id");
    QSqlQuery requete(QSqlQuery(*Application::bd));
    requete.prepare(commande);
    requete.bindValue(":id", id);
    requete.exec();
    if (requete.next()) {
        fiche = mapper(requete.record());
    }
    return fiche;
}

bool MappeurFiches::inserer(const Fiche *fiche) const
{
    const QString commande("INSERT INTO fiches\
                                (idAppareil, priorite, idTechnicien, idStatut, commentaire)\
                            VALUES\
                                (:idAppareil, :priorite, :idTechnicien, :idStatut, :commentaire)");
    const bool succes = ecrire(fiche, commande);
    return succes;
}

bool MappeurFiches::mettreAJour(const Fiche *fiche) const
{
    const QString commande("UPDATE fiches\
                            SET\
                                idAppareil=:idAppareil,\
                                priorite=:priorite,\
                                idTechnicien=:idTechnicien,\
                                idStatut=:idStatut,\
                                commentaire=:commentaire\
                            WHERE id=:idFiche");
    const bool succes = ecrire(fiche, commande);
    return succes;
}

Fiche *MappeurFiches::mapper(const QSqlRecord &ligne)
{
    Fiche* fiche = new Fiche();
    fiche->setId(ligne.value("id").toInt());
    fiche->setIdAppareil(ligne.value("idAppareil").toInt());
    fiche->setPieces(MappeurPieces::piecesPourFiche(fiche->id()));
    fiche->setPriorite(ligne.value("priorite").toInt());
    fiche->setStatut(MappeurStatuts::getStatutFiche(ligne.value("idStatut").toInt()));
    fiche->setTaches(MappeurTaches::tachesPourFiche(fiche->id()));
//    fiche->setTechniciens(ligne.value("idTechnicien").toInt());
    return fiche;
}

QSqlQuery *MappeurFiches::preparerRequete(const Fiche *fiche, const QString &commande) const
{
    QSqlQuery* requete = new QSqlQuery(*Application::bd);
    requete->prepare(commande);
    requete->bindValue(":id", fiche->id());
//    requete->bindValue(":statut", fiche->statut());
    return requete;
}

int MappeurFiches::derniereInsertion() const
{
    int id = -1;
    QSqlQuery* requete = new QSqlQuery("SELECT LAST_INSERT_ID() as id",*Application::bd);
    if (requete->next()) {
        id = requete->record().value("id").toInt();
    }
    return id;
}

bool MappeurFiches::ecrire(const Fiche *fiche, const QString &commande) const
{
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    QSqlQuery* requete = preparerRequete(fiche, commande);
    const bool succes = requete->exec();
    if (succes) {
        bd.commit();
    } else {
        qDebug() << requete->lastError();
        bd.rollback();
    }
    delete requete;
    return succes;
}