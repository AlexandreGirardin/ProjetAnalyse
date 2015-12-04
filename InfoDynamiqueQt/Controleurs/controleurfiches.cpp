#include "controleurfiches.h"
#include "ui_vueprincipale.h"
#include "ui_vuesecondaire.h"

ControleurFiches::ControleurFiches(VuePrincipale *vuePrincipale, QObject *parent) : QObject(parent)
{
    vueSecondaireFiches = new VueSecondaire();

    //Configuration du fragment
    fragment = new VueFragment();
    fragment->getEtiquette()->setText("Fiches");
    fragment->getBouton1()->setText("Ajouter une fiche");
    fragment->getBouton2()->setText("Modifier la fiche");
    fragment->getBouton2()->setDisabled(true);
    fragment->getBouton3()->setText("Visualiser la fiche");
    fragment->getBouton3()->setDisabled(true);
    fragment->getCaseCocher()->setText("Afficher toutes les fiches");
    vueSecondaireFiches->getUi()->verticalLayout->addWidget(fragment);

    vuePrincipale->getUi()->ongletFiches->layout()->addWidget(vueSecondaireFiches);
}

