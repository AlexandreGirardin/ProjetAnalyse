#include "controleuractions.h"
#include "ui_vueprincipale.h"
#include "ui_vuesecondaire.h"

ControleurActions::ControleurActions(VuePrincipale *vuePrincipale, QObject *parent) : QObject(parent)
{
    vueSecondaireActions = new VueSecondaire();
    fragmentActions = new VueFragment();
    fragmentActions->getEtiquette()->setText("Actions");
    fragmentActions->getBoutonAjouter()->setText("Ajouter une action");
    fragmentActions->getBoutonModifier()->setText("Modifier l'action");
    fragmentActions->getBoutonModifier()->setDisabled(true);
    fragmentActions->getBoutonVoir()->setText("Visualiser l'action");
    fragmentActions->getBoutonVoir()->setDisabled(true);
    fragmentActions->getCaseCocher()->setText("Afficher toutes les actions");
    vueSecondaireActions->getUi()->verticalLayout->addWidget(fragmentActions);

    fragmentEnsembles = new VueFragment();
    fragmentEnsembles->getEtiquette()->setText("Ensembles");
    fragmentEnsembles->getBoutonAjouter()->setText("Ajouter un ensemble");
    fragmentEnsembles->getBoutonModifier()->setText("Modifier l'ensemble");
    fragmentEnsembles->getBoutonModifier()->setDisabled(true);
    fragmentEnsembles->getBoutonVoir()->setText("Visualiser l'ensemble");
    fragmentEnsembles->getBoutonVoir()->setDisabled(true);
    fragmentEnsembles->getCaseCocher()->setHidden(true);
    vueSecondaireActions->getUi()->verticalLayout->addWidget(fragmentEnsembles);
    vuePrincipale->getUi()->ongletActions->layout()->addWidget(vueSecondaireActions);
}

