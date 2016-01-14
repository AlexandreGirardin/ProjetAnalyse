#include "Controleurs/controleurgestionclient.h"

#include "Controleurs/application.h"
#include "Vues/vuegestionclient.h"

ControleurGestionClient::ControleurGestionClient(QObject* parent)
    : QObject(parent)
{
}

void ControleurGestionClient::ajouterClient()
{
    VueGestionClient* vue = new VueGestionClient(Application::getVuePrincipale());
    vue->exec();
}

void ControleurGestionClient::modifierClient(int idClient)
{
    VueGestionClient* vue = new VueGestionClient(Application::getVuePrincipale());
    Client* client = Application::clients->getClient(idClient);
    assignerClient(vue, client);
    vue->exec();
}

void ControleurGestionClient::voirClient(int idClient)
{
    VueGestionClient* vue = new VueGestionClient(Application::getVuePrincipale());
    Client* client = Application::clients->getClient(idClient);
    assignerClient(vue, client);
    vue->setLectureSeule();
    vue->show();
}

void ControleurGestionClient::assignerClient(VueGestionClient* vue, Client* client)
{
    vue->getChampPrenom()->setText(client->getPrenom());
    vue->getChampNom()->setText(client->getNom());
    vue->getChampCourriel()->setText(client->getAdresse());
    vue->getChampTelephone()->setText(client->getTelephone());
}

