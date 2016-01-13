#include "Mappeurs/mappeuractions.h"

#include <QVariant>
#include <QtSql/QSqlQuery>

MappeurActions::MappeurActions(QSqlDatabase* a_bd, QObject* parent) :
    QObject(parent) {
    bd = a_bd;
}

Action* MappeurActions::getAction(int id) {
    Action* action = NULL;
    QSqlQuery requete = QSqlQuery(*bd);
    requete.prepare("SELECT * FROM actions WHERE id=:id");
    requete.bindValue(":id", id);
    requete.exec();
    if (requete.next()) {
        action = mapper(requete.record());
    }
    return action;
}

Action* MappeurActions::mapper(QSqlRecord ligne) {
    Action* action = new Action(this);
    action->setId(ligne.value("id").toInt());
    action->setNom(ligne.value("nom").toString());
    action->setDescription(ligne.value("description").toString());
    return action;
}

QList<Action*>* MappeurActions::getActions() {
    QList<Action*>* liste = new QList<Action*>();
    QSqlQuery* commande = new QSqlQuery("SELECT * FROM actions",*bd);
    QSqlRecord ligne = commande->record();
    int colId = ligne.indexOf("id");
    int colNom = ligne.indexOf("nom");
    int colDesc = ligne.indexOf("description");
    int colEtat = ligne.indexOf("active");
    while (commande->next()) {
        ligne = commande->record();
        Action* action = new Action(this);
        action->setId(ligne.value(colId).toInt());
        action->setNom(ligne.value(colNom).toString());
        action->setDescription(ligne.value(colDesc).toString());
        action->setEtat(ligne.value(colEtat).toBool());
        liste->append(action);
    }
    return liste;
}
