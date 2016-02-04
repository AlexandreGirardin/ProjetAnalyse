#include "Mappeurs/mappeuractions.h"

#include "Controleurs/application.h"

#include <QDebug>
#include <QVariant>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

MappeurActions::MappeurActions(QObject* parent) : QObject(parent) {}

Action* MappeurActions::getAction(const int &id)
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

QList<Action*>* MappeurActions::getActions()
{
    QSqlQuery requete("SELECT * FROM actions ORDER BY nom ASC", *Application::bd);
    return mapper(requete);
}

Action* MappeurActions::mapper(const QSqlRecord &ligne)
{
    Action* action = new Action(this);
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
        Action* action = new Action(this);
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

bool MappeurActions::mettreAJour(const Action* action) const
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

QSqlQuery* MappeurActions::preparerRequete(const Action* action, const QString &commande) const
{
    QSqlQuery* requete = new QSqlQuery(*Application::bd);
    requete->prepare(commande);
    requete->bindValue(":idAction", action->id());
    requete->bindValue(":nom", action->nom());
    requete->bindValue(":description", action->description());
    requete->bindValue(":etat", action->etat());
    return requete;
}

bool MappeurActions::ecrire(const Action *action, const QString &commande) const
{
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    QSqlQuery* requete = preparerRequete(action, commande);
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
