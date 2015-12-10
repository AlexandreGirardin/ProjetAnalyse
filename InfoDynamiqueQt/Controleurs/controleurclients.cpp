#include "controleurclients.h"
#include "ui_vueprincipale.h"

#include <QSqlQueryModel>

ControleurClients::ControleurClients(VuePrincipale* vuePrincipale, QObject* parent)
    : QObject(parent) {
    splitter = new QSplitter(Qt::Vertical, vuePrincipale->getUi()->ongletClients);
    vuePrincipale->getUi()->ongletClients->layout()->addWidget(splitter);
    controleurGestionClient = new ControleurGestionClient();
    controleurGestionAppareil = new ControleurGestionAppareil();
    controleurGestionFiche = new ControleurGestionFiche();
    configurerFragmentClients();
    configurerFragmentAppareils();
    configurerFragmentFiches();

    requeteClients = new QString(
                "select\
                      c.id as '#',\
                      coalesce(a.nb,0) as 'Nb. appareils',\
                      c.nom as 'Nom',\
                      c.telephone as 'Téléphone'\
                  from\
                      clients c\
                    left outer join\
                      (select idClient, count(id) as 'nb' from appareils group by idClient) a\
                    on\
                      c.id = a.idClient");

    peuplerClients();
}

void ControleurClients::configurerFragmentClients() {
    fragmentClients = new VueFragment(splitter);
    fragmentClients->getEtiquette()->setText("Clients");
    fragmentClients->getCaseCocher()->hide();
    QObject::connect(fragmentClients, SIGNAL(clicCreer()), controleurGestionClient, SLOT(ajouterClient()));
    QObject::connect(fragmentClients, SIGNAL(clicEditer()), this, SLOT(modifierClient()));
    QObject::connect(fragmentClients, SIGNAL(clicVoir()), this, SLOT(voirClient()));
}

void ControleurClients::configurerFragmentAppareils() {
    fragmentAppareils = new VueFragment(splitter);
    fragmentAppareils->getEtiquette()->setText("Appareils");
    fragmentAppareils->getCaseCocher()->hide();
    QObject::connect(fragmentAppareils, SIGNAL(clicCreer()), controleurGestionAppareil, SLOT(ajouterAppareil()));
    QObject::connect(fragmentClients, SIGNAL(modeleSelectionne(int)), this, SLOT(peuplerAppareils(int)));
    QObject::connect(fragmentClients, SIGNAL(modeleRelache()), fragmentAppareils, SLOT(relacherModele()));
    QObject::connect(fragmentClients, SIGNAL(modeleSelectionne(int)), fragmentAppareils, SLOT(show()));
    QObject::connect(fragmentClients, SIGNAL(modeleRelache()), fragmentAppareils, SLOT(hide()));
}

void ControleurClients::configurerFragmentFiches() {
    fragmentFiches = new VueFragment(splitter);
    fragmentFiches->getEtiquette()->setText("Fiches");
    fragmentFiches->getCaseCocher()->setText("Afficher toutes les fiches");
    QObject::connect(fragmentFiches, SIGNAL(clicCreer()), controleurGestionFiche, SLOT(ajouterFiche()));
    QObject::connect(fragmentAppareils, SIGNAL(modeleSelectionne(int)), this, SLOT(peuplerFiches(int)));
    QObject::connect(fragmentAppareils, SIGNAL(modeleRelache()), fragmentFiches, SLOT(relacherModele()));
    QObject::connect(fragmentAppareils, SIGNAL(modeleSelectionne(int)), fragmentFiches, SLOT(show()));
    QObject::connect(fragmentAppareils, SIGNAL(modeleRelache()), fragmentFiches, SLOT(hide()));
}

void ControleurClients::peuplerClients() {
    QSqlQueryModel* clients = new QSqlQueryModel(this);
    const QSqlDatabase bd = QSqlDatabase::database("dossiers");
    clients->setQuery(*requeteClients, bd);
    fragmentClients->peuplerTableau(clients);
}

void ControleurClients::peuplerAppareils(int idClient) {
    QSqlQueryModel* appareils = new QSqlQueryModel(this);
    appareils->setQuery(requeteAppareils(idClient));
    fragmentAppareils->peuplerTableau(appareils);
}

void ControleurClients::peuplerFiches(int idAppareil) {
    QSqlQueryModel* fiches = new QSqlQueryModel(this);
    fiches->setQuery(requeteFiches(idAppareil));
    fragmentFiches->peuplerTableau(fiches);
}

void ControleurClients::modifierClient() {
    if (fragmentClients->getIdModele() != -1) {
        controleurGestionClient->modifierClient(fragmentClients->getIdModele());
    }
}

void ControleurClients::voirClient() {
    if (fragmentClients->getIdModele() != -1) {
        controleurGestionClient->voirClient(fragmentClients->getIdModele());
    }
}

QSqlQuery ControleurClients::requeteAppareils(int idClient) const {
    QSqlQuery requete = QSqlQuery(QSqlDatabase::database("dossiers"));
    requete.prepare("SELECT * FROM appareils WHERE idClient=:idClient");
    requete.bindValue(":idClient", idClient);
    requete.exec();
    return requete;
}

QSqlQuery ControleurClients::requeteFiches(int idAppareil) const {
    QSqlQuery requete = QSqlQuery(QSqlDatabase::database("dossiers"));
    requete.prepare("SELECT * FROM fiches WHERE idAppareil=:idAppareil");
    requete.bindValue(":idAppareil", idAppareil);
    requete.exec();
    return requete;
}
