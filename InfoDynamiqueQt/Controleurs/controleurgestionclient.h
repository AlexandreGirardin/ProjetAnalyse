#ifndef CONTROLEURGESTIONCLIENT_H
#define CONTROLEURGESTIONCLIENT_H

#include <QObject>

#include "Mappeurs/mappeurclients.h"
#include "Vues/vuegestionclient.h"

class ControleurGestionClient : public QObject{
    Q_OBJECT

    // Contrôle l'exécution de la création, de la lecture et de la mise à jour des clients

public:

    /**
     * @brief ControleurGestionClient
     * @param parent
     */
    explicit ControleurGestionClient(QObject* parent = 0);

private:

    /**
     * @brief mappeur
     */
    MappeurClients* mappeur;

    /**
     * @brief assignerClient
     * Insère les informations d'un client dans les champs d'une fiche de gestion
     * @param vue La vue cible
     * @param client Le client cible
     */
    void assignerClient(VueGestionClient *vue, Client *client);

public slots:

    /**
     * @brief ajouterClient
     * Lance la création d'un nouveau client
     */
    void ajouterClient();

    /**
     * @brief modifierClient
     * Lance la modification d'un client
     */
    void modifierClient(int idClient);

    /**
     * @brief modifierClient
     * Lance la modification d'un client
     */
    void voirClient(int idClient);
};

#endif // CONTROLEURGESTIONCLIENT_H
