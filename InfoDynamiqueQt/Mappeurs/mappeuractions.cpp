#include "Mappeurs/mappeuractions.h"

#include "Controleurs/application.h"
#include "Mappeurs/aidemappeurs.h"
#include "Modeles/action.h"
#include "Modeles/ensembleactions.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

Action* MappeurActions::get(const int &id)
{
    Action* action = NULL;
    QSqlQuery requete(*Application::bd);
    requete.prepare("SELECT * FROM actions WHERE id=:id");
    requete.bindValue(":id", id);
    requete.exec();
    if (requete.next()) {
        action = mapper(requete.record());
    }
    return action;
}

QList<Action*>* MappeurActions::get()
{
    QSqlQuery requete("SELECT * FROM actions ORDER BY nom ASC", *Application::bd);
    return mapper(requete);
}

QList<Action*>* MappeurActions::get(const QList<int>* listeId)
{
    QList<Action*>* listeActions = new QList<Action*>;
    for (QList<int>::const_iterator i = listeId->constBegin(); i != listeId->constEnd(); ++i) {
        Action* action = get((*i));
        if (action != NULL) {
            listeActions->append(action);
        }
    }
    return listeActions;
}

QList<Action*>* MappeurActions::getSauf(const QList<int>* idExclus)
{
    QList<Action*>* listeActions = new QList<Action*>;
    QSqlQuery requete("SELECT * FROM actions ORDER BY nom ASC", *Application::bd);
    const int colId = requete.record().indexOf("id");
    while (requete.next()) {
        QSqlRecord ligne = requete.record();
        int id = requete.record().value(colId).toInt();
        if (!idExclus->contains(id)) {
            listeActions->append(mapper(ligne));
        }
    }
    return listeActions;
}

int MappeurActions::nombreTachesPourAction(const int &idAction)
{
    QSqlQuery requete(*Application::bd);
    requete.prepare("SELECT count(*) as 'nombre' FROM taches WHERE idAction=:idAction");
    requete.bindValue(":idAction", idAction);
    requete.exec();
    int nombre = -1;
    if (requete.next()) {
        nombre = requete.record().value("nombre").toInt();
    }
    return nombre;
}

Action* MappeurActions::mapper(const QSqlRecord &ligne)
{
    Action* action = new Action();
    action->setId(ligne.value("id").toInt());
    action->setNom(ligne.value("nom").toString());
    action->setDescription(ligne.value("description").toString());
    action->setEtat(ligne.value("etat").toInt());
    return action;
}

QList<Action*>* MappeurActions::mapper(QSqlQuery &requete)
{
    QList<Action*>* liste = new QList<Action*>();
    QSqlRecord ligne = requete.record();
    int colId = ligne.indexOf("id");
    int colNom = ligne.indexOf("nom");
    int colDesc = ligne.indexOf("description");
    int colEtat = ligne.indexOf("etat");
    while (requete.next()) {
        ligne = requete.record();
        Action* action = new Action();
        action->setId(ligne.value(colId).toInt());
        action->setNom(ligne.value(colNom).toString());
        action->setDescription(ligne.value(colDesc).toString());
        action->setEtat(ligne.value(colEtat).toInt());
        liste->append(action);
    }
    return liste;
}

QList<Action*>* MappeurActions::actionsDansEnsemble(const int &idEnsemble)
{
    QSqlQuery requete(*Application::bd);
    requete.prepare("SELECT * FROM actions a\
                    WHERE a.id IN\
                        (SELECT idAction FROM ensemblesActions ea\
                         WHERE ea.idEnsemble=:idEnsemble)\
                    ORDER BY a.nom ASC");
    requete.bindValue(":idEnsemble", idEnsemble);
    requete.exec();
    return mapper(requete);
}

QList<Action*>* MappeurActions::actionsHorsEnsemble(const int &idEnsemble)
{
    QSqlQuery requete(*Application::bd);
    requete.prepare("SELECT * FROM actions a\
                    WHERE a.id NOT IN\
                        (SELECT idAction FROM ensemblesActions ea\
                         WHERE ea.idEnsemble=:idEnsemble)\
                    ORDER BY a.nom ASC");
    requete.bindValue(":idEnsemble", idEnsemble);
    requete.exec();
    return mapper(requete);
}

bool MappeurActions::inserer(Action* action)
{
    const QString commande("INSERT INTO actions (nom, description, etat)\
                            VALUES (:nom, :description, :etat)");
    const bool succes = ecrire(action, commande);
    action->setId(AideMappeurs::derniereInsertion());
    return succes;
}

bool MappeurActions::mettreAJour(const Action* action)
{
    const QString commande("UPDATE actions\
                            SET\
                                nom=:nom,\
                                description=:description,\
                                etat=:etat\
                            WHERE id=:idAction");
    const bool succes = ecrire(action, commande);
    return succes;
}

bool MappeurActions::supprimer(Action *action)
{
    bool succes = false;
    QString erreur;
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    QSqlQuery* requeteEnsembles = preparerRequete(action, "DELETE FROM ensemblesActions WHERE idAction=:idAction");
    const bool ensemblesNettoyes = requeteEnsembles->exec();
    if (ensemblesNettoyes) {
        QSqlQuery* requeteActions = preparerRequete(action, "DELETE FROM actions WHERE id=:idAction");
        const bool actionEffacee = requeteActions->exec();
        if (actionEffacee) {
            succes = true;
        } else {
            erreur = requeteActions->lastError().text();
        }
    } else {
        erreur = requeteEnsembles->lastError().text();
    }
    if (succes) {
        bd.commit();
    } else {
        bd.rollback();
        Application::erreurSuppression(erreur);
    }
    return succes;
}

QSqlQuery* MappeurActions::preparerRequete(const Action* action, const QString &commande)
{
    QSqlQuery* requete = new QSqlQuery(*Application::bd);
    requete->prepare(commande);
    requete->bindValue(":idAction", action->id());
    requete->bindValue(":nom", action->nom());
    requete->bindValue(":description", action->description());
    requete->bindValue(":etat", action->etat());
    return requete;
}

bool MappeurActions::ecrire(const Action *action, const QString &commande)
{
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    QSqlQuery* requete = preparerRequete(action, commande);
    const bool succes = requete->exec();
    if (succes) {
        bd.commit();
    } else {
        Application::erreurEcriture(requete->lastError().text());
        bd.rollback();
    }
    delete requete;
    return succes;
}
