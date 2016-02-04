#include "Mappeurs/mappeurclients.h"

#include "Controleurs/application.h"

#include <QDebug>
#include <QSqlError>

MappeurClients::MappeurClients(QObject* parent) : QObject(parent) {}

Client* MappeurClients::getClient(const int &id)
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

bool MappeurClients::inserer(const Client* client) const
{
    QSqlDatabase* bd = Application::bd;
    bd->transaction();
    const QString commande(
                "INSERT INTO clients\
                    (prenom, nom, telephone, adresse)\
                VALUES\
                    (:prenom, :nom, :telephone, :adresse)");
    QSqlQuery* requete = preparerRequete(client, commande);
    const bool succes = requete->exec();
    if (succes) {
        bd->commit();
    } else {
        qDebug() << requete->lastError();
        bd->rollback();
    }
    delete requete;
    return succes;
}

bool MappeurClients::mettreAJour(const Client *client) const
{
    QSqlDatabase* bd = Application::bd;
    bd->transaction();
    const QString commande(
                "UPDATE clients\
                SET\
                    prenom=:prenom,\
                    nom=:nom,\
                    telephone=:telephone,\
                    adresse=:adresse\
                WHERE id=:id");
    QSqlQuery* requete = preparerRequete(client, commande);
    const bool succes = requete->exec();
    if (succes) {
        bd->commit();
    } else {
        qDebug() << requete->lastError();
        bd->rollback();
    }
    delete requete;
    return succes;
}

Client* MappeurClients::mapper(const QSqlRecord &ligne)
{
    Client* client = new Client(this);
    client->setId(ligne.value("id").toInt());
    client->setPrenom(ligne.value("prenom").toString());
    client->setNom(ligne.value("nom").toString());
    client->setTelephone(ligne.value("telephone").toString());
    client->setAdresse(ligne.value("adresse").toString());
    client->setAppareils(Application::appareils->appareilsPourClient(client->id()));
    return client;
}

QSqlQuery* MappeurClients::preparerRequete(const Client* client, const QString &commande) const
{
    QSqlQuery* requete = new QSqlQuery(*Application::bd);
    requete->prepare(commande);
    requete->bindValue(":id", client->id());
    requete->bindValue(":nom", client->nom());
    requete->bindValue(":prenom", client->prenom());
    requete->bindValue(":telephone", client->telephone());
    requete->bindValue(":adresse", client->adresse());
    return requete;
}
