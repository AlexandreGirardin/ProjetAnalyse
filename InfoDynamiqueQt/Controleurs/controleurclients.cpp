#include "controleurclients.h"
#include "ui_vueprincipale.h"
#include "ui_vuesecondaire.h"

#include <QSqlQueryModel>
#include <QDebug>

ControleurClients::ControleurClients(VuePrincipale* vuePrincipale, QObject* parent)
    : QObject(parent) {
    vueSecondaireClients = new VueSecondaire();
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
                      c.telephone as 'Téléphone',\
                      c.adresse as 'Adresse'\
                  from\
                      clients c\
                    left outer join\
                      (select idClient, count(id) as 'nb' from appareils group by idClient) a\
                    on\
                      c.id = a.idClient");

    peuplerClients();
}

void ControleurClients::configurerFragmentClients() {
    fragmentClients = new VueFragment();
    vueSecondaireClients->getUi()->verticalLayout->addWidget(fragmentClients);
    fragmentClients->getEtiquette()->setText("Clients");
    QPushButton* boutonAjouter = fragmentClients->getBouton1();
    boutonAjouter->setIcon(QIcon::fromTheme("list-add-user"));
    QPushButton* boutonModifier = fragmentClients->getBouton2();
    boutonModifier->setIcon(QIcon::fromTheme("document-edit"));
    QPushButton* boutonVisualiser = fragmentClients->getBouton3();
    boutonVisualiser->setIcon(QIcon::fromTheme("user-properties"));
    fragmentClients->getCaseCocher()->hide();
    QObject::connect(fragmentClients->getBouton1(), SIGNAL(pressed()), controleurGestionClient, SLOT(ajouterClient()));
    QObject::connect(fragmentClients->getTableau(), SIGNAL(activated(QModelIndex)), this, SLOT(selectionnerClient(QModelIndex)));
}

void ControleurClients::configurerFragmentAppareils() {
    fragmentAppareils = new VueFragment();
    vueSecondaireClients->getUi()->verticalLayout->addWidget(fragmentAppareils);
    fragmentAppareils->getEtiquette()->setText("Appareils");
    QPushButton* boutonAjouter = fragmentAppareils->getBouton1();
    boutonAjouter->setIcon(QIcon::fromTheme("list-add"));
    QPushButton* boutonModifier = fragmentAppareils->getBouton2();
    boutonModifier->setIcon(QIcon::fromTheme("document-edit"));
    QPushButton* boutonVisualiser = fragmentAppareils->getBouton3();
    boutonVisualiser->setIcon(QIcon::fromTheme("document-preview"));
    fragmentAppareils->getCaseCocher()->hide();
    QObject::connect(boutonAjouter, SIGNAL(pressed()), controleurGestionAppareil, SLOT(ajouterAppareil()));
    QObject::connect(this, SIGNAL(clientSelectionne(int)), this, SLOT(peuplerAppareils(int)));
    QObject::connect(this, SIGNAL(clientSelectionne(int)), fragmentAppareils, SLOT(show()));
    QObject::connect(this, SIGNAL(clientRelache()), this, SLOT(relacherAppareil()));
    QObject::connect(this, SIGNAL(clientRelache()), fragmentAppareils, SLOT(hide()));
    QObject::connect(fragmentAppareils->getTableau(), SIGNAL(pressed(QModelIndex)), this, SLOT(selectionnerAppareil(QModelIndex)));
}

