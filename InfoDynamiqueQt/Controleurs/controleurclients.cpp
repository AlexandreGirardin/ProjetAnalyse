#include "Controleurs/controleurclients.h"
#include "ui_vueprincipale.h"

#include "Controleurs/controleurbd.h"

#include <QSqlQueryModel>

ControleurClients::ControleurClients(VuePrincipale* vuePrincipale, QObject* parent)
    : QObject(parent) {
    splitter = new QSplitter(Qt::Vertical, vuePrincipale->getUi()->ongletClients);
    vuePrincipale->getUi()->ongletClients->layout()->addWidget(splitter);
    splitter->setChildrenCollapsible(false);
    controleurGestionClient = new ControleurGestionClient();
    controleurGestionAppareil = new ControleurGestionAppareil();
    controleurGestionFiche = new ControleurGestionFiche();
    configurerFragmentClients();
    configurerFragmentAppareils();
    configurerFragmentFiches();
    definirCommandes();
}

void ControleurClients::configurerFragmentClients() {
    fragmentClients = new VueFragment(splitter);
    fragmentClients->getEtiquette()->setText(tr("Clients"));
    fragmentClients->getCaseCocher()->hide();
    QObject::connect(fragmentClients, SIGNAL(clicCreer()), controleurGestionClient, SLOT(ajouterClient()));
    QObject::connect(fragmentClients, SIGNAL(clicEditer()), this, SLOT(modifierClient()));
    QObject::connect(fragmentClients, SIGNAL(clicVoir()), this, SLOT(voirClient()));
    QObject::connect(fragmentClients, SIGNAL(rechercher(QString)), this, SLOT(filtrerClients(QString)));

}

void ControleurClients::configurerFragmentAppareils() {
    fragmentAppareils = new VueFragment(splitter);
    fragmentAppareils->getEtiquette()->setText(tr("Appareils"));
    fragmentAppareils->getCaseCocher()->hide();
    fragmentAppareils->getChamp()->hide();
    QObject::connect(fragmentAppareils, SIGNAL(clicCreer()), controleurGestionAppareil, SLOT(ajouterAppareil()));
    QObject::connect(fragmentClients, SIGNAL(modeleSelectionne(int)), this, SLOT(peuplerAppareils(int)));
    QObject::connect(fragmentClients, SIGNAL(modeleRelache()), fragmentAppareils, SLOT(relacherModele()));
    QObject::connect(fragmentClients, SIGNAL(modeleSelectionne(int)), fragmentAppareils, SLOT(show()));
    QObject::connect(fragmentClients, SIGNAL(modeleRelache()), fragmentAppareils, SLOT(hide()));
}

void ControleurClients::configurerFragmentFiches() {
    fragmentFiches = new VueFragment(splitter);
    fragmentFiches->getEtiquette()->setText(tr("Fiches"));
    fragmentFiches->getCaseCocher()->setText(tr("Afficher toutes les fiches"));
    fragmentFiches->getChamp()->hide();
    QObject::connect(fragmentFiches, SIGNAL(clicCreer()), controleurGestionFiche, SLOT(ajouterFiche()));
    QObject::connect(fragmentAppareils, SIGNAL(modeleSelectionne(int)), this, SLOT(peuplerFiches(int)));
    QObject::connect(fragmentAppareils, SIGNAL(modeleRelache()), fragmentFiches, SLOT(relacherModele()));
    QObject::connect(fragmentAppareils, SIGNAL(modeleSelectionne(int)), fragmentFiches, SLOT(show()));
    QObject::connect(fragmentAppareils, SIGNAL(modeleRelache()), fragmentFiches, SLOT(hide()));
}

void ControleurClients::definirCommandes() {
    commandeClients = new QString(
                "SELECT\
                      c.id AS '#',\
                      c.telephone AS 'Téléphone',\
                      COALESCE(a.nb,0) AS 'Nb. appareils',\
                      c.nom AS 'Nom'\
                 FROM\
                      clients c\
                 LEFT OUTER JOIN\
                      (select idClient, count(id) as 'nb' from appareils group by idClient) a\
                 ON\
                      c.id = a.idClient");
    commandeFiltreClients = new QString (*commandeClients +
                                        QString(" WHERE c.id LIKE :filtre\
                                                OR c.nom LIKE :filtre\
                                                OR c.telephone LIKE :filtre\
                                                OR c.adresse LIKE :filtre"));
    commandeAppareils = new QString ("SELECT * FROM appareils WHERE idClient=:idClient");
    commandeFiches = new QString("SELECT * FROM fiches WHERE idAppareil=:idAppareil");
}

void ControleurClients::peuplerClients() {
    QSqlQueryModel* clients = new QSqlQueryModel(this);
    const QSqlDatabase bd = QSqlDatabase::database(ControleurBD::nomBd());
    clients->setQuery(*commandeClients, bd);
    fragmentClients->peuplerTableau(clients);
    fragmentClients->getTableau()->hideColumn(0);
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

void ControleurClients::filtrerClients(QString filtre) {
    if (filtre.isEmpty()) {
        peuplerClients();
    } else {
        QSqlQuery requete = QSqlQuery(QSqlDatabase::database(ControleurBD::nomBd()));
        requete.prepare(*commandeFiltreClients);
        const QString* meta = ControleurBD::meta();
        requete.bindValue(":filtre", *meta + filtre + *meta);
        requete.exec();
        QSqlQueryModel* resultats = new QSqlQueryModel(this);
        resultats->setQuery(requete);
        fragmentClients->peuplerTableau(resultats);
        fragmentClients->getTableau()->hideColumn(0);
    }
}

// Requêtes SQL

QSqlQuery ControleurClients::requeteAppareils(int idClient) const {
    QSqlQuery requete = QSqlQuery(QSqlDatabase::database(ControleurBD::nomBd()));
    requete.prepare(*commandeAppareils);
    requete.bindValue(":idClient", idClient);
    requete.exec();
    return requete;
}

QSqlQuery ControleurClients::requeteFiches(int idAppareil) const {
    QSqlQuery requete = QSqlQuery(QSqlDatabase::database(ControleurBD::nomBd()));
    requete.prepare(*commandeFiches);
    requete.bindValue(":idAppareil", idAppareil);
    requete.exec();
    return requete;
}
