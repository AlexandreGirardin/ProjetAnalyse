#include "mappeurtaches.h"

#include "Controleurs/application.h"
#include "Mappeurs/aidemappeurs.h"
#include "Mappeurs/mappeuractions.h"
#include "Mappeurs/mappeurstatuts.h"
#include "Modeles/action.h"
#include "Modeles/fiche.h"
#include "Modeles/statut.h"
#include "Modeles/tache.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

Tache *MappeurTaches::get(const int &id)
{
    Tache* tache = NULL;
    QSqlQuery requete(*Application::bd);
    requete.prepare("SELECT * FROM taches WHERE id=:idTache");
    requete.bindValue(":idTache", id);
    requete.exec();
    if (requete.next()) {
        tache = mapper(requete.record());
    }
    return tache;
}

QList<Tache*>* MappeurTaches::get()
{
    QSqlQuery requete("SELECT * FROM taches ORDER BY idFiche ASC", *Application::bd);
    return mapper(requete);
}

QList<Tache*>* MappeurTaches::get(const QList<int>* listeId)
{
    QList<Tache*>* taches = new QList<Tache*>;
    for (QList<int>::const_iterator i = listeId->constBegin(); i != listeId->constEnd(); ++i) {
        Tache* tache = get(*i);
        if (tache != NULL) {
            taches->append(tache);
        }
    }
    return taches;
}

QList<Tache*>* MappeurTaches::pourFiche(const int &idFiche)
{
    QString commande("SELECT * FROM taches WHERE idFiche=:idFiche");
    QSqlQuery requete(*Application::bd);
    requete.prepare(commande);
    requete.bindValue(":idFiche", idFiche);
    requete.exec();
    return mapper(requete);
}

int MappeurTaches::pourAction(const int &idAction)
{
    int nombre = -1;
    QString commande("SELECT count(*) as 'nb' FROM taches WHERE idAction=:idAction");
    QSqlQuery requete(*Application::bd);
    requete.prepare(commande);
    requete.bindValue(":idAction", idAction);
    requete.exec();
    if (requete.next()) {
        nombre = requete.record().value("nb").toInt();
    }
    return nombre;
}

int MappeurTaches::prioriteMinimale()
{
    return 1; // TODO Déplacer vers la base de données
}

int MappeurTaches::prioriteMaximale()
{
    return 5; // TODO Déplacer vers la base de données
}

bool MappeurTaches::syncTaches(const Fiche* fiche) {
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    bool succes = false;
    if (supprimer(pourFiche(fiche->id())) && inserer(fiche->taches())) {
        succes = true;
    }
    if (succes) {
        bd.commit();
    } else {
        bd.rollback();
    }
    return succes;
}

bool MappeurTaches::inserer(Tache* tache)
{
    const QString commande("INSERT INTO taches\
                               (idFiche, idAction, idStatut, commentaire)\
                            VALUES\
                               (:idFiche, :idAction, :idStatut, :commentaire)");
    const bool succes = ecrire(tache, commande);
    return succes;
}

bool MappeurTaches::inserer(const QList<Tache*>* taches)
{
    bool succes = true;
    for (QList<Tache*>::const_iterator i = taches->constBegin(); i != taches->constEnd() && succes; ++i) {
        succes = inserer(*i);
    }
    return succes;
}

bool MappeurTaches::mettreAJour(const Tache* tache)
{
    const QString commande("UPDATE taches\
                            SET\
                                idStatut=:idStatut,\
                                commentaire=:commentaire,\
                            WHERE\
                                idFiche=:idFiche AND idAction=:idAction");
    const bool succes = ecrire(tache, commande);
    return succes;
}

Tache* MappeurTaches::mapper(const QSqlRecord &ligne)
{
    Tache* tache = new Tache();
    tache->setIdFiche(ligne.value("idFiche").toInt());
    tache->setAction(MappeurActions::get(ligne.value("idAction").toInt()));
    tache->setStatut(MappeurStatuts::getStatutTache(ligne.value("idStatut").toInt()));
    tache->setCommentaire(ligne.value("commentaire").toString());
    return tache;
}

QList<Tache*>* MappeurTaches::mapper(QSqlQuery &requete)
{
    QList<Tache*>* liste = new QList<Tache*>;
    QSqlRecord ligne = requete.record();
    int colIdFiche = ligne.indexOf("idFiche");
    int colIdAction = ligne.indexOf("idAction");
    int colIdStatut = ligne.indexOf("idStatut");
    int colCommentaire = ligne.indexOf("commentaire");
    while (requete.next()) {
        ligne = requete.record();
        Tache* tache = new Tache();
        tache->setIdFiche(ligne.value(colIdFiche).toInt());
        tache->setAction(MappeurActions::get(ligne.value(colIdAction).toInt()));
        tache->setStatut(MappeurStatuts::getStatutTache(ligne.value(colIdStatut).toInt()));
        tache->setCommentaire(ligne.value(colCommentaire).toString());
        liste->append(tache);
    }
    return liste;
}

bool MappeurTaches::supprimer(const Tache *tache)
{
    const QString commande("DELETE FROM taches\
                            WHERE idFiche=:idFiche AND idAction=:idAction");
    const bool succes = ecrire(tache, commande);
    return succes;
}

bool MappeurTaches::supprimer(const QList<Tache*>* taches)
{
    bool succes = true;
    for (QList<Tache*>::const_iterator i = taches->constBegin(); i != taches->constEnd() && succes; ++i) {
        succes = supprimer(*i);
    }
    return succes;
}

QSqlQuery* MappeurTaches::preparerRequete(const Tache* tache, const QString &commande)
{
    QSqlQuery* requete = new QSqlQuery(*Application::bd);
    requete->prepare(commande);
    requete->bindValue(":idFiche", tache->idFiche());
    requete->bindValue(":idAction", tache->action()->id());
    requete->bindValue(":idStatut", tache->statut()->id());
    requete->bindValue(":commentaire", tache->commentaire());
    return requete;
}

bool MappeurTaches::ecrire(const Tache* tache, const QString &commande)
{
    QSqlQuery* requete = preparerRequete(tache, commande);
    const bool succes = requete->exec();
    if (!succes) {
        Application::erreurEcriture(requete->lastError().text() + "\n" + requete->lastQuery());
    }
    delete requete;
    return succes;
}
