#include "Controleurs/controleurgestionappareil.h"

#include "Vues/vueappareil.h"
#include "Controleurs/application.h"

ControleurGestionAppareil::ControleurGestionAppareil(QObject* parent) :
    QObject(parent)
{
    vueGestionAppareil = new VueGestionAppareil();
}

void ControleurGestionAppareil::ajouterAppareil()
{
    vueGestionAppareil->exec();
}

void ControleurGestionAppareil::voirAppareil(int idAppareil)
{
    VueAppareil* vue = new VueAppareil(Application::getVuePrincipale());
    Appareil* appareil = Application::appareils->getAppareil(idAppareil);
    vue->getChampFabricant()->setText(appareil->getNomFabricant());
    vue->getChampType()->setText(appareil->getNomType());
    vue->getChampDescription()->setText(appareil->getDescription());
    vue->getChampMotDePasse()->setText(appareil->getMotDePasse());
    vue->show();
}
