#include "controleurgestionfiche.h"

ControleurGestionFiche::ControleurGestionFiche(QObject *parent) :
    QObject(parent) {
    vueGestionFiche = new VueGestionFiche();
}

void ControleurGestionFiche::ajouterFiche() {
    vueGestionFiche->exec();
}
