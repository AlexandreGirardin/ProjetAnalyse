#include "controleurappareils.h"
#include "ui_vueprincipale.h"
#include "ui_vuesecondaire.h"

ControleurAppareils::ControleurAppareils(VuePrincipale *vuePrincipale, QObject *parent) : QObject(parent)
{
    vueSecondaireAppareils = new VueSecondaire();
    fragment = new VueFragment();
    fragment->getEtiquette()->setText("Appareils");
    fragment->getBoutonAjouter()->setText("Ajouter un appareil");
    fragment->getBoutonModifier()->setText("Modifier l'appareil");
    fragment->getBoutonModifier()->setDisabled(true);
    fragment->getBoutonVoir()->setText("Visualiser l'appareil");
    fragment->getBoutonVoir()->setDisabled(true);
    fragment->getCaseCocher()->setHidden(true);
    vueSecondaireAppareils->getUi()->verticalLayout->addWidget(fragment);
    vuePrincipale->getUi()->ongletAppareils->layout()->addWidget(vueSecondaireAppareils);
}

