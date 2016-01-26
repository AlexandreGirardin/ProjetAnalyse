#include "Controleurs/controleurbd.h"

#include <QDebug>
#include <QtSql/QSqlDatabase>

ControleurBD::ControleurBD(QObject* parent) :
    QObject(parent)
{
}

QSqlDatabase* ControleurBD::getBd()
{
    return &bd;
}

void ControleurBD::connecterDossiers()
{
    bd = QSqlDatabase::addDatabase(QString("QMYSQL"), nomBd());
    bd.setHostName("localhost");
    bd.setDatabaseName("InfoDynamiqueDossiers");
    bd.setPort(3307);
    bd.setUserName("root");
    bd.setPassword("patate");
    if (!bd.open()) {
        qDebug() << "Database error occurred";
    }
}

const QString ControleurBD::nomBd()
{
    return QString("dossiers");
}

const QString* ControleurBD::meta()
{
    return new QString("%");
}
