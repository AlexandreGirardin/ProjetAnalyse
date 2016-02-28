#include "Controleurs/controleurclients.h"

#include "Controleurs/application.h"
#include "Mappeurs/mappeurappareils.h"
#include "Mappeurs/mappeurclients.h"
#include "Modeles/client.h"
#include "Vues/vueclient.h"
#include "Vues/vuegestionclient.h"
#include "Vues/vueprincipale.h"

int ControleurClients::ajouterClient()
{
    int id = -1;
    VueGestionClient* vue = new VueGestionClient(Application::vuePrincipale());
    vue->setWindowTitle(tr("Créer un nouveau client"));
    if (vue->exec() == vue->Accepted) {
        Client* client = new Client(vue);
        extraireClient(client, vue);
        if (MappeurClients::inserer(client)) {
            id = client->id();
            emit Application::getInstance()->nombreClientsChange();
        }
        vue->deleteLater();
    }
    return id;
}

void ControleurClients::modifierClient(const int &idClient)
{
    Client* client = MappeurClients::get(idClient);
    if (client != NULL) {
        VueGestionClient* vue = new VueGestionClient(Application::vuePrincipale());
        vue->setWindowTitle(tr("Modifier un client"));
        assignerClient(vue, client);
        if (vue->exec() == vue->Accepted) {
            extraireClient(client, vue);
            if (MappeurClients::mettreAJour(client)) {
                emit Application::getInstance()->clientModifie();
            }
        }
        vue->deleteLater();
        client->deleteLater();
    }
}

void ControleurClients::voirClient(const int &idClient, const bool &modal)
{
    Client* client = MappeurClients::get(idClient);
    if (client != NULL) {
        VueClient* vue = new VueClient(Application::vuePrincipale());
        vue->setModal(modal);
        vue->setWindowTitle(tr("Informations d'un client"));
        vue->setPrenom(client->prenom());
        vue->setNom(client->nom());
        vue->setTelephone(client->telephone());
        vue->setAdresse(client->adresse());
        vue->setCourriel(client->courriel());
        QObject::connect(vue, SIGNAL(finished(int)), vue, SLOT(deleteLater()));
        vue->show();
        client->deleteLater();
    }
}

void ControleurClients::effacerClient(const int &idClient)
{
    if (MappeurAppareils::nombreAppareils(idClient) == 0) {
        Client* client = MappeurClients::get(idClient);
        QMessageBox* confirmation = new QMessageBox(QMessageBox::Warning,
                        tr("Confirmation de la suppression"),
                        tr("Supprimer le client?\n") + client->out(),
                        QMessageBox::Ok | QMessageBox::Cancel);
        confirmation->setDefaultButton(QMessageBox::Cancel);
        if (confirmation->exec() == confirmation->Ok) {
            if (MappeurClients::supprimer(client)) {
                emit Application::getInstance()->nombreClientsChange();
            }
        }
        confirmation->deleteLater();
        client->deleteLater();
    }
}

void ControleurClients::assignerClient(VueGestionClient* vue, const Client* client)
{
    vue->setPrenom(client->prenom());
    vue->setNom(client->nom());
    vue->setTelephone(client->telephone());
    vue->setAdresse(client->adresse());
    vue->setCourriel(client->courriel());
}

void ControleurClients::extraireClient(Client *client, const VueGestionClient* vue)
{
    client->setPrenom(vue->getPrenom());
    client->setNom(vue->getNom());
    client->setTelephone(vue->getTelephone());
    client->setAdresse(vue->getAdresse());
    client->setCourriel(vue->getCourriel());
}

