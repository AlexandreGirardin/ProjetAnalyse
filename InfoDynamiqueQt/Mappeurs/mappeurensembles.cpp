#include "Mappeurs/mappeurensembles.h"

#include "Controleurs/application.h"
#include "Mappeurs/mappeuractions.h"

#include <QDebug>
#include <QVariant>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

MappeurEnsembles::MappeurEnsembles(QObject* parent) : QObject(parent) {}

EnsembleActions* MappeurEnsembles::getEnsemble(const int &id)
{
    EnsembleActions* ensemble = NULL;
    QSqlQuery requete(*Application::bd);
    requete.prepare("SELECT * FROM ensembles WHERE id=:id");
    requete.bindValue(":id", id);
    requete.exec();
    if (requete.next()) {
        ensemble = mapper(requete.record());
    }
    return ensemble;
}

QList<EnsembleActions*>* MappeurEnsembles::getEnsembles()
{
    QSqlQuery requete("SELECT * FROM ensembles", *Application::bd);
    return mapper(requete);
}

EnsembleActions* MappeurEnsembles::mapper(const QSqlRecord &ligne)
{
    EnsembleActions* ensemble = new EnsembleActions();
    ensemble->setId(ligne.value("id").toInt());
    ensemble->setNom(ligne.value("nom").toString());
    ensemble->setDescription(ligne.value("description").toString());
    ensemble->setActions(MappeurActions::actionsDansEnsemble(ensemble->id()));
    return ensemble;
}

QList<EnsembleActions*>* MappeurEnsembles::mapper(QSqlQuery &requete)
{
    QList<EnsembleActions*>* liste = new QList<EnsembleActions*>();
    QSqlRecord ligne = requete.record();
    int colId = ligne.indexOf("id");
    int colNom = ligne.indexOf("nom");
    int colDesc = ligne.indexOf("description");
    while (requete.next()) {
        ligne = requete.record();
        EnsembleActions* ensemble = new EnsembleActions();
        ensemble->setId(ligne.value(colId).toInt());
        ensemble->setNom(ligne.value(colNom).toString());
        ensemble->setDescription(ligne.value(colDesc).toString());
        ensemble->setActions(MappeurActions::actionsDansEnsemble(ensemble->id()));
        liste->append(ensemble);
    }
    return liste;
}

bool MappeurEnsembles::inserer(EnsembleActions *ensemble)
{
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    const QString commandeEnsemble("INSERT INTO ensembles\
                                        (nom, description)\
                                    VALUES\
                                        (:nom, :description)\
                                    ");
    bool ecritureEnsemble = ecrire(ensemble, commandeEnsemble);
    ensemble->setId(derniereInsertion());
    const QString commandeActions("INSERT INTO ensemblesActions\
                                        (idEnsemble, idAction)\
                                    VALUES\
                                        (:idEnsemble, :idAction)"
                                    );
    bool ecritureActions = ecrireActions(ensemble, commandeActions);
    bool succes = ecritureEnsemble && ecritureActions;
    if (succes) {
        bd.commit();
    } else {
        bd.rollback();
    }
    return succes;
}

bool MappeurEnsembles::mettreAJour(const EnsembleActions* ensemble)
{
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    const QString commandeEnsemble("UPDATE ensembles\
                                    SET\
                                        nom=:nom,\
                                        description=:description\
                                    WHERE id=:idEnsemble");
    bool succes = ecrire(ensemble, commandeEnsemble);
    if (succes) {
        const QString commandeViderActions("DELETE FROM ensemblesActions\
                                           WHERE idEnsemble=:idEnsemble");
        succes = ecrire(ensemble, commandeViderActions);
        if (succes) {
            const QString commandeActions("INSERT INTO ensemblesActions\
                                                (idEnsemble, idAction)\
                                            VALUES\
                                                (:idEnsemble, :idAction)"
                                            );
            succes = ecrireActions(ensemble, commandeActions);
        }
    }
    if (succes) {
        bd.commit();
    } else {
        bd.rollback();
    }
    return succes;
}

bool MappeurEnsembles::supprimer(const EnsembleActions *ensemble)
{
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    const QString commandeViderActions("DELETE FROM ensemblesActions WHERE idEnsemble=:idEnsemble");
    bool succes = ecrire(ensemble, commandeViderActions);
    if (succes) {
        const QString commandeEnsemble("DELETE FROM ensembles WHERE id=:idEnsemble");
        succes = ecrire(ensemble, commandeEnsemble);
    }
    if (succes) {
        bd.commit();
    } else {
        bd.rollback();
    }
    return succes;
}

QSqlQuery* MappeurEnsembles::preparerRequete(const EnsembleActions* ensemble, const QString &commande)
{
    QSqlQuery* requete = new QSqlQuery(*Application::bd);
    requete->prepare(commande);
    requete->bindValue(":idEnsemble", ensemble->id());
    requete->bindValue(":nom", ensemble->nom());
    requete->bindValue(":description", ensemble->description());
    return requete;
}

int MappeurEnsembles::derniereInsertion()
{
    int id = -1;
    QSqlQuery* requete = new QSqlQuery("SELECT LAST_INSERT_ID() as id",*Application::bd);
    if (requete->next()) {
        id = requete->record().value("id").toInt();
    }
    return id;
}

bool MappeurEnsembles::ecrire(const EnsembleActions* ensemble, const QString &commande)
{
    QSqlQuery* requete = preparerRequete(ensemble, commande);
    requete->bindValue(":idEnsemble", ensemble->id());
    const bool succes = requete->exec();
    if (!succes) {
        qDebug() << requete->lastError();
    }
    delete requete;
    return succes;
}

bool MappeurEnsembles::ecrireActions(const EnsembleActions *ensemble, const QString &commande)
{
    QSqlQuery* requete = preparerRequete(ensemble, commande);
    requete->bindValue(":idEnsemble", ensemble->id());
    QList<Action*>* actions = ensemble->actions();
    bool succes = true;
    for (QList<Action*>::const_iterator i = actions->constBegin(); succes && i != actions->constEnd(); ++i) {
        requete->bindValue(":idAction", (*i)->id());
        succes = succes && requete->exec();
    }
    if (!succes) {
        qDebug() << requete->lastError();
    }
    delete requete;
    return succes;
}
