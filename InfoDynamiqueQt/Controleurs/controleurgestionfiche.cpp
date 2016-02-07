#include "Controleurs/controleurgestionfiche.h"

#include "Controleurs/application.h"
#include <QDebug>

ControleurGestionFiche::ControleurGestionFiche(QObject* parent) : QObject(parent) {}

void ControleurGestionFiche::ajouterFiche(const int &idAppareil)
{
    VueGestionFiche* vue = new VueGestionFiche();
    vue->setWindowTitle(tr("Créer une nouvelle fiche"));
    vue->exec();
    vue->deleteLater();
}

void ControleurGestionFiche::modifierFiche(const int &idFiche)
{
    VueGestionFiche* vue = new VueGestionFiche();
    vue->setWindowTitle(tr("Modifier une fiche"));
    vue->exec();
    vue->deleteLater();
}

void ControleurGestionFiche::voirFiche(const int &idFiche)
{
//    const Fiche* fiche = Application::fiches->getFiche(idFiche); if (fiche !=
//    NULL) { VueGestionFiche* vue = new
//    VueGestionFiche(Application::vuePrincipale()); assignerFiche(vue, fiche);
//    vue->setLectureSeule(); QObject::connect(vue, SIGNAL(finished(int)), vue,
//    SLOT(deleteLater())); vue->show();
//    }
}

void ControleurGestionFiche::assignerFiche(VueGestionFiche* vue, const Fiche* fiche)
{

}
