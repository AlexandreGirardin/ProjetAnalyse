#include "controleurclients.h"
#include "ui_vueprincipale.h"
#include "ui_vuesecondaire.h"

#include <QSqlQueryModel>
#include <QDebug>

ControleurClients::ControleurClients(VuePrincipale *vuePrincipale, QObject *parent) : QObject(parent)
{
    controleurGestionClient = new ControleurGestionClient();
    controleurGestionAppareil = new ControleurGestionAppareil();
    controleurGestionFiche = new ControleurGestionFiche();
    vueSecondaireClients = new VueSecondaire();

    configurerFragmentClients();
    configurerFragmentAppareils();
    configurerFragmentFiches();

    peuplerClients();

    vuePrincipale->getUi()->ongletClients->layout()->addWidget(vueSecondaireClients);
}

void ControleurClients::configurerFragmentClients() {
    fragmentClients = new VueFragment();
    vueSecondaireClients->getUi()->verticalLayout->addWidget(fragmentClients);
    fragmentClients->getEtiquette()->setText("Clients");
    QPushButton* boutonAjouter = fragmentClients->getBouton1();
    boutonAjouter->setText("Ajouter");
    boutonAjouter->setIcon(QIcon::fromTheme("list-add-user"));
    QPushButton* boutonModifier = fragmentClients->getBouton2();
    boutonModifier->setText("Modifier");
    boutonModifier->setIcon(QIcon::fromTheme("document-edit"));
    boutonModifier->setDisabled(true);
    QPushButton* boutonVisualiser = fragmentClients->getBouton3();
    boutonVisualiser->setText("Visualiser");
    boutonVisualiser->setIcon(QIcon::fromTheme("user-properties"));
    boutonVisualiser->setDisabled(true);
    fragmentClients->getCaseCocher()->hide();
    QObject::connect(fragmentClients->getBouton1(), SIGNAL(pressed()), controleurGestionClient, SLOT(ajouterClient()));
}

void ControleurClients::peuplerClients()
{
    QSqlQueryModel* clients = new QSqlQueryModel(this);
    const QSqlDatabase bd = QSqlDatabase::database("dossiers");
    const QString* requete = new QString("SELECT * FROM clients");
    clients->setQuery(*requete, bd);
    fragmentClients->setModele(clients);
}

void ControleurClients::configurerFragmentAppareils() {
    fragmentAppareils = new VueFragment();
    vueSecondaireClients->getUi()->verticalLayout->addWidget(fragmentAppareils);
    fragmentAppareils->getEtiquette()->setText("Appareils");
    QPushButton* boutonAjouter = fragmentAppareils->getBouton1();
    boutonAjouter->setText("Ajouter");
    boutonAjouter->setIcon(QIcon::fromTheme("list-add"));
    QPushButton* boutonModifier = fragmentAppareils->getBouton2();
    boutonModifier->setText("Modifier");
    boutonModifier->setDisabled(true);
    boutonModifier->setIcon(QIcon::fromTheme("document-edit"));
    QPushButton* boutonVisualiser = fragmentAppareils->getBouton3();
    boutonVisualiser->setText("Visualiser");
    boutonVisualiser->setDisabled(true);
    fragmentAppareils->getCaseCocher()->hide();
    fragmentAppareils->setHidden(true);
    QObject::connect(fragmentAppareils->getBouton1(), SIGNAL(pressed()), controleurGestionAppareil, SLOT(ajouterAppareil()));
    QObject::connect(fragmentClients->getTableau(), SIGNAL(clicked(QModelIndex)), this, SLOT(clientSelectionne(QModelIndex)));
}

void ControleurClients::clientSelectionne(QModelIndex index)
{
    int colonne = 0;
    int rangee = index.row();
    QModelIndex index2 = fragmentClients->getTableau()->model()->index(rangee, colonne);
    QVariant id = fragmentClients->getTableau()->model()->data(index2);
    peuplerAppareils(id.toInt());
    fragmentAppareils->show();
    fragmentFiches->hide();
}

void ControleurClients::peuplerAppareils(int idClient)
{
    QSqlQueryModel* appareils = new QSqlQueryModel(this);
    const QSqlDatabase bd = QSqlDatabase::database("dossiers");
    QString requete = "SELECT * FROM appareils WHERE idClient="+QString::number(idClient);
    appareils->setQuery(requete, bd);
    fragmentAppareils->setModele(appareils);
}

void ControleurClients::configurerFragmentFiches() {
    fragmentFiches = new VueFragment();
    vueSecondaireClients->getUi()->verticalLayout->addWidget(fragmentFiches);
    fragmentFiches->getEtiquette()->setText("Fiches");
    QPushButton* boutonAjouter = fragmentFiches->getBouton1();
    boutonAjouter->setText("Ajouter");
    boutonAjouter->setIcon(QIcon::fromTheme("document-new"));
    QPushButton* boutonModifier = fragmentFiches->getBouton2();
    boutonModifier->setText("Modifier");
    boutonModifier->setDisabled(true);
    boutonModifier->setIcon(QIcon::fromTheme("document-edit"));
    QPushButton* boutonVisualiser = fragmentFiches->getBouton3();
    boutonVisualiser->setText("Visualiser");
    boutonVisualiser->setDisabled(true);
    boutonVisualiser->setIcon(QIcon::fromTheme("document-preview"));
    fragmentFiches->getCaseCocher()->setText("Afficher toutes les fiches");
    fragmentFiches->hide();
    QObject::connect(fragmentFiches->getBouton1(), SIGNAL(pressed()), controleurGestionFiche, SLOT(ajouterFiche()));
    QObject::connect(fragmentAppareils->getTableau(), SIGNAL(clicked(QModelIndex)), this, SLOT(afficherFiches(QModelIndex)));
}

void ControleurClients::peuplerFiches(int idAppareil)
{
    QSqlQueryModel* fiches = new QSqlQueryModel(this);
    const QSqlDatabase bd = QSqlDatabase::database("dossiers");
    QString requete = "SELECT * FROM fiches WHERE idAppareil="+QString::number(idAppareil);
    fiches->setQuery(requete, bd);
    fragmentFiches->setModele(fiches);
}

void ControleurClients::afficherFiches(QModelIndex index)
{
    int colonne = 0;
    int rangee = index.row();
    QModelIndex index2 = fragmentAppareils->getTableau()->model()->index(rangee, colonne);
    QVariant id = fragmentAppareils->getTableau()->model()->data(index2);
    peuplerFiches(id.toInt());
    fragmentFiches->show();
}

