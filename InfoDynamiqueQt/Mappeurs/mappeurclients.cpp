#include "Mappeurs/mappeurclients.h"

#include "Controleurs/application.h"

#include <QDebug>
#include <QSqlError>

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

bool MappeurClients::inserer(const Client* client)
{
    QSqlDatabase* bd = Application::bd;
    bd->transaction();
    QString* commande = new QString(
                "INSERT INTO clients\
                    (id, nom, prenom, telephone, adresse)\
                VALUES\
                    (:id, :prenom, :nom, :telephone, :adresse)");
    QSqlQuery* requete = preparerRequete(client, commande);
    bool succes = requete->exec();
    if (succes) {
        bd->commit();
    } else {
        qDebug() << requete->lastError();
        bd->rollback();
    }
    return succes;
}

<<<<<<< HEAD
bool MappeurClients::mettreAJour(const Client *client)
=======
Client* MappeurClients::getClient(const int id)
>>>>>>> 45d7d11832c9fc05d5ca2bc845a62be9588290fd
{
    QSqlDatabase* bd = Application::bd;
    bd->transaction();
    QString* commande = new QString(
                "UPDATE clients\
                SET\
                    prenom=:prenom,\
                    nom=:nom,\
                    telephone=:telephone,\
                    adresse=:adresse\
                WHERE id=:id");
    QSqlQuery* requete = preparerRequete(client, commande);
    bool succes = requete->exec();
    if (succes) {
        bd->commit();
    } else {
        qDebug() << requete->lastError();
        bd->rollback();
    }
    return succes;
}

Client* MappeurClients::mapper(const QSqlRecord ligne)
{
    Client* client = new Client(this);
    client->setId(ligne.value("id").toInt());
    client->setPrenom(ligne.value("prenom").toString());
    client->setNom(ligne.value("nom").toString());
    client->setTelephone(ligne.value("telephone").toString());
    client->setAdresse(ligne.value("adresse").toString());
    return client;
}

QSqlQuery* MappeurClients::preparerRequete(const Client* client, const QString* commande)
{
    QSqlQuery* requete = new QSqlQuery(*Application::bd);
    requete->prepare(*commande);
    requete->bindValue(":id", client->getId());
    requete->bindValue(":nom", client->getNom());
    requete->bindValue(":prenom", client->getPrenom());
    requete->bindValue(":telephone", client->getTelephone());
    requete->bindValue(":adresse", client->getAdresse());
    return requete;
}
