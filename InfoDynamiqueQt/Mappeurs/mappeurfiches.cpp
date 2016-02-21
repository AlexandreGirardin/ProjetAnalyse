#include "Mappeurs/mappeurfiches.h"

#include "Controleurs/application.h"
#include "Mappeurs/aidemappeurs.h"
#include "Mappeurs/mappeurpieces.h"
#include "Mappeurs/mappeurstatuts.h"
#include "Mappeurs/mappeurtaches.h"

#include <QDebug>
#include <QSqlError>

Fiche *MappeurFiches::get(const int &id)
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

bool MappeurFiches::inserer(Fiche* fiche)
{
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    const QString commande("INSERT INTO fiches\
                                (idAppareil, priorite, idTechnicien,\
                                 idStatut, commentaire, description)\
                            VALUES\
                                (:idAppareil, :priorite, :idTechnicien,\
                                 :idStatut, :commentaire, :description)");
    bool succes = ecrire(fiche, commande);
    if (succes) {
        succes = MappeurTaches::inserer(fiche->taches());
    }
    if (succes) {
        bd.commit();
        fiche->setId(AideMappeurs::derniereInsertion());
    } else {
        bd.rollback();
    }
    return succes;
}

bool MappeurFiches::mettreAJour(const Fiche* fiche)
{
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    const QString commandeFiche("UPDATE fiches\
                                 SET\
                                    idAppareil=:idAppareil,\
                                    priorite=:priorite,\
                                    idTechnicien=:idTechnicien,\
                                    idStatut=:idStatut,\
                                    commentaire=:commentaire,\
                                    description=:description\
                                WHERE id=:id");
    bool succes = ecrire(fiche, commandeFiche);
    if (succes) {
        succes = MappeurTaches::syncTaches(fiche);
    }
    if (succes) {
        bd.commit();
        qDebug() << "succès";
    } else {
        bd.rollback();
        qDebug() << "échec";
    }
    Fiche* derp = get(fiche->id());
    qDebug() << fiche->description() << " " << fiche->commentaire();
    qDebug() << derp->description() << " " << derp->commentaire();
    delete derp;
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
    fiche->setDescription(ligne.value("description").toString());
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
    int colDescription = ligne.indexOf("description");
    while (requete.next()) {
        ligne = requete.record();
        Fiche* fiche = new Fiche();
        fiche->setId(ligne.value(colId).toInt());
        fiche->setIdAppareil(ligne.value(colAppareil).toInt());
        fiche->setPieces(MappeurPieces::piecesPourFiche(fiche->id()));
        fiche->setPriorite(ligne.value(colPriorite).toInt());
        fiche->setStatut(MappeurStatuts::getStatutFiche(ligne.value(colStatut).toInt()));
        fiche->setCommentaire(ligne.value(colCommentaire).toString());
        fiche->setDescription(ligne.value(colDescription).toString());
        fiche->setTaches(MappeurTaches::tachesPourFiche(fiche->id()));
        liste->append(fiche);
    }
    return liste;
}

QSqlQuery *MappeurFiches::preparerRequete(const Fiche* fiche, const QString &commande)
{
    QSqlQuery* requete = new QSqlQuery(*Application::bd);
    requete->prepare(commande);
    requete->bindValue(":id", fiche->id());
    requete->bindValue(":idAppareil", fiche->idAppareil());
    requete->bindValue(":priorite", fiche->priorite());
    requete->bindValue(":idTechnicien", 1); // TODO
    requete->bindValue(":idStatut", fiche->statut()->id());
    requete->bindValue(":commentaire", fiche->commentaire());
    requete->bindValue(":description", fiche->description());
    return requete;
}

bool MappeurFiches::ecrireTransaction(const Fiche* fiche, const QString &commande)
{
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    const bool succes = ecrire(fiche, commande);
    if (succes) {
        bd.commit();
    } else {
        bd.rollback();
    }
    return succes;
}

bool MappeurFiches::ecrire(const Fiche* fiche, const QString &commande)
{
    QSqlQuery* requete = preparerRequete(fiche, commande);
    const bool succes = requete->exec();
    if (!succes) {
        Application::erreurEcriture(requete->lastQuery()+requete->lastError().text());
    }
    delete requete;
    return succes;
}
