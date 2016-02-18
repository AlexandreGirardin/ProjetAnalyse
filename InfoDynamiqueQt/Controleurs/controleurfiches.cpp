#include "Controleurs/controleurfiches.h"

#include "Controleurs/application.h"
#include "Mappeurs/mappeurappareils.h"
#include "Mappeurs/mappeurclients.h"
#include "Mappeurs/mappeurensembles.h"
#include "Mappeurs/mappeurfiches.h"
#include "Mappeurs/mappeurstatuts.h"
#include "Mappeurs/mappeurtaches.h"

#include "Vues/vueeditionfiche.h"
#include "QDebug"

void ControleurFiches::ajouterFiche(const int &idAppareil)
{
    VueGestionFiche* vue = new VueGestionFiche(Application::vuePrincipale());
    vue->setWindowTitle(tr("Créer une nouvelle fiche"));
    vue->setEnsembles(MappeurEnsembles::get());
    if (vue->exec() == vue->Accepted) {
        Fiche* fiche = new Fiche(vue);
        fiche->setIdAppareil(idAppareil);
        fiche->setStatut(MappeurStatuts::getStatutFiche(1));
        extraireFiche(fiche, vue);
        if (MappeurFiches::inserer(fiche)) {
            emit Application::getInstance()->ficheModifiee();
        }
        fiche->deleteLater();
    }
    vue->deleteLater();
}

void ControleurFiches::traiterFiche(const int &idFiche)
{
    Fiche* fiche = MappeurFiches::get(idFiche);
    if (fiche != NULL) {
        VueEditionFiche* vue = new VueEditionFiche(Application::vuePrincipale());
        vue->setIdFiche(fiche->id());
        vue->setCommentaire(fiche->commentaire());
        vue->setTaches(MappeurTaches::tachesPourFiche(fiche->id()));
        Appareil* appareil = MappeurAppareils::get(fiche->idAppareil());
        vue->setAppareil(appareil->id(), appareil->nomType() + " " + appareil->nomFabricant());
        Client* client = MappeurClients::get(appareil->idClient());
        vue->setClient(client->id(), client->prenom() + " " + client->nom(), client->telephone());
        vue->exec();
        vue->getTaches();
        vue->deleteLater();
    }
}

void ControleurFiches::assignerFiche(VueGestionFiche* vue, const Fiche* fiche)
{
    vue->setCommentaire(fiche->commentaire());
    vue->setEnsembles(MappeurEnsembles::get());
}

void ControleurFiches::extraireFiche(Fiche *fiche, const VueGestionFiche * const vue)
{
    fiche->setCommentaire(vue->getCommentaire());
    fiche->setPriorite(vue->getPriorite());
    //    fiche->setTaches(vue->getTaches);
}

void ControleurFiches::assignerFiche(VueEditionFiche* vue, const Fiche* fiche)
{
    vue->setCommentaire(fiche->commentaire());
}

void ControleurFiches::extraireFiche(Fiche* fiche, const VueEditionFiche* const vue)
{
    fiche->setCommentaire(vue->commentaire());
}
