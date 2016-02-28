#include "Mappeurs/mappeurclients.h"

#include "Controleurs/application.h"
#include "Modeles/client.h"
#include "Mappeurs/aidemappeurs.h"
#include "Mappeurs/mappeurappareils.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

Client* MappeurClients::get(const int &id)
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

bool MappeurClients::inserer(Client* client)
{
    const QString commande(
                "INSERT INTO clients\
                    (prenom, nom, telephone, adresse, courriel)\
                VALUES\
                    (:prenom, :nom, :telephone, :adresse, :courriel)");
    bool succes = ecrire(client, commande);
    client->setId(AideMappeurs::derniereInsertion());
    return succes;
}

bool MappeurClients::mettreAJour(const Client *client)
{
    const QString commande(
                "UPDATE clients\
                SET\
                    prenom=:prenom,\
                    nom=:nom,\
                    telephone=:telephone,\
                    adresse=:adresse,\
                    courriel=:courriel\
                WHERE id=:id");
    return ecrire(client, commande);
}

bool MappeurClients::supprimer(const Client *client)
{
    const QString commande("DELETE FROM clients WHERE id=:id");
    return ecrire(client, commande);
}

Client* MappeurClients::mapper(const QSqlRecord &ligne)
{
    Client* client = new Client();
    client->setId(ligne.value("id").toInt());
    client->setPrenom(ligne.value("prenom").toString());
    client->setNom(ligne.value("nom").toString());
    client->setTelephone(ligne.value("telephone").toString());
    client->setAdresse(ligne.value("adresse").toString());
    client->setCourriel(ligne.value("courriel").toString());
    return client;
}

QSqlQuery* MappeurClients::preparerRequete(const Client* client, const QString &commande)
{
    QSqlQuery* requete = new QSqlQuery(*Application::bd);
    requete->prepare(commande);
    requete->bindValue(":id", client->id());
    requete->bindValue(":nom", client->nom());
    requete->bindValue(":prenom", client->prenom());
    requete->bindValue(":telephone", client->telephone());
    requete->bindValue(":adresse", client->adresse());
    requete->bindValue(":courriel", client->courriel());
    return requete;
}

bool MappeurClients::ecrire(const Client* client, const QString &commande)
{
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    QSqlQuery* requete = preparerRequete(client, commande);
    const bool succes = requete->exec();
    if (succes) {
        bd.commit();
    } else {
        Application::erreurEcriture(requete->lastError().text());
        bd.rollback();
    }
    delete requete;
    return succes;
}
