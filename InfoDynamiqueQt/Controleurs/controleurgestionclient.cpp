#include "Controleurs/controleurgestionclient.h"
#include "Vues/vuegestionclient.h"
#include "Controleurs/controleurbd.h"
#include <QDebug>

ControleurGestionClient::ControleurGestionClient(QObject* parent) : QObject(parent) {
    QSqlDatabase bd = QSqlDatabase::database(ControleurBD::nomBd());
    mappeur = new MappeurClients(&bd);
}

void ControleurGestionClient::ajouterClient() {
    VueGestionClient* vue = new VueGestionClient();
    vue->exec();
}

void ControleurGestionClient::modifierClient(int idClient) {
    VueGestionClient* vue = new VueGestionClient();
    Client* client = mappeur->getClient(idClient);
    assignerClient(vue, client);
    vue->exec();
}

void ControleurGestionClient::voirClient(int idClient) {
    VueGestionClient* vue = new VueGestionClient();
    Client* client = mappeur->getClient(idClient);
    assignerClient(vue, client);
    vue->setWindowModality(Qt::NonModal);
    vue->setLectureSeule();
    vue->show();
}

void ControleurGestionClient::assignerClient(VueGestionClient* vue, Client* client) {
    vue->getChampPrenom()->setText(client->getPrenom());
    vue->getChampNom()->setText(client->getNom());
    vue->getChampCourriel()->setText(client->getAdresse());
    vue->getChampTelephone()->setText(client->getTelephone());
    qDebug() << client->out();
}

