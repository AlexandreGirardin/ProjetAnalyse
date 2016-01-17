#include "Mappeurs/mappeurclients.h"

#include "Controleurs/application.h"

#include <QtSql/QSqlQuery>

MappeurClients::MappeurClients(QObject* parent) :
    QObject(parent)
{
}

Client* MappeurClients::getClient(int id)
{
    Client* client = NULL;
    QSqlQuery requete = QSqlQuery(*Application::bd);
    requete.prepare("SELECT * FROM clients WHERE id=:id");
    requete.bindValue(":id", id);
    requete.exec();
    if (requete.next()) {
        client = mapper(requete.record());
    }
    return client;
}

Client* MappeurClients::mapper(QSqlRecord ligne)
{
    Client* client = new Client(this);
    client->setId(ligne.value("id").toInt());
    client->setPrenom(ligne.value("prenom").toString());
    client->setNom(ligne.value("nom").toString());
    client->setTelephone(ligne.value("telephone").toString());
    client->setCourriel(ligne.value("adresse").toString());
    return client;
}
