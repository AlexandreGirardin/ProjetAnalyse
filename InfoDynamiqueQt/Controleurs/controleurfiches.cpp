#include "controleurfiches.h"
#include "ui_vueprincipale.h"
#include "ui_vuesecondaire.h"
#include "Vues/vueprincipale.h"
#include "Vues/vuesecondaire.h"
#include "Vues/vuefragment.h"

ControleurFiches::ControleurFiches(VuePrincipale *vuePrincipale, QObject *parent) : QObject(parent)
{
    vueSecondaireFiches = new VueSecondaire();
    fragment = new VueFragment();
    vueSecondaireFiches->getUi()->verticalLayout->addWidget(fragment);
    vuePrincipale->getUi()->ongletFiches->layout()->addWidget(vueSecondaireFiches);
}

