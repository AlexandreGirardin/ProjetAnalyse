#include "Controleurs/controleurgestionappareil.h"

#include "Controleurs/application.h"
#include "Mappeurs/mappeurfabricants.h"
#include "Mappeurs/mappeurtypeappareils.h"

#include <QDebug>

ControleurGestionAppareil::ControleurGestionAppareil(QObject* parent) : QObject(parent) {}

void ControleurGestionAppareil::ajouterAppareil(const int &idClient)
{
    VueGestionAppareil* vue = new VueGestionAppareil(Application::vuePrincipale());
    vue->setWindowTitle(tr("Créer un nouvel appareil"));
    vue->setTypes(MappeurTypeAppareils::getTypesAppareil());
    vue->setFabricants(MappeurFabricants::getFabricants());
    if (vue->exec() == vue->Accepted) {
        Appareil* appareil = new Appareil(vue);
        appareil->setIdClient(idClient);
        extraireAppareil(appareil, vue);
        if (MappeurAppareils::inserer(appareil)) {
            emit donneesModifiees();
            emit nombreAppareilsChange(idClient);
        } else {
            qDebug() << "Pas marché: " << appareil->out();
        }
        vue->deleteLater();
    }
}

void ControleurGestionAppareil::modifierAppareil(const int &idAppareil)
{
    Appareil* appareil = MappeurAppareils::getAppareil(idAppareil);
    if (appareil != NULL) {
        VueGestionAppareil* vue = new VueGestionAppareil(Application::vuePrincipale());
        vue->setWindowTitle(tr("Modifier un appareil"));
        assignerAppareil(vue, appareil);
        if (vue->exec() == vue->Accepted) {
            extraireAppareil(appareil, vue);
            if (MappeurAppareils::mettreAJour(appareil)) {
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
    Appareil* appareil = MappeurAppareils::getAppareil(idAppareil);
    if (appareil != NULL) {
        VueAppareil* vue = new VueAppareil(Application::vuePrincipale());
        vue->setWindowTitle(tr("Appareil"));
        assignerAppareil(vue, appareil);
        QObject::connect(vue, SIGNAL(finished(int)), vue, SLOT(deleteLater()));
        vue->show();
    }
    appareil->deleteLater();
}

void ControleurGestionAppareil::assignerAppareil(VueGestionAppareil *vue, const Appareil *appareil)
{
    vue->setTypes(MappeurTypeAppareils::getTypesAppareil(), appareil->nomType());
    vue->setFabricants(MappeurFabricants::getFabricants(), appareil->nomFabricant());
    vue->setMotDePasse(appareil->motDePasse());
    vue->setDescription(appareil->description());
}

void ControleurGestionAppareil::assignerAppareil(VueAppareil *vue, const Appareil *appareil)
{
    vue->setType(appareil->nomType());
    vue->setFabricant(appareil->nomFabricant());
    vue->setMotDePasse(appareil->motDePasse());
    vue->setDescription(appareil->description());
}

void ControleurGestionAppareil::extraireAppareil(Appareil *appareil, const VueGestionAppareil *vue)
{
    appareil->setMotDePasse(vue->getMotDePasse());
    appareil->setType(vue->getType());
    appareil->setFabricant(vue->getFabricant());
    appareil->setDescription(vue->getDescription());
}
