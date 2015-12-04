#include "gestionnaireconnexion.h"

GestionnaireConnexion::GestionnaireConnexion(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3307);
    db.setDatabaseName("InfoDynamiqueDossiers");
    db.setUserName("root");
    db.setPassword("patate");
    if (!db.open()) {
        qDebug() << "Database error occurred";
    }
}

QSqlQuery GestionnaireConnexion::requete(const QString commande) {
    QSqlQuery query(db);
    query.exec(commande);
    return query;
}
