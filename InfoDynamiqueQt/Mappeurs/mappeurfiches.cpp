#include "Mappeurs/mappeurfiches.h"

#include "Controleurs/application.h"
#include "Mappeurs/aidemappeurs.h"
#include "Mappeurs/mappeurpieces.h"
#include "Mappeurs/mappeurstatuts.h"
#include "Mappeurs/mappeurtaches.h"

#include <QSqlError>

Fiche *MappeurFiches::getFiche(const int &id)
{
    Fiche* fiche = NULL;
    QString commande("SELECT * FROM fiches WHERE id=:id");
    QSqlQuery requete(*Application::bd);
    requete.prepare(commande);
    requete.bindValue(":id", id);
    requete.exec();
    if (requete.next()) {
        fiche = mapper(requete.record());
    }
    return fiche;
}

QList<Fiche*>* MappeurFiches::fichesPourAppareil(const int &idAppareil)
{
    const QString commande("SELECT * FROM fiches WHERE idAppareil=:idAppareil");
    QSqlQuery requete(*Application::bd);
    requete.prepare(commande);
    requete.bindValue(":idAppareil", idAppareil);
    requete.exec();
    return mapper(requete);
}

int MappeurFiches::nombreFiches(const int &idAppareil)
{
    QString commande("SELECT count(*) as 'nombre' FROM fiches WHERE idAppareil=:idAppareil");
//    QString commande("SELECT 2 as nombre");
    QSqlQuery requete(*Application::bd);
    requete.prepare(commande);
    requete.bindValue(":idAppareil", idAppareil);
    requete.exec();
    int nombre = -1;
    if (requete.next()) {
        nombre = requete.record().value("nombre").toInt();
    }
    return nombre;
}

bool MappeurFiches::inserer(Fiche *fiche){
    const QString commande("INSERT INTO fiches\
                                (idAppareil, priorite, idTechnicien, idStatut, commentaire)\
                            VALUES\
                                (:idAppareil, :priorite, :idTechnicien, :idStatut, :commentaire)");
    const bool succes = ecrire(fiche, commande);
    fiche->setId(AideMappeurs::derniereInsertion());
    return succes;
}

bool MappeurFiches::mettreAJour(const Fiche *fiche)
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

    fiche->setCommentaire(ligne.value("commentaire").toString());
    fiche->setTaches(MappeurTaches::tachesPourFiche(fiche->id()));
//    fiche->setTechniciens(MappeurTechniciens::);
    return fiche;
}

QList<Fiche*>* MappeurFiches::mapper(QSqlQuery &requete)
{
    QList<Fiche*>* liste = new QList<Fiche*>;
    QSqlRecord ligne = requete.record();
    int colId = ligne.indexOf("id");
    int colAppareil = ligne.indexOf("idAppareil");
    int colPriorite = ligne.indexOf("priorite");
    int colStatut = ligne.indexOf("idStatut");
    int colCommentaire = ligne.indexOf("commentaire");
    while (requete.next()) {
        ligne = requete.record();
        Fiche* fiche = new Fiche();
        fiche->setId(ligne.value(colId).toInt());
        fiche->setIdAppareil(ligne.value(colAppareil).toInt());
        fiche->setPieces(MappeurPieces::piecesPourFiche(fiche->id()));
        fiche->setPriorite(ligne.value(colPriorite).toInt());
        fiche->setStatut(MappeurStatuts::getStatutFiche(ligne.value(colStatut).toInt()));
        fiche->setCommentaire(ligne.value(colCommentaire).toString());
        fiche->setTaches(MappeurTaches::tachesPourFiche(fiche->id()));
        liste->append(fiche);
    }
    return liste;
}

QSqlQuery *MappeurFiches::preparerRequete(const Fiche *fiche, const QString &commande)
{
    QSqlQuery* requete = new QSqlQuery(*Application::bd);
    requete->prepare(commande);
    requete->bindValue(":id", fiche->id());
//    requete->bindValue(":statut", fiche->statut());
    return requete;
}

int MappeurFiches::derniereInsertion()
{
    int id = -1;
    QSqlQuery* requete = new QSqlQuery("SELECT LAST_INSERT_ID() as id",*Application::bd);
    if (requete->next()) {
        id = requete->record().value("id").toInt();
    }
    return id;
}

bool MappeurFiches::ecrire(const Fiche *fiche, const QString &commande)
{
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    QSqlQuery* requete = preparerRequete(fiche, commande);
    const bool succes = requete->exec();
    if (succes) {
        bd.commit();
    } else {
        Application::messageErreur(tr("Erreur lors de l'écriture"),
                                   tr("Une erreur s'est produite lors de l'écriture:\n") + requete->lastError().text(),
                                   Application::vuePrincipale());
        bd.rollback();
    }
    delete requete;
    return succes;
}
