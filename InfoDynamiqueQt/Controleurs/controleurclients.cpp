#include "controleurclients.h"
#include "ui_vueprincipale.h"
#include "ui_vuesecondaire.h"

#include <QSqlQueryModel>
#include <QDebug>

ControleurClients::ControleurClients(VuePrincipale* vuePrincipale, QObject* parent)
    : QObject(parent) {
    vueSecondaireClients = new VueSecondaire(vuePrincipale->getUi()->ongletClients);
    splitter = new QSplitter(Qt::Vertical, vueSecondaireClients);
    vueSecondaireClients->layout()->addWidget(splitter);
    vuePrincipale->getUi()->ongletClients->layout()->addWidget(vueSecondaireClients);
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
    QObject::connect(fragmentClients, SIGNAL(nouvelleSelection(QModelIndex)), this, SLOT(selectionnerClient(QModelIndex)));
}

void ControleurClients::configurerFragmentAppareils() {
    fragmentAppareils = new VueFragment(splitter);
    fragmentAppareils->getEtiquette()->setText("Appareils");
    fragmentAppareils->getCaseCocher()->hide();
    QObject::connect(fragmentAppareils, SIGNAL(clicCreer()), controleurGestionAppareil, SLOT(ajouterAppareil()));
    QObject::connect(this, SIGNAL(clientSelectionne(int)), this, SLOT(peuplerAppareils(int)));
    QObject::connect(this, SIGNAL(clientSelectionne(int)), fragmentAppareils, SLOT(show()));
    QObject::connect(this, SIGNAL(clientRelache()), this, SLOT(relacherAppareil()));
    QObject::connect(this, SIGNAL(clientRelache()), fragmentAppareils, SLOT(hide()));
    QObject::connect(fragmentAppareils, SIGNAL(nouvelleSelection(QModelIndex)), this, SLOT(selectionnerAppareil(QModelIndex)));
}

void ControleurClients::configurerFragmentFiches() {
    fragmentFiches = new VueFragment(splitter);
    fragmentFiches->getEtiquette()->setText("Fiches");
    fragmentFiches->getCaseCocher()->setText("Afficher toutes les fiches");
    QObject::connect(fragmentFiches, SIGNAL(clicCreer()), controleurGestionFiche, SLOT(ajouterFiche()));
    QObject::connect(this, SIGNAL(appareilSelectionne(int)), this, SLOT(peuplerFiches(int)));
    QObject::connect(this, SIGNAL(appareilSelectionne(int)), fragmentFiches, SLOT(show()));
    QObject::connect(this, SIGNAL(appareilRelache()), this, SLOT(relacherFiche()));
    QObject::connect(this, SIGNAL(appareilRelache()), fragmentFiches, SLOT(hide()));
    QObject::connect(fragmentFiches, SIGNAL(nouvelleSelection(QModelIndex)), this, SLOT(selectionnerFiche(QModelIndex)));
}

void ControleurClients::peuplerClients() {
    QSqlQueryModel* clients = new QSqlQueryModel(this);
    const QSqlDatabase bd = QSqlDatabase::database("dossiers");
    clients->setQuery(*requeteClients, bd);
    fragmentClients->setModele(clients);
    relacherClient();
}

void ControleurClients::modifierClient() {
    if (idClient != -1) {
        controleurGestionClient->modifierClient(idClient);
    }
}

void ControleurClients::voirClient()
{
    if (idClient != -1) {
        controleurGestionClient->voirClient(idClient);
    }
}

void ControleurClients::peuplerAppareils(int idClient) {
    QSqlQueryModel* appareils = new QSqlQueryModel(this);
    appareils->setQuery(requeteAppareils(idClient));
    fragmentAppareils->setModele(appareils);
    relacherAppareil();
}

QSqlQuery ControleurClients::requeteAppareils(int idClient) const {
    QSqlQuery requete = QSqlQuery(QSqlDatabase::database("dossiers"));
    requete.prepare("SELECT * FROM appareils WHERE idClient=:idClient");
    requete.bindValue(":idClient", idClient);
    requete.exec();
    return requete;
}

void ControleurClients::peuplerFiches(int idAppareil) {
    QSqlQueryModel* fiches = new QSqlQueryModel(this);
    fiches->setQuery(requeteFiches(idAppareil));
    fragmentFiches->setModele(fiches);
    relacherFiche();
}

QSqlQuery ControleurClients::requeteFiches(int idAppareil) const {
    QSqlQuery requete = QSqlQuery(QSqlDatabase::database("dossiers"));
    requete.prepare("SELECT * FROM fiches WHERE idAppareil=:idAppareil");
    requete.bindValue(":idAppareil", idAppareil);
    requete.exec();
    return requete;
}

void ControleurClients::selectionnerClient(QModelIndex caseSelectionnee) {
    fragmentClients->activerBoutonsModele();
    idClient = fragmentClients->getId(caseSelectionnee);
    emit clientSelectionne(idClient);
}

void ControleurClients::relacherClient() {
    fragmentClients->relacherModele();
    idClient = -1;
    emit clientRelache();
}

void ControleurClients::selectionnerAppareil(QModelIndex caseSelectionnee) {
    fragmentAppareils->activerBoutonsModele();
    idAppareil = fragmentAppareils->getId(caseSelectionnee);
    emit appareilSelectionne(idAppareil);
}

void ControleurClients::relacherAppareil() {
    fragmentAppareils->relacherModele();
    idAppareil = -1;
    emit appareilRelache();
}

void ControleurClients::selectionnerFiche(QModelIndex caseSelectionnee) {
    fragmentFiches->activerBoutonsModele();
    idFiche = fragmentFiches->getId(caseSelectionnee);
    emit ficheSelectionnee(idFiche);
}

void ControleurClients::relacherFiche() {
    fragmentFiches->relacherModele();
    idFiche = -1;
    emit ficheRelachee();
}
