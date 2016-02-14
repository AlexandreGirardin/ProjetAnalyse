#include "Controleurs/controleurfiches.h"

#include "Controleurs/application.h"
#include "Mappeurs/mappeurfiches.h"
#include "Mappeurs/mappeurensembles.h"

void ControleurFiches::ajouterFiche(const int &idAppareil)
{
    VueGestionFiche* vue = new VueGestionFiche(Application::vuePrincipale());
    vue->setWindowTitle(tr("Créer une nouvelle fiche"));
    if (vue->exec() == vue->Accepted) {
        Fiche* fiche = new Fiche(vue);
        fiche->setIdAppareil(idAppareil);
        extraireFiche(fiche, vue);
        if (MappeurFiches::inserer(fiche)) {
            emit Application::getInstance()->ficheModifiee();
        }
        fiche->deleteLater();
    }
    vue->deleteLater();
}

void ControleurFiches::voirFiche(const int &idFiche)
{
    Fiche* fiche = MappeurFiches::getFiche(idFiche);
    if (fiche != NULL) {
        VueGestionFiche* vue = new VueGestionFiche(Application::vuePrincipale());
        assignerFiche(vue, fiche);
        QObject::connect(vue, SIGNAL(finished(int)), vue, SLOT(deleteLater()));
        vue->show();
        fiche->deleteLater();
    }
}

void ControleurFiches::assignerFiche(VueGestionFiche* vue, const Fiche* fiche)
{
    vue->setCommentaire(fiche->commentaire());
    vue->setEnsembles(MappeurEnsembles::getEnsembles());
}

void ControleurFiches::extraireFiche(Fiche *fiche, const VueGestionFiche * const vue)
{
    fiche->setCommentaire(vue->getCommentaire());
//    fiche->setTaches(vue->getTaches);
}
