#include "Controleurs/controleurappareils.h"

#include "Controleurs/application.h"
#include "Mappeurs/mappeurappareils.h"
#include "Mappeurs/mappeurfabricants.h"
#include "Mappeurs/mappeurfiches.h"
#include "Mappeurs/mappeurtypeappareils.h"

#include <QMessageBox>

void ControleurAppareils::ajouterAppareil(const int &idClient)
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
            emit Application::getInstance()->nombreAppareilsChange();
        }
        vue->deleteLater();
    }
}

void ControleurAppareils::modifierAppareil(const int &idAppareil)
{
    Appareil* appareil = MappeurAppareils::getAppareil(idAppareil);
    if (appareil != NULL) {
        VueGestionAppareil* vue = new VueGestionAppareil(Application::vuePrincipale());
        vue->setWindowTitle(tr("Modifier un appareil"));
        assignerAppareil(vue, appareil);
        if (vue->exec() == vue->Accepted) {
            extraireAppareil(appareil, vue);
            if (MappeurAppareils::mettreAJour(appareil)) {
                emit Application::getInstance()->appareilModifie();
            }
        }
        vue->deleteLater();
    }
    appareil->deleteLater();
}

void ControleurAppareils::voirAppareil(const int &idAppareil)
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

void ControleurAppareils::effacerAppareil(const int &idAppareil)
{
    QList<Fiche*>* fiches = MappeurFiches::fichesPourAppareil(idAppareil);
    if (fiches->isEmpty()) {
        Appareil* appareil = MappeurAppareils::getAppareil(idAppareil);
        QMessageBox* confirmation = new QMessageBox(QMessageBox::Warning,
                        tr("Confirmation de la suppression"),
                        tr("Supprimer l'appareil?\n") + appareil->joliOut(),
                        QMessageBox::Ok | QMessageBox::Cancel);
        confirmation->setDefaultButton(QMessageBox::Cancel);
        if (confirmation->exec() == confirmation->Ok) {
            if (MappeurAppareils::supprimer(appareil)) {
                emit Application::getInstance()->nombreAppareilsChange();
            }
        }
        confirmation->deleteLater();
        appareil->deleteLater();
    } else {

    }
    qDeleteAll(*fiches);
    delete fiches;
}

void ControleurAppareils::assignerAppareil(VueGestionAppareil *vue, const Appareil *appareil)
{
    vue->setTypes(MappeurTypeAppareils::getTypesAppareil(), appareil->nomType());
    vue->setFabricants(MappeurFabricants::getFabricants(), appareil->nomFabricant());
    vue->setMotDePasse(appareil->motDePasse());
    vue->setDescription(appareil->description());
}

void ControleurAppareils::assignerAppareil(VueAppareil *vue, const Appareil *appareil)
{
    vue->setType(appareil->nomType());
    vue->setFabricant(appareil->nomFabricant());
    vue->setMotDePasse(appareil->motDePasse());
    vue->setDescription(appareil->description());
}

void ControleurAppareils::extraireAppareil(Appareil *appareil, const VueGestionAppareil *vue)
{
    appareil->setMotDePasse(vue->getMotDePasse());
    appareil->setType(MappeurTypeAppareils::getTypeAppareil(vue->getType()));
    appareil->setFabricant(MappeurFabricants::getFabricant(vue->getFabricant()));
    appareil->setDescription(vue->getDescription());
}
