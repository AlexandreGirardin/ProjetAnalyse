#ifndef CONTROLEURGESTIONCLIENT_H
#define CONTROLEURGESTIONCLIENT_H

#include <QObject>

class Client;
class VueGestionClient;

class ControleurClients : public QObject{

    Q_OBJECT

    // Contrôle la gestion (création, modification, visualisation) des clients

private:

    /**
     * @brief assignerClient
     * Insère les informations d'un client dans les champs d'une fiche de gestion
     * @param vue La vue cible
     * @param client Le client source
     */
    static void assignerClient(VueGestionClient* vue, const Client* client);

    /**
     * @brief extraireClient
     * Transfère la valeur des champs d'une vue dans un client
     * @param client Le client cible
     * @param vue La vue source
     */
    static void extraireClient(Client* client, const VueGestionClient* vue);

public slots:

    /**
     * @brief ajouterClient
     * Lance la création d'un nouveau client
     * @return L'id du client nouvellement créé ou -1
     */
    static int ajouterClient();

    /**
     * @brief modifierClient
     * Lance la modification d'un client
     */
    static void modifierClient(const int &idClient);

    /**
     * @brief modifierClient
     * Lance la visualisation d'un client
     */
    static void voirClient(const int &idClient, const bool &modal = false);

    /**
     * @brief effacerClient
     * Lance la suppression d'un client
     * Ne fonctionnera que si le client n'a pas d'appareil
     * @param idClient L'id du client à effacer
     */
    static void effacerClient(const int &idClient);
};

#endif // CONTROLEURGESTIONCLIENT_H
