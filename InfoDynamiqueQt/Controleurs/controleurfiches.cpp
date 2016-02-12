#include "Controleurs/controleurfiches.h"

#include "Controleurs/application.h"
#include "Mappeurs/mappeurfiches.h"
#include "Mappeurs/mappeurensembles.h"

#include <QDebug>

ControleurFiches::ControleurFiches(QObject* parent) : QObject(parent) {}

void ControleurFiches::ajouterFiche(const int &idAppareil)
{
    VueGestionFiche* vue = new VueGestionFiche();
    vue->setWindowTitle(tr("Créer une nouvelle fiche"));
    vue->exec();
    vue->deleteLater();
}

void ControleurFiches::modifierFiche(const int &idFiche)
{
    Fiche* fiche = MappeurFiches::getFiche(idFiche);
    if (fiche != NULL) {
        VueGestionFiche* vue = new VueGestionFiche();
        assignerFiche(vue, fiche);
        vue->setWindowTitle(tr("Modifier une fiche"));
        if (vue->exec() == vue->Accepted) {
            extraireFiche(fiche, vue);
            if (MappeurFiches::mettreAJour(fiche)) {
                emit Application::getInstance()->fichesModifiees();
            }
        }
        vue->deleteLater();
    }
}

void ControleurFiches::voirFiche(const int &idFiche)
{
    const Fiche* fiche = MappeurFiches::getFiche(idFiche);
    if (fiche != NULL) {
        VueGestionFiche* vue = new VueGestionFiche(Application::vuePrincipale());
        assignerFiche(vue, fiche);
        vue->setLectureSeule();
        QObject::connect(vue, SIGNAL(finished(int)), vue, SLOT(deleteLater()));
        vue->show();
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
