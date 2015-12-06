#include "controleurgestionclient.h"

ControleurGestionClient::ControleurGestionClient(QObject *parent) : QObject(parent) {
    vueGestionClient = new VueGestionClient();
}

void ControleurGestionClient::ajouterClient() {
    vueGestionClient->exec();
}

