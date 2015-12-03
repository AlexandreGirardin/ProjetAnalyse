#include "controleurbd.h"
#include <QDebug>

ControleurBD::ControleurBD(QObject *parent) :
    QObject(parent)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("InfoDynamiqueDossiers");
    db.setUserName("root");
    db.setPassword("");
    if (!db.open()) {
        qDebug() << "Database error occurred";
    }
}

QSqlQuery ControleurBD::requete(const QString commande)
{
    QSqlQuery* query = new QSqlQuery(commande);
    query->exec();
    return *query;
}
