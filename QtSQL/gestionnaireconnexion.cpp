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
}

QSqlQuery GestionnaireConnexion::requete(const QString commande) {
    QSqlQuery query(db);
    query.exec(commande);
    return query;
}
