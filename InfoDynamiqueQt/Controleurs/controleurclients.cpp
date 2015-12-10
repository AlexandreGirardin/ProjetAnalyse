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
    QObject::connect(fragmentClients->getBouton1(), SIGNAL(pressed()), controleurGestionClient, SLOT(ajouterClient()));
    QObject::connect(fragmentClients->getBouton2(), SIGNAL(pressed()), this, SLOT(modifierClient()));
    QObject::connect(fragmentClients->getTableau(), SIGNAL(activated(QModelIndex)), this, SLOT(selectionnerClient(QModelIndex)));
}

void ControleurClients::configurerFragmentAppareils() {
    fragmentAppareils = new VueFragment(splitter);
    fragmentAppareils->getEtiquette()->setText("Appareils");
    fragmentAppareils->getCaseCocher()->hide();
    QObject::connect(fragmentAppareils->getBouton1(), SIGNAL(pressed()), controleurGestionAppareil, SLOT(ajouterAppareil()));
    QObject::connect(this, SIGNAL(clientSelectionne(int)), this, SLOT(peuplerAppareils(int)));
    QObject::connect(this, SIGNAL(clientSelectionne(int)), fragmentAppareils, SLOT(show()));
    QObject::connect(this, SIGNAL(clientRelache()), this, SLOT(relacherAppareil()));
    QObject::connect(this, SIGNAL(clientRelache()), fragmentAppareils, SLOT(hide()));
    QObject::connect(fragmentAppareils->getTableau(), SIGNAL(pressed(QModelIndex)), this, SLOT(selectionnerAppareil(QModelIndex)));
}

void ControleurClients::configurerFragmentFiches() {
    fragmentFiches = new VueFragment(splitter);
    fragmentFiches->getEtiquette()->setText("Fiches");
    fragmentFiches->getCaseCocher()->setText("Afficher toutes les fiches");
    QObject::connect(fragmentFiches->getBouton1(), SIGNAL(pressed()), controleurGestionFiche, SLOT(ajouterFiche()));
    QObject::connect(this, SIGNAL(appareilSelectionne(int)), this, SLOT(peuplerFiches(int)));
    QObject::connect(this, SIGNAL(appareilSelectionne(int)), fragmentFiches, SLOT(show()));
    QObject::connect(this, SIGNAL(appareilRelache()), this, SLOT(relacherFiche()));
    QObject::connect(this, SIGNAL(appareilRelache()), fragmentFiches, SLOT(hide()));
    QObject::connect(fragmentFiches->getTableau(), SIGNAL(pressed(QModelIndex)), this, SLOT(selectionnerFiche(QModelIndex)));
}

void ControleurClients::peuplerClients() {
    QSqlQueryModel* clients = new QSqlQueryModel(this);
    const QSqlDatabase bd = QSqlDatabase::database("dossiers");
    clients->setQuery(*requeteClients, bd);
    fragmentClients->setModele(clients);
    fragmentClients->getTableau()->resizeColumnsToContents();
    relacherClient();
}

void ControleurClients::modifierClient() {
    if (idClient != -1) {
        controleurGestionClient->modifierClient(idClient);
    }
}

void ControleurClients::peuplerAppareils(int idClient) {
    QSqlQueryModel* appareils = new QSqlQueryModel(this);
    appareils->setQuery(requeteAppareils(idClient));
    fragmentAppareils->setModele(appareils);
    fragmentAppareils->getTableau()->resizeColumnsToContents();
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
    fragmentFiches->getTableau()->resizeColumnsToContents();
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
    fragmentClients->getBouton2()->setEnabled(true);
    fragmentClients->getBouton3()->setEnabled(true);
    int colonne = 0;
    int rangee = caseSelectionnee.row();
    QModelIndex caseId = fragmentClients->getTableau()->model()->index(rangee, colonne);
    idClient = fragmentClients->getTableau()->model()->data(caseId).toInt();
    emit clientSelectionne(idClient);
}

void ControleurClients::relacherClient() {
    fragmentClients->getTableau()->clearSelection();
    fragmentClients->getBouton2()->setEnabled(false);
    fragmentClients->getBouton3()->setEnabled(false);
    idClient = -1;
    emit clientRelache();
}

void ControleurClients::selectionnerAppareil(QModelIndex caseSelectionnee) {
    fragmentAppareils->getBouton2()->setEnabled(true);
    fragmentAppareils->getBouton3()->setEnabled(true);
    int colonne = 0;
    int rangee = caseSelectionnee.row();
    QModelIndex caseId = fragmentAppareils->getTableau()->model()->index(rangee, colonne);
    idAppareil = fragmentAppareils->getTableau()->model()->data(caseId).toInt();
    emit appareilSelectionne(idAppareil);
}

void ControleurClients::relacherAppareil() {
    fragmentAppareils->getTableau()->clearSelection();
    fragmentAppareils->getBouton2()->setEnabled(false);
    fragmentAppareils->getBouton3()->setEnabled(false);
    idAppareil = -1;
    emit appareilRelache();
}

void ControleurClients::selectionnerFiche(QModelIndex caseSelectionnee) {
    fragmentFiches->getBouton2()->setEnabled(true);
    fragmentFiches->getBouton3()->setEnabled(true);
    int colonne = 0;
    int rangee = caseSelectionnee.row();
    QModelIndex caseId = fragmentAppareils->getTableau()->model()->index(rangee, colonne);
    idFiche = fragmentFiches->getTableau()->model()->data(caseId).toInt();
    emit ficheSelectionnee(idFiche);
}

void ControleurClients::relacherFiche() {
    fragmentFiches->getTableau()->clearSelection();
    fragmentFiches->getBouton2()->setEnabled(false);
    fragmentFiches->getBouton3()->setEnabled(false);
    idFiche = -1;
    emit ficheRelachee();
}
