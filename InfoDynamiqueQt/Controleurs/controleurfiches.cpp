#include "Controleurs/controleurfiches.h"

#include "Controleurs/application.h"
#include "Mappeurs/mappeurfiches.h"
#include "Mappeurs/mappeurensembles.h"

#include <QDebug>

void ControleurFiches::ajouterFiche(const int &idAppareil)
{
    VueGestionFiche* vue = new VueGestionFiche(Application::vuePrincipale());
    vue->setWindowTitle(tr("Créer une nouvelle fiche"));
    if (vue->exec() == vue->Accepted) {
        Fiche* fiche = new Fiche(vue);
        extraireFiche(fiche, vue);
        if (MappeurFiches::inserer(fiche)) {
            emit Application::getInstance()->fichesModifiees();
        }
        vue->deleteLater();
    }
}

void ControleurFiches::assignerFiche(VueGestionFiche* vue, const Fiche* fiche)
{
    vue->setCommentaire(fiche->commentaire());
    vue->setTaches(fiche->taches());
    vue->setEnsembles(MappeurEnsembles::getEnsembles());
}

void ControleurFiches::extraireFiche(Fiche *fiche, const VueGestionFiche * const vue)
{

}
