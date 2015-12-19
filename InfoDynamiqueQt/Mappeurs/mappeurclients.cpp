#include "Mappeurs/mappeurclients.h"

#include <QtSql/QSqlQuery>

MappeurClients::MappeurClients(QSqlDatabase* a_bd, QObject* parent) :
    QObject(parent) {
    bd = a_bd;
}

Client* MappeurClients::getClient(int id) {
    Client* client = NULL;
    QSqlQuery requete = QSqlQuery(QSqlDatabase::database("dossiers"));
    requete.prepare("SELECT * FROM clients WHERE id=:id");
    requete.bindValue(":id", id);
    requete.exec();
    if (requete.next()) {
        client = mapper(requete.record());
    }
    return client;
}

Client* MappeurClients::mapper(QSqlRecord ligne) {
    Client* client = new Client(this);
    client->setId(ligne.value("id").toInt());
    client->setPrenom(ligne.value("prenom").toString());
    client->setNom(ligne.value("nom").toString());
    client->setTelephone(ligne.value("telephone").toString());
    client->setAdresse(ligne.value("adresse").toString());
    return client;
}
