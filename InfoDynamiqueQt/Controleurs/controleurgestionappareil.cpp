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

void ControleurGestionAppareil::voirAppareil(const int idAppareil)
{
    VueAppareil* vue = new VueAppareil(Application::getVuePrincipale());
    Appareil* appareil = Application::appareils->getAppareil(idAppareil);
    vue->setType(appareil->getNomType());
    vue->setFabricant(appareil->getNomFabricant());
    vue->setMotDePasse(appareil->getMotDePasse());
    vue->setDescription(appareil->getDescription());
    vue->show();
}
