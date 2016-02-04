#include "Controleurs/controleurgestionappareil.h"

#include "Vues/vueappareil.h"
#include "Controleurs/application.h"
#include <QDebug>

ControleurGestionAppareil::ControleurGestionAppareil(QObject* parent) :
    QObject(parent)
{
    vueGestionAppareil = new VueGestionAppareil();
}

void ControleurGestionAppareil::ajouterAppareil()
{
    vueGestionAppareil->exec();
}

void ControleurGestionAppareil::modifierAppareil(const int &idAppareil)
{
    Appareil* appareil = Application::appareils->getAppareil(idAppareil);
    if (appareil != NULL) {
        VueGestionAppareil* vue = new VueGestionAppareil(Application::getVuePrincipale());
        vue->setTypes(Application::typesAppareils->getTypesAppareil(), appareil->nomType());
        vue->setFabricants(Application::fabricants->getFabricants(), appareil->nomFabricant());
        vue->setMotDePasse(appareil->motDePasse());
        vue->setDescription(appareil->description());
        if (vue->exec() == vue->Accepted) {
            appareil->setMotDePasse(vue->getMotDePasse());
            appareil->setType(vue->getType());
            appareil->setFabricant(vue->getFabricant());
            appareil->setDescription(vue->getDescription());
            if (Application::appareils->mettreAJour(appareil)) {
                emit donneesModifiees();
            } else {
                qDebug() << "Pas marché: " << appareil->out();
            }
        }
        vue->deleteLater();
    }
    appareil->deleteLater();
}

void ControleurGestionAppareil::voirAppareil(const int &idAppareil)
{    
    Appareil* appareil = Application::appareils->getAppareil(idAppareil);
    if (appareil != NULL) {
        VueAppareil* vue = new VueAppareil(Application::getVuePrincipale());
        vue->setType(appareil->nomType());
        vue->setFabricant(appareil->nomFabricant());
        vue->setMotDePasse(appareil->motDePasse());
        vue->setDescription(appareil->description());
        QObject::connect(vue, SIGNAL(finished(int)), vue, SLOT(deleteLater()));
        vue->show();
    }
    appareil->deleteLater();
}
