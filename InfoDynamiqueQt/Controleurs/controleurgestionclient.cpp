#include "Controleurs/controleurgestionclient.h"
#include "Vues/vuegestionclient.h"

ControleurGestionClient::ControleurGestionClient(QObject *parent) : QObject(parent) {
//    VueGestionClient = new VueGestionClient();
}

void ControleurGestionClient::ajouterClient() {
    VueGestionClient* vue = new VueGestionClient();
    vue->exec();
}

void ControleurGestionClient::modifierClient(int idClient) {
    VueGestionClient* vue = new VueGestionClient();
    vue->setWindowTitle(QString::number(idClient));
    vue->exec();
}

