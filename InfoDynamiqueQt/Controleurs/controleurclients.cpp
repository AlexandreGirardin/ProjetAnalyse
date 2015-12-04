#include "controleurclients.h"
#include "ui_vueprincipale.h"
#include "ui_vuesecondaire.h"

ControleurClients::ControleurClients(VuePrincipale *vuePrincipale, QObject *parent) : QObject(parent)
{
    controleurGestionClient = new ControleurGestionClient();
    vueSecondaireClients = new VueSecondaire();
    //Configuration du fragmentClients
    fragmentClients = new VueFragment();
    fragmentClients->getEtiquette()->setText("Clients");
    fragmentClients->getBouton1()->setText("Ajouter un client");
    fragmentClients->getBouton2()->setText("Modifier le client");
    fragmentClients->getBouton2()->setDisabled(true);
    fragmentClients->getBouton3()->setText("Visualiser le client");
    fragmentClients->getBouton3()->setDisabled(true);
    fragmentClients->getCaseCocher()->setHidden(true);
    vueSecondaireClients->getUi()->verticalLayout->addWidget(fragmentClients);

    //Configuration du fragmentAppareils
    fragmentAppareils = new VueFragment();
    //fragmentAppareils->hide();
    fragmentAppareils->getEtiquette()->setText("Appareils");
    fragmentAppareils->getBouton1()->setText("Ajouter un appareil");
    fragmentAppareils->getBouton2()->setText("Modifier l'appareil");
    fragmentAppareils->getBouton2()->setDisabled(true);
    fragmentAppareils->getBouton3()->setText("Visualiser l'appareil");
    fragmentAppareils->getBouton3()->setDisabled(true);
    fragmentAppareils->getCaseCocher()->setHidden(true);
    vueSecondaireClients->getUi()->verticalLayout->addWidget(fragmentAppareils);

    //Configuration du fragmentFiches
    fragmentFiches = new VueFragment();
    //fragmentFiches->hide();
    fragmentFiches->getEtiquette()->setText("Fiches");
    fragmentFiches->getBouton1()->setText("Ajouter une fiche");
    fragmentFiches->getBouton2()->setText("Modifier la fiche");
    fragmentFiches->getBouton2()->setDisabled(true);
    fragmentFiches->getBouton3()->setText("Visualiser la fiche");
    fragmentFiches->getBouton3()->setDisabled(true);
    fragmentFiches->getCaseCocher()->setText("Afficher toutes les fiches");
    vueSecondaireClients->getUi()->verticalLayout->addWidget(fragmentFiches);
    vuePrincipale->getUi()->ongletClients->layout()->addWidget(vueSecondaireClients);

    QObject::connect(fragmentClients->getBouton1(), SIGNAL(pressed()), controleurGestionClient, SLOT(ajouterClient()));
}

