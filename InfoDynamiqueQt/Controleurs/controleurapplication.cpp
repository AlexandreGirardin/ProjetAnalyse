#include "Controleurs/controleuractions.h"
#include "Controleurs/controleurappareils.h"
#include "Controleurs/controleurapplication.h"
#include "Controleurs/controleurclients.h"
#include "Controleurs/controleurfiches.h"
#include "Vues/vueprincipale.h"

ControleurApplication::ControleurApplication(QObject* parent) :
    QObject(parent) {
    vuePrincipale = new VuePrincipale();
    controleurClients = new ControleurClients(vuePrincipale, this);
    controleurFiches = new ControleurFiches(vuePrincipale, this);
    controleurAppareils = new ControleurAppareils(vuePrincipale, this);
    controleurActions = new ControleurActions(vuePrincipale, this);
}

void ControleurApplication::executer()
{
    vuePrincipale->showMaximized();
}


