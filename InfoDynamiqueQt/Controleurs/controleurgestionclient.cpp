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
    VueGestionClient* vue = new VueGestionClient(Application::vuePrincipale());
    vue->setWindowTitle(tr("Créer un nouveau client"));
    if (vue->exec() == vue->Accepted) {
        Client* client = new Client(vue);
        extraireClient(client, vue);
        if (Application::clients->inserer(client)) {
            emit donneesModifiees();
        } else {
            qDebug() << "Pas marché: " << client->out();
        }
        vue->deleteLater();
    }
}

void ControleurGestionClient::modifierClient(const int &idClient)
{
    Client* client = Application::clients->getClient(idClient);
    if (client != NULL) {
        VueGestionClient* vue = new VueGestionClient(Application::vuePrincipale());
        client->setParent(vue);
        vue->setWindowTitle(tr("Modifier un client"));
        assignerClient(vue, client);
        if (vue->exec() == vue->Accepted) {
            extraireClient(client, vue);
            if (Application::clients->mettreAJour(client)) {
                emit donneesModifiees();
            } else {
                qDebug() << "Pas marché" << client->out();
            }
        }
        vue->deleteLater();
    }
}

void ControleurGestionClient::voirClient(const int &idClient)
{
    Client* client = Application::clients->getClient(idClient);
    if (client != NULL) {
        VueGestionClient* vue = new VueGestionClient(Application::vuePrincipale());
        client->setParent(vue);
        vue->setWindowTitle(tr("Informations d'un client"));
        assignerClient(vue, client);
        vue->setLectureSeule();
        QObject::connect(vue, SIGNAL(finished(int)), vue, SLOT(deleteLater()));
        vue->show();
    }
}

void ControleurGestionClient::assignerClient(VueGestionClient* vue, const Client* client)
{
    vue->setPrenom(client->prenom());
    vue->setNom(client->nom());
    vue->setTelephone(client->telephone());
    vue->setAdresse(client->adresse());
}

void ControleurGestionClient::extraireClient(Client *client, const VueGestionClient* vue)
{
    client->setPrenom(vue->getPrenom());
    client->setNom(vue->getNom());
    client->setTelephone(vue->getTelephone());
    client->setAdresse(vue->getAdresse());
}

