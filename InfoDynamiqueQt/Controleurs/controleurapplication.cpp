#include "controleurapplication.h"
#include "controleurclients.h"
#include "controleurfiches.h"
#include "Vues/vueprincipale.h"

ControleurApplication::ControleurApplication(QObject *parent) : QObject(parent)
{
    vuePrincipale = new VuePrincipale();
    controleurClients = new ControleurClients(vuePrincipale, this);
    controleurFiches = new ControleurFiches(vuePrincipale, this);
}

void ControleurApplication::executer()
{
    vuePrincipale->show();
}


