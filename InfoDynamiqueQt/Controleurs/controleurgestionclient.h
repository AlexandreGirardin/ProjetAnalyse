#ifndef CONTROLEURGESTIONCLIENT_H
#define CONTROLEURGESTIONCLIENT_H

#include <QObject>

#include "Mappeurs/mappeurclients.h"
#include "Vues/vuegestionclient.h"

class ControleurGestionClient : public QObject{
    Q_OBJECT

public:
    explicit ControleurGestionClient(QObject* parent = 0);

private:
    MappeurClients* mappeur;

    void assignerClient(VueGestionClient *vue, Client *client);
signals:

public slots:

    /**
     * @brief ajouterClient Lance la création d'un nouveau client
     */
    void ajouterClient();

    /**
     * @brief modifierClient Lance la modification d'un client
     */
    void modifierClient(int idClient);

    void voirClient(int idClient);
};

#endif // CONTROLEURGESTIONCLIENT_H
