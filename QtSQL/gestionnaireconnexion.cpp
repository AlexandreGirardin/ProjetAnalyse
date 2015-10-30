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
    }
    else{

        qDebug() << "Connecté!";

        QSqlQuery query;
        query.exec("SELECT * FROM actions");
        QString name;

        while (query.next()) {
            name = query.value(0).toString();
            qDebug() << query.value(0).toString() << " " << query.value(1).toString();
        }
    }
    db.close();
}

