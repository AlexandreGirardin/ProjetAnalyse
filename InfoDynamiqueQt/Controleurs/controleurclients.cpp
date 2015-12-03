#include "controleurclients.h"
#include "ui_vueprincipale.h"
#include "ui_vuesecondaire.h"
#include "Vues/vueprincipale.h"
#include "Vues/vuesecondaire.h"
#include "Vues/vuefragment.h"

ControleurClients::ControleurClients(VuePrincipale *vuePrincipale, QObject *parent) : QObject(parent)
{
    vueSecondaireClients = new VueSecondaire();
    fragmentClients = new VueFragment();
    vueSecondaireClients->getUi()->verticalLayout->addWidget(fragmentClients);
    fragmentAppareils = new VueFragment();
    fragmentAppareils->hide();
    vueSecondaireClients->getUi()->verticalLayout->addWidget(fragmentAppareils);
    fragmentFiches = new VueFragment();
    fragmentFiches->hide();
    vueSecondaireClients->getUi()->verticalLayout->addWidget(fragmentFiches);
    vuePrincipale->getUi()->ongletClients->layout()->addWidget(vueSecondaireClients);
}

