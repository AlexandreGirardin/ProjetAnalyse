#include "Mappeurs/mappeuractions.h"

#include "Controleurs/application.h"

#include <QDebug>
#include <QVariant>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

MappeurActions::MappeurActions(QObject* parent) :
    QObject(parent)
{
}

Action* MappeurActions::getAction(int id)
{
    Action* action = NULL;
    QSqlQuery requete = QSqlQuery(*Application::bd);
    requete.prepare("SELECT * FROM actions WHERE id=:id");
    requete.bindValue(":id", id);
    requete.exec();
    if (requete.next()) {
        action = mapper(requete.record());
    }
    return action;
}

Action* MappeurActions::mapper(QSqlRecord ligne)
{
    Action* action = new Action(this);
    action->setId(ligne.value("id").toInt());
    action->setNom(ligne.value("nom").toString());
    action->setDescription(ligne.value("description").toString());
    action->setEtat(ligne.value("etat").toInt());
    return action;
}

QList<Action*>* MappeurActions::getActions()
{
    QList<Action*>* liste = new QList<Action*>();
    QSqlQuery* commande = new QSqlQuery("SELECT * FROM actions",*Application::bd);
    QSqlRecord ligne = commande->record();
    int colId = ligne.indexOf("id");
    int colNom = ligne.indexOf("nom");
    int colDesc = ligne.indexOf("description");
    int colEtat = ligne.indexOf("etat");
    while (commande->next()) {
        ligne = commande->record();
        Action* action = new Action(this);
        action->setId(ligne.value(colId).toInt());
        action->setNom(ligne.value(colNom).toString());
        action->setDescription(ligne.value(colDesc).toString());
        action->setEtat(ligne.value(colEtat).toInt());
        liste->append(action);
    }
    return liste;
}

QSqlQuery* MappeurActions::preparerRequete(const Action* action, const QString* commande)
{
    QSqlQuery* requete = new QSqlQuery(*Application::bd);
    requete->prepare(*commande);
    requete->bindValue(":idAction", action->getId());
    requete->bindValue(":nom", action->getNom());
    requete->bindValue(":description", action->getDescription());
    requete->bindValue(":etat", action->getEtat());
    return requete;
}

bool MappeurActions::mettreAJour(const Action* action)
{
    QSqlDatabase* bd = Application::bd;
    bd->transaction();
    const QString* commande = new QString(
                "UPDATE actions\
                SET\
                    nom=:nom,\
                    description=:description,\
                    etat=:etat\
                WHERE id=:idAction");
    QSqlQuery* requete = preparerRequete(action, commande);
    bool succes = requete->exec();
    if (succes) {
        bd->commit();
    } else {
        qDebug() << requete->lastError();
        bd->rollback();
    }
    return succes;
}
