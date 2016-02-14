#ifndef MAPPEURCLIENTS_H
#define MAPPEURCLIENTS_H

#include "Modeles/client.h"

#include <QSqlQuery>
#include <QSqlRecord>

class MappeurClients {

    // Lit et écrit des objets Client dans la base de données

public:

    /**
     * @brief getClient
     * @param id Le numéro du client à mapper
     * @return Le client s'il existe, NULL autrement
     */
    static Client* getClient(const int &id);

    /**
     * @brief inserer
     * Inscrit un nouveau client dans la base de données
     * @param client Le client a insérer dans la base de données
     * @return succes
     */
    static bool inserer(Client* client);

    /**
     * @brief mettreAJour
     * Met à jour un client dans la base de données
     * @param client Le client à mettre à jour
     * @return Succès
     */
    static bool mettreAJour(const Client* client);

private:

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en client
     * @return Le client
     */
    static Client* mapper(const QSqlRecord &ligne);

    /**
     * @brief preparerRequete Assigne les valeurs d'un client à une requête préparée
     * @param client Le client source
     * @param commande La commande SQL à préparer
     * @return La commande préparée
     */
    static QSqlQuery* preparerRequete(const Client* client, const QString &commande);

    /**
     * @brief ecrire
     * Effectue une opération SQL à l'intérieur d'une transaction
     * La transaction est annulée si l'opération échoue et validée autrement
     * @param client Le client à inclure dans l'opération SQL
     * @param commande La commande à exécuter
     * @return Succès de l'opération
     */
    static bool ecrire(const Client* client, const QString &commande);
};

#endif // MAPPEURCLIENTS_H
