#include "Mappeurs/mappeuractions.h"

#include <QVariant>
#include <QtSql/QSqlQuery>

MappeurActions::MappeurActions(QSqlDatabase* a_bd, QObject* parent) :
    QObject(parent) {
    bd = a_bd;
}

Action* MappeurActions::getAction(int id) {
    Action* action = NULL;
    QString requete = "SELECT * FROM actions WHERE id="+QString::number(id);
    QSqlQuery* commande = new QSqlQuery(requete,* bd);
    if (commande->next()) {
        action = mapper(commande->record());
    }
    return action;
}

Action* MappeurActions::mapper(QSqlRecord ligne) {
    return new Action(ligne.value("id").toInt(),
                     ligne.value("nom").toString(),
                     ligne.value("description").toString(), this);
}

QList<Action*>* MappeurActions::getActions() {
    QList<Action*>* liste = new QList<Action*>();
    QString requete = "SELECT * FROM actions";
    QSqlQuery* commande = new QSqlQuery(requete,* bd);
    QSqlRecord ligne = commande->record();
    int colId = ligne.indexOf("id");
    int colNom = ligne.indexOf("nom");
    int colDesc = ligne.indexOf("description");
    while (commande->next()) {
        Action* action = new Action(ligne.value(colId).toInt(),
                                    ligne.value(colNom).toString(),
                                    ligne.value(colDesc).toString(), this);
        liste->append(action);
    }
    return liste;
}
