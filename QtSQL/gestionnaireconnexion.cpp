#include "gestionnaireconnexion.h"

GestionnaireConnexion::GestionnaireConnexion(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("InfoDynamiqueDossiers");
    db.setUserName("root");
    db.setPassword("");
    if (!db.open()) {
        qDebug() << "Database error occurred";
    }else{
        qDebug() << "Connecté!";
    }
}

QSqlQuery GestionnaireConnexion::requete(const char *commande) {
    QSqlQuery query(db);
    query.exec(commande);
    return query;
}
