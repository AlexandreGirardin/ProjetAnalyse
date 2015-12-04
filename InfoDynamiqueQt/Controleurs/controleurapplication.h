#ifndef CONTROLEURAPPLICATION_H
#define CONTROLEURAPPLICATION_H

#include <QObject>
#include "controleuractions.h"
#include "controleurappareils.h"
#include "controleurclients.h"
#include "controleurfiches.h"
#include "Vues/vueprincipale.h"

class ControleurApplication : public QObject
{
    Q_OBJECT
public:
    explicit ControleurApplication(QObject *parent = 0);
    void executer();

private:
    VuePrincipale *vuePrincipale;
    ControleurClients *controleurClients;
    ControleurFiches *controleurFiches;
    ControleurAppareils *controleurAppareils;
    ControleurActions *controleurActions;

signals:

public slots:
};

#endif // CONTROLEURAPPLICATION_H
