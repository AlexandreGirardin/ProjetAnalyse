#ifndef CONTROLEURCLIENTS_H
#define CONTROLEURCLIENTS_H

#include <QObject>
#include "Vues/vueprincipale.h"
#include "Vues/vuesecondaire.h"
#include "Vues/vuefragment.h"

class ControleurClients : public QObject
{
    Q_OBJECT
public:
    explicit ControleurClients(VuePrincipale *, QObject *parent = 0);

private:
    VueSecondaire *vueSecondaireClients;
    VueFragment *fragmentClients;
    VueFragment *fragmentAppareils;
    VueFragment *fragmentFiches;

signals:

public slots:
};

#endif // CONTROLEURCLIENTS_H
