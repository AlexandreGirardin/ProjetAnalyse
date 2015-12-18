#include "Controleurs/controleurgestionappareil.h"

ControleurGestionAppareil::ControleurGestionAppareil(QObject* parent) :
    QObject(parent) {
    vueGestionAppareil = new VueGestionAppareil();
}

void ControleurGestionAppareil::ajouterAppareil() {
    vueGestionAppareil->exec();
}
