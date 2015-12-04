#include "controleuractions.h"
#include "ui_vueprincipale.h"
#include "ui_vuesecondaire.h"

ControleurActions::ControleurActions(VuePrincipale *vuePrincipale, QObject *parent) : QObject(parent)
{
    vueSecondaireActions = new VueSecondaire();
    fragmentActions = new VueFragment();
    fragmentActions->getEtiquette()->setText("Actions");
    fragmentActions->getBouton1()->setText("Ajouter une action");
    fragmentActions->getBouton2()->setText("Modifier l'action");
    fragmentActions->getBouton2()->setDisabled(true);
    fragmentActions->getBouton3()->setText("Visualiser l'action");
    fragmentActions->getBouton3()->setDisabled(true);
    fragmentActions->getCaseCocher()->setText("Afficher toutes les actions");
    vueSecondaireActions->getUi()->verticalLayout->addWidget(fragmentActions);

    fragmentEnsembles = new VueFragment();
    fragmentEnsembles->getEtiquette()->setText("Ensembles");
    fragmentEnsembles->getBouton1()->setText("Ajouter un ensemble");
    fragmentEnsembles->getBouton2()->setText("Modifier l'ensemble");
    fragmentEnsembles->getBouton2()->setDisabled(true);
    fragmentEnsembles->getBouton3()->setText("Visualiser l'ensemble");
    fragmentEnsembles->getBouton3()->setDisabled(true);
    fragmentEnsembles->getCaseCocher()->setHidden(true);
    vueSecondaireActions->getUi()->verticalLayout->addWidget(fragmentEnsembles);
    vuePrincipale->getUi()->ongletActions->layout()->addWidget(vueSecondaireActions);
}

