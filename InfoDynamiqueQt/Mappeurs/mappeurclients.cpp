#include "Mappeurs/mappeurclients.h"

#include "Controleurs/application.h"

#include <QDebug>
#include <QSqlError>

MappeurClients::MappeurClients(QObject* parent) :
    QObject(parent)
{
}

bool MappeurClients::inserer(const Client* client)
{
    QSqlDatabase* bd = Application::bd;
    bd->transaction();
    QString* commande = new QString(
                "INSERT INTO clients\
                    (id, nom, prenom, telephone, adresse)\
                VALUES\
                    (:id, :nom, :prenom, :telephone, :adresse)");
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

Client* MappeurClients::getClient(const int id)
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