void ControleurClients::configurerFragmentFiches() {
    fragmentFiches = new VueFragment();
    vueSecondaireClients->getUi()->verticalLayout->addWidget(fragmentFiches);
    fragmentFiches->getEtiquette()->setText("Fiches");
    QPushButton* boutonAjouter = fragmentFiches->getBouton1();
    boutonAjouter->setIcon(QIcon::fromTheme("document-new"));
    QPushButton* boutonModifier = fragmentFiches->getBouton2();
    boutonModifier->setIcon(QIcon::fromTheme("document-edit"));
    QPushButton* boutonVisualiser = fragmentFiches->getBouton3();
    boutonVisualiser->setIcon(QIcon::fromTheme("document-preview"));
    fragmentFiches->getCaseCocher()->setText("Afficher toutes les fiches");
    QObject::connect(boutonAjouter, SIGNAL(pressed()), controleurGestionFiche, SLOT(ajouterFiche()));
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

void ControleurClients::peuplerAppareils(int idClient) {
    QSqlQueryModel* appareils = new QSqlQueryModel(this);
    const QSqlDatabase bd = QSqlDatabase::database("dossiers");
    appareils->setQuery(*requeteAppareils(idClient), bd);
    fragmentAppareils->setModele(appareils);
    fragmentAppareils->getTableau()->resizeColumnsToContents();
    relacherAppareil();
}

QString *ControleurClients::requeteAppareils(int idClient) const {
    return new QString("SELECT * FROM appareils WHERE idClient="+QString::number(idClient));
}

void ControleurClients::peuplerFiches(int idAppareil) {
    QSqlQueryModel* fiches = new QSqlQueryModel(this);
    const QSqlDatabase bd = QSqlDatabase::database("dossiers");
    fiches->setQuery(*requeteFiches(idAppareil), bd);
    fragmentFiches->setModele(fiches);
    fragmentFiches->getTableau()->resizeColumnsToContents();
    relacherFiche();
}

QString *ControleurClients::requeteFiches(int idAppareil) const {
    return new QString("SELECT * FROM fiches WHERE idAppareil="+QString::number(idAppareil));
}

void ControleurClients::selectionnerClient(QModelIndex caseSelectionnee) {
    fragmentClients->getBouton2()->setEnabled(true);
    fragmentClients->getBouton3()->setEnabled(true);
    int colonne = 0;
    int rangee = caseSelectionnee.row();
    QModelIndex caseId = fragmentClients->getTableau()->model()->index(rangee, colonne);
    int id = fragmentClients->getTableau()->model()->data(caseId).toInt();
    emit clientSelectionne(id);
}

void ControleurClients::relacherClient() {
    fragmentClients->getTableau()->clearSelection();
    fragmentClients->getBouton2()->setEnabled(false);
    fragmentClients->getBouton3()->setEnabled(false);
    emit clientRelache();
}

void ControleurClients::selectionnerAppareil(QModelIndex caseSelectionnee) {
    fragmentAppareils->getBouton2()->setEnabled(true);
    fragmentAppareils->getBouton3()->setEnabled(true);
    int colonne = 0;
    int rangee = caseSelectionnee.row();
    QModelIndex caseId = fragmentAppareils->getTableau()->model()->index(rangee, colonne);
    int id = fragmentAppareils->getTableau()->model()->data(caseId).toInt();
    emit appareilSelectionne(id);
}

void ControleurClients::relacherAppareil() {
    fragmentAppareils->getTableau()->clearSelection();
    fragmentAppareils->getBouton2()->setEnabled(false);
    fragmentAppareils->getBouton3()->setEnabled(false);
    emit appareilRelache();
}

void ControleurClients::selectionnerFiche(QModelIndex caseSelectionnee) {
    fragmentFiches->getBouton2()->setEnabled(true);
    fragmentFiches->getBouton3()->setEnabled(true);
    int colonne = 0;
    int rangee = caseSelectionnee.row();
    QModelIndex caseId = fragmentAppareils->getTableau()->model()->index(rangee, colonne);
    int id = fragmentFiches->getTableau()->model()->data(caseId).toInt();
    emit ficheSelectionnee(id);
}

void ControleurClients::relacherFiche() {
    fragmentFiches->getTableau()->clearSelection();
    fragmentFiches->getBouton2()->setEnabled(false);
    fragmentFiches->getBouton3()->setEnabled(false);
    emit ficheRelachee();
}
