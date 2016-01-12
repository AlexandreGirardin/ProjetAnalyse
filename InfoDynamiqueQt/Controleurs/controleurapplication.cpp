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
    paresseux = QObject::connect(vuePrincipale->getUi()->onglets, SIGNAL(currentChanged(int)), this, SLOT(chargerOnglet()));
}

void ControleurApplication::executer() {
    clientsCharges = false;
    fichesChargees = false;
    appareilsCharges = false;
    actionsChargees = false;
    chargerOnglet();
    vuePrincipale->show();
}

void ControleurApplication::chargerOnglet() {
    QWidget* onglet = vuePrincipale->getUi()->onglets->currentWidget();
    if (onglet == vuePrincipale->getUi()->ongletClients && !clientsCharges) {
        controleurClients->peuplerClients();
        clientsCharges = true;
    } else if (onglet == vuePrincipale->getUi()->ongletFiches && !fichesChargees) {
        controleurFiches->peuplerFiches();
        fichesChargees = true;
    } else if (onglet == vuePrincipale->getUi()->ongletAppareils && !appareilsCharges) {
        controleurAppareils->peuplerAppareils();
        appareilsCharges = true;
    } else if (onglet == vuePrincipale->getUi()->ongletActions && !actionsChargees) {
        controleurActions->peuplerActions();
        controleurActions->peuplerEnsembles();
        actionsChargees = true;
    }
    verifierParesseux();
}

void ControleurApplication::verifierParesseux() {
    if (clientsCharges && fichesChargees && appareilsCharges && actionsChargees) {
        QObject::disconnect(paresseux);
    }
}


