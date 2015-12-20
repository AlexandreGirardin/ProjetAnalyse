#include "Controleurs/controleuractions.h"
#include "Controleurs/controleurappareils.h"
#include "Controleurs/controleurapplication.h"
#include "Controleurs/controleurclients.h"
#include "Controleurs/controleurfiches.h"
#include "Vues/vueprincipale.h"
#include "ui_vueprincipale.h"
#include <QDebug>

ControleurApplication::ControleurApplication(QObject* parent) :
    QObject(parent) {
    vuePrincipale = new VuePrincipale();
    controleurClients = new ControleurClients(vuePrincipale, this);
    controleurFiches = new ControleurFiches(vuePrincipale, this);
    controleurAppareils = new ControleurAppareils(vuePrincipale, this);
    controleurActions = new ControleurActions(vuePrincipale, this);
    QObject::connect(vuePrincipale->getUi()->onglets, SIGNAL(currentChanged(int)), this, SLOT(chargerOnglet()));
}

void ControleurApplication::executer() {
    chargerOnglet();
    vuePrincipale->show();
}

void ControleurApplication::chargerOnglet() {
    QWidget* onglet = vuePrincipale->getUi()->onglets->currentWidget();
    if (onglet == vuePrincipale->getUi()->ongletClients && !controleurClients->ongletDejaCharge) {
        controleurClients->peuplerClients();
    } else if (onglet == vuePrincipale->getUi()->ongletFiches && !controleurFiches->ongletDejaCharge) {
        controleurFiches->peuplerFiches();
    } else if (onglet == vuePrincipale->getUi()->ongletAppareils && !controleurAppareils->ongletDejaCharge) {
        controleurAppareils->peuplerAppareils();
    } else if (onglet == vuePrincipale->getUi()->ongletActions && !controleurActions->ongletDejaCharge) {
        controleurActions->peuplerActions();
        controleurActions->peuplerEnsembles();
    }
}


