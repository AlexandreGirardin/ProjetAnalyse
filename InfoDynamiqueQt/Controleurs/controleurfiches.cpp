#include "Controleurs/controleurfiches.h"

#include "Controleurs/application.h"
#include "Mappeurs/mappeurfiches.h"
#include "Mappeurs/mappeurensembles.h"
#include "Mappeurs/mappeurstatuts.h"

void ControleurFiches::ajouterFiche(const int &idAppareil)
{
    VueGestionFiche* vue = new VueGestionFiche(Application::vuePrincipale());
    vue->setWindowTitle(tr("Créer une nouvelle fiche"));
    vue->setEnsembles(MappeurEnsembles::getEnsembles());
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

void ControleurFiches::assignerFiche(VueGestionFiche* vue, const Fiche* fiche)
{
    vue->setCommentaire(fiche->commentaire());
    vue->setEnsembles(MappeurEnsembles::getEnsembles());
}

void ControleurFiches::extraireFiche(Fiche *fiche, const VueGestionFiche * const vue)
{
    fiche->setCommentaire(vue->getCommentaire());
    fiche->setPriorite(vue->getPriorite());
//    fiche->setTaches(vue->getTaches);
}
