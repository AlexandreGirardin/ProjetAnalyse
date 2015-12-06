#ifndef CONTROLEURGESTIONCLIENT_H
#define CONTROLEURGESTIONCLIENT_H

#include <QObject>
#include "Vues/vuegestionclient.h"

class ControleurGestionClient : public QObject
{
    Q_OBJECT

public:
    explicit ControleurGestionClient(QObject* parent = 0);

    // La vue utilisée pour modifier un client
    VueGestionClient* vueGestionClient;

signals:

public slots:

    /**
     * @brief ajouterClient Lance la création d'un nouveau client
     */
    void ajouterClient();
};

#endif // CONTROLEURGESTIONCLIENT_H
