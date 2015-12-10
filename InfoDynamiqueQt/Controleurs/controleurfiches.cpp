#include "controleurfiches.h"
#include "ui_vueprincipale.h"
#include "ui_vuesecondaire.h"

ControleurFiches::ControleurFiches(VuePrincipale *vuePrincipale, QObject *parent) : QObject(parent)
{
    vueSecondaireFiches = new VueSecondaire();

    //Configuration du fragment
    fragment = new VueFragment();
    fragment->getEtiquette()->setText("Fiches");
    fragment->getBoutonAjouter()->setText("Ajouter une fiche");
    fragment->getBoutonModifier()->setText("Modifier la fiche");
    fragment->getBoutonModifier()->setDisabled(true);
    fragment->getBoutonVoir()->setText("Visualiser la fiche");
    fragment->getBoutonVoir()->setDisabled(true);
    fragment->getCaseCocher()->setText("Afficher toutes les fiches");
    vueSecondaireFiches->getUi()->verticalLayout->addWidget(fragment);

    vuePrincipale->getUi()->ongletFiches->layout()->addWidget(vueSecondaireFiches);
}

