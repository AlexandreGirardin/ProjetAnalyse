#include "Controleurs/controleurclients.h"

#include "Controleurs/application.h"
#include "Controleurs/controleurbd.h"
#include "Vues/vueclient.h"

#include <QSqlQueryModel>
#include <QDebug>

void ControleurClients::ajouterClient()
{
    VueGestionClient* vue = new VueGestionClient(Application::vuePrincipale());
    vue->setWindowTitle(tr("Créer un nouveau client"));
    if (vue->exec() == vue->Accepted) {
        Client* client = new Client(vue);
        extraireClient(client, vue);
        if (MappeurClients::inserer(client)) {
            emit Application::getInstance()->clientsModifies();
        } else {
            qDebug() << "Pas marché: " << client->out();
        }
        vue->deleteLater();
    }
}

void ControleurClients::modifierClient(const int &idClient)
{
    Client* client = MappeurClients::getClient(idClient);
    if (client != NULL) {
        VueGestionClient* vue = new VueGestionClient(Application::vuePrincipale());
        client->setParent(vue);
        vue->setWindowTitle(tr("Modifier un client"));
        assignerClient(vue, client);
        if (vue->exec() == vue->Accepted) {
            extraireClient(client, vue);
            if (MappeurClients::mettreAJour(client)) {
                emit Application::getInstance()->clientsModifies();
            } else {
                qDebug() << "Pas marché" << client->out();
            }
        }
        vue->deleteLater();
    }
}

void ControleurClients::voirClient(const int &idClient)
{
    Client* client = MappeurClients::getClient(idClient);
    if (client != NULL) {
        VueClient* vue = new VueClient(Application::vuePrincipale());
        client->setParent(vue);
        vue->setWindowTitle(tr("Informations d'un client"));
        vue->setPrenom(client->prenom());
        vue->setNom(client->nom());
        vue->setTelephone(client->telephone());
        vue->setAdresse(client->adresse());
        QObject::connect(vue, SIGNAL(finished(int)), vue, SLOT(deleteLater()));
        vue->show();
    }
}

void ControleurClients::assignerClient(VueGestionClient* vue, const Client* client)
{
    vue->setPrenom(client->prenom());
    vue->setNom(client->nom());
    vue->setTelephone(client->telephone());
    vue->setAdresse(client->adresse());
}

void ControleurClients::extraireClient(Client *client, const VueGestionClient* vue)
{
    client->setPrenom(vue->getPrenom());
    client->setNom(vue->getNom());
    client->setTelephone(vue->getTelephone());
    client->setAdresse(vue->getAdresse());
}

