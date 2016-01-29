#include "Controleurs/controleurgestionclient.h"

#include "Controleurs/application.h"
#include "Controleurs/controleurbd.h"

#include "Vues/vuegestionclient.h"
#include <QSqlQueryModel>
#include <QDebug>

ControleurGestionClient::ControleurGestionClient(QObject* parent)
    : QObject(parent)
{
}

void ControleurGestionClient::ajouterClient()
{
    VueGestionClient* vue = new VueGestionClient(Application::getVuePrincipale());
    if (vue->exec() == vue->Accepted) {
        Client* client = new Client();
        client->setPrenom(vue->getPrenom());
        client->setNom(vue->getNom());
        client->setTelephone(vue->getTelephone());
        client->setAdresse(vue->getAdresse());
        if (Application::clients->inserer(client)) {
            emit donneesModifiees();
        } else {
            qDebug() << "Pas marché: " << client->out();
        }
    }
}

void ControleurGestionClient::modifierClient(int idClient)
{
    Client* client = Application::clients->getClient(idClient);
    if (client != NULL) {
        VueGestionClient* vue = new VueGestionClient(Application::getVuePrincipale());
        assignerClient(vue, client);
        if (vue->exec() == vue->Accepted) {
            client->setNom(vue->getNom());
            client->setPrenom(vue->getPrenom());
            client->setTelephone(vue->getTelephone());
            client->setAdresse(vue->getAdresse());
            if (Application::clients->mettreAJour(client)) {
                emit donneesModifiees();
            } else {
                qDebug() << "Pas marché" << client->out();
            }
        }
    }
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
    vue->setPrenom(client->getPrenom());
    vue->setNom(client->getNom());
    vue->setTelephone(client->getTelephone());
    vue->setAdresse(client->getAdresse());
}

