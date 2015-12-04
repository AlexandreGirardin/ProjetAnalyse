#include "controleurappareils.h"
#include "ui_vueprincipale.h"
#include "ui_vuesecondaire.h"

ControleurAppareils::ControleurAppareils(VuePrincipale *vuePrincipale, QObject *parent) : QObject(parent)
{
    vueSecondaireAppareils = new VueSecondaire();
    fragment = new VueFragment();
    fragment->getEtiquette()->setText("Appareils");
    fragment->getBouton1()->setText("Ajouter un appareil");
    fragment->getBouton2()->setText("Modifier l'appareil");
    fragment->getBouton2()->setDisabled(true);
    fragment->getBouton3()->setText("Visualiser l'appareil");
    fragment->getBouton3()->setDisabled(true);
    fragment->getCaseCocher()->setHidden(true);
    vueSecondaireAppareils->getUi()->verticalLayout->addWidget(fragment);
    vuePrincipale->getUi()->ongletAppareils->layout()->addWidget(vueSecondaireAppareils);
}

