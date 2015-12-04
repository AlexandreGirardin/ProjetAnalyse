#include "controleurbd.h"

#include <QtSql/QSqlDatabase>
#include <QDebug>

ControleurBD::ControleurBD(QObject *parent) :
    QObject(parent)
{
    bd = QSqlDatabase::addDatabase(QString("QMYSQL"), QString("dossiers"));
    bd.setHostName("localhost");
    bd.setDatabaseName("InfoDynamiqueDossiers");
    bd.setUserName("root");
    bd.setPassword("");
    if (!bd.open()) {
        qDebug() << "Database error occurred";
    }
}

QSqlQuery ControleurBD::requete(const QString commande)
{
    QSqlQuery* query = new QSqlQuery(bd);
    query->exec(commande);
    return *query;
}
QSqlDatabase *ControleurBD::getBd()
{
    return &bd;
}
