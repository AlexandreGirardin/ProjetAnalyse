#include "controleurbd.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>
#include <QtSql/QSql>
#include <QDebug>

ControleurBD::ControleurBD(QObject *parent) :
    QObject(parent)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("InfoDynamiqueDossiers");
    db.setDatabaseName("root");
    db.setPassword("");
    if (!db.open()) {
        qDebug() << "Database error occurred";
    }
    QStringList tables = db.tables();
    qDebug() << tables;
}

QSqlQuery ControleurBD::requete(const QString commande)
{
    QSqlQuery query(db);
    query.exec(commande);
    return query;
}
