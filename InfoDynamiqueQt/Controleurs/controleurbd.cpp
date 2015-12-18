#include "controleurbd.h"

#include <QtSql/QSqlDatabase>
#include <QDebug>

ControleurBD::ControleurBD(QObject* parent) :
    QObject(parent) {
    bd = QSqlDatabase::addDatabase(QString("QMYSQL"), QString("dossiers"));
    bd.setHostName("localhost");
    bd.setPort(3307);
    bd.setDatabaseName("InfoDynamiqueDossiers");
    bd.setUserName("root");
    bd.setPassword("patate");
    if (!bd.open()) {
        qDebug() << "Database error occurred";
    }
}

QSqlDatabase* ControleurBD::getBd() {
    return &bd;
}
