#ifndef CONTROLEURCLIENTS_H
#define CONTROLEURCLIENTS_H

#include <QObject>
#include "Controleurs/controleurgestionclient.h"
#include "Vues/vueprincipale.h"
#include "Vues/vuesecondaire.h"
#include "Vues/vuefragment.h"

class ControleurClients : public QObject
{
    Q_OBJECT
public:
    explicit ControleurClients(VuePrincipale *, QObject *parent = 0);

private:
    ControleurGestionClient *controleurGestionClient;
    VueSecondaire *vueSecondaireClients;
    VueFragment *fragmentClients;
    VueFragment *fragmentAppareils;
    VueFragment *fragmentFiches;

signals:

public slots:
};

#endif // CONTROLEURCLIENTS_H
