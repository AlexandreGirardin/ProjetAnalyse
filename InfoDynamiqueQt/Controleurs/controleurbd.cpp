#include "Controleurs/controleurbd.h"

#include "ui_vueconnexion.h"

#include "Controleurs/application.h"
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
    VueConnexion* vue = new VueConnexion(Application::getVuePrincipale());
    if (vue->exec() == vue->Accepted) {
        bd = QSqlDatabase::addDatabase(QString("QMYSQL"), nomBd());
        bd.setHostName(vue->getHote());
        bd.setDatabaseName("InfoDynamiqueDossiers");
        bd.setPort(vue->getPort());
        bd.setUserName(vue->getUsager());
        bd.setPassword(vue->getMotDePasse());
        if (!bd.open()) {
            qDebug() << "Database error occurred";
        }
    }
}

const QString ControleurBD::nomBd()
{
    return QString("dossiers");
}

const QString* ControleurBD::meta = new QString("%");
