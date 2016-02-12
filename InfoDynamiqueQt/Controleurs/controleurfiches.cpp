#include "Controleurs/controleurfiches.h"

#include "Controleurs/application.h"
#include "Mappeurs/mappeurfiches.h"

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
        vue->exec();
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
    vue->setTaches(fiche->taches());
}
