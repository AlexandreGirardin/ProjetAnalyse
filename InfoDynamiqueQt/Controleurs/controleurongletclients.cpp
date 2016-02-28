#include "Controleurs/controleurongletclients.h"

#include "Controleurs/application.h"
#include "Controleurs/requetessql.h"
#include "Controleurs/controleurappareils.h"
#include "Controleurs/controleurclients.h"
#include "Controleurs/controleurfiches.h"
#include "Mappeurs/mappeurappareils.h"
#include "Mappeurs/mappeurfiches.h"
#include <Vues/fragment.h>

#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSplitter>
#include <QSqlQuery>
#include <QSqlQueryModel>

ControleurOngletClients::ControleurOngletClients(QObject* parent) : QObject(parent) {}

void ControleurOngletClients::charger(QWidget* vue) {
    splitter = new QSplitter(Qt::Vertical, vue);
    vue->layout()->addWidget(splitter);
    splitter->setChildrenCollapsible(false);
    configurerFragmentClients();
    configurerFragmentAppareils();
    configurerFragmentFiches();
    fragmentClients->champ()->setFocus();
    peuplerClients();
}

// Configuration

void ControleurOngletClients::configurerFragmentClients()
{
    fragmentClients = new Fragment(splitter);
    fragmentClients->setEtiquette(tr("Clients"));
    fragmentClients->retirerCaseCocher();
    boutonEffacerClient = fragmentClients->ajouterBoutonNonConnecte(4, tr("Effacer"), QIcon(":/Images/edit-delete"));
    boutonEffacerClient->setEnabled(false);
    connect(boutonEffacerClient, SIGNAL(clicked()), this, SLOT(effacerClient()));
    connect(fragmentClients, SIGNAL(selectionValide(bool)), this, SLOT(activerBoutonEffacerClient(bool)));
    connect(fragmentClients, SIGNAL(clicCreer()), this, SLOT(ajouterClient()));
    connect(fragmentClients, SIGNAL(clicEditer()), this, SLOT(modifierClient()));
    connect(fragmentClients, SIGNAL(clicVoir()), this, SLOT(voirClient()));
    connect(fragmentClients, SIGNAL(rechercher(QString)), this, SLOT(filtrerClients(QString)));
    connect(fragmentClients, SIGNAL(doubleClicModele()), this, SLOT(voirClient()));
    connect(Application::get(), SIGNAL(clientModifie()), this, SLOT(rafraichirClients()));
    connect(Application::get(), SIGNAL(nombreAppareilsChange()), this, SLOT(rafraichirClients()));
    connect(Application::get(), SIGNAL(rafraichirTout()), this, SLOT(rechargerClients()));
    connect(Application::get(), SIGNAL(nombreClientsChange()), this, SLOT(rechargerClients()));
}

void ControleurOngletClients::configurerFragmentAppareils()
{
    fragmentAppareils = new Fragment(splitter);
    fragmentAppareils->setEtiquette(tr("Appareils"));
    fragmentAppareils->retirerCaseCocher();
    fragmentAppareils->retirerChamp();
    boutonEffacerAppareil = fragmentAppareils->ajouterBoutonNonConnecte(4, tr("Effacer"), QIcon(":/Images/edit-delete"));
    connect(boutonEffacerAppareil, SIGNAL(clicked()), this, SLOT(effacerAppareil()));
    connect(fragmentAppareils, SIGNAL(selectionValide(bool)), this, SLOT(activerBoutonEffacerAppareil(bool)));
    connect(fragmentAppareils, SIGNAL(clicCreer()), this, SLOT(ajouterAppareil()));
    connect(fragmentAppareils, SIGNAL(clicEditer()), this, SLOT(modifierAppareil()));
    connect(fragmentAppareils, SIGNAL(clicVoir()), this, SLOT(voirAppareil()));
    connect(fragmentAppareils, SIGNAL(doubleClicModele()), this, SLOT(voirAppareil()));
    connect(Application::get(), SIGNAL(appareilModifie()), this, SLOT(rafraichirAppareils()));
    connect(Application::get(), SIGNAL(nombreFichesChange()), this, SLOT(rafraichirAppareils()));
    connect(Application::get(), SIGNAL(nombreAppareilsChange()), this, SLOT(rechargerAppareils()));
    connect(fragmentClients, SIGNAL(modeleSelectionne(int)), this, SLOT(peuplerAppareils(int)));
    connect(fragmentClients, SIGNAL(modeleSelectionne(int)), fragmentAppareils, SLOT(show()));
    connect(fragmentClients, SIGNAL(modeleRelache()), fragmentAppareils, SLOT(relacherModele()));
    connect(fragmentClients, SIGNAL(modeleRelache()), fragmentAppareils, SLOT(hide()));
}

void ControleurOngletClients::configurerFragmentFiches()
{
    fragmentFiches = new Fragment(splitter);
    fragmentFiches->setEtiquette(tr("Fiches"));
    fragmentFiches->setTexteCaseCocher(tr("Afficher toutes les fiches"));
    fragmentFiches->retirerChamp();
    fragmentFiches->boutonModifier()->deleteLater();
    fragmentFiches->boutonVoir()->deleteLater();
    boutonTraiter = fragmentFiches->ajouterBouton(4, tr("Traiter"), QIcon(":/Images/document-edit-sign"));
    connect(fragmentFiches, SIGNAL(clicCreer()), this, SLOT(ajouterFiche()));
    connect(fragmentFiches, SIGNAL(caseCochee()), this, SLOT(desactiverCritereFiches()));
    connect(fragmentFiches, SIGNAL(caseDecochee()), this, SLOT(activerCritereFiches()));
    connect(fragmentFiches, SIGNAL(doubleClicModele()), this, SLOT(traiterFiche()));
    connect(fragmentAppareils, SIGNAL(modeleSelectionne(int)), this, SLOT(peuplerFiches(int)));
    connect(fragmentAppareils, SIGNAL(modeleSelectionne(int)), fragmentFiches, SLOT(show()));
    connect(fragmentAppareils, SIGNAL(modeleRelache()), fragmentFiches, SLOT(relacherModele()));
    connect(fragmentAppareils, SIGNAL(modeleRelache()), fragmentFiches, SLOT(hide()));
    connect(Application::get(), SIGNAL(ficheModifiee()), this, SLOT(rafraichirFiches()));
    connect(Application::get(), SIGNAL(nombreFichesChange()), this, SLOT(rechargerFiches()));
    connect(boutonTraiter, SIGNAL(clicked()), this, SLOT(traiterFiche()));
    fragmentFiches->setCaseCochee(true);
}

// Clients

void ControleurOngletClients::peuplerClients()
{
    QSqlQueryModel* clients = new QSqlQueryModel(this);
    clients->setQuery(*RequetesSQL::afficherClients, *Application::bd);
    fragmentClients->peuplerTableau(clients);
    fragmentClients->cacherColonneId();
}

void ControleurOngletClients::ajouterClient() const
{
    int id = ControleurClients::ajouterClient();
    if (id != -1) {
        fragmentClients->selectionnerModeleParId(id);
    }
}

void ControleurOngletClients::modifierClient() const
{
    if (fragmentClients->idModele() != -1) {
        ControleurClients::modifierClient(fragmentClients->idModele());
    }
}

void ControleurOngletClients::effacerClient() const
{
    if (fragmentClients->idModele() != -1) {
        ControleurClients::effacerClient(fragmentClients->idModele());
    }
}

void ControleurOngletClients::voirClient() const
{
    if (fragmentClients->idModele() != -1) {
        ControleurClients::voirClient(fragmentClients->idModele());
    }
}

void ControleurOngletClients::filtrerClients(const QString &filtre)
{
    if (filtre.isEmpty()) {
        peuplerClients();
    } else {
        QSqlQuery requete = QSqlQuery(*Application::bd);
        requete.prepare(*RequetesSQL::filtrerClients);
        const QString meta = *RequetesSQL::meta;
        requete.bindValue(":filtre", meta + filtre + meta);
        requete.exec();
        QSqlQueryModel* resultats = new QSqlQueryModel(this);
        resultats->setQuery(requete);
        fragmentClients->peuplerTableau(resultats);
        fragmentClients->cacherColonneId();
    }
}

void ControleurOngletClients::activerBoutonEffacerClient(const bool &actif) const
{
    if (!actif) {
        boutonEffacerClient->setEnabled(false);
    } else {
        int usages = MappeurAppareils::nombreAppareils(fragmentClients->idModele());
        if (usages == 0) {
            boutonEffacerClient->setEnabled(true);
            boutonEffacerClient->setToolTip("");
        } else {
            boutonEffacerClient->setEnabled(false);
            boutonEffacerClient->setToolTip("Ce client ne peut pas être supprimé.");
        }
    }
}

void ControleurOngletClients::rechargerClients()
{
    filtrerClients(fragmentClients->filtre());
}

void ControleurOngletClients::rafraichirClients()
{
    int selection = fragmentClients->rangeeSelectionnee();
    rechargerClients();
    fragmentClients->selectionnerRangee(selection);
}

// Appareils

void ControleurOngletClients::peuplerAppareils(const int &idClient)
{
    QSqlQueryModel* appareils = new QSqlQueryModel(this);
    appareils->setQuery(requeteAppareils(idClient));
    fragmentAppareils->peuplerTableau(appareils);
    fragmentAppareils->cacherColonneId();
}

void ControleurOngletClients::ajouterAppareil() const
{
    if (fragmentClients->idModele() != -1) {
        int id = ControleurAppareils::ajouterAppareil(fragmentClients->idModele());
        if (id != -1) {
            fragmentAppareils->selectionnerModeleParId(id);
        }
    }
}

void ControleurOngletClients::modifierAppareil() const
{
    if (fragmentAppareils->idModele() != -1) {
        ControleurAppareils::modifierAppareil(fragmentAppareils->idModele());
    }
}

void ControleurOngletClients::activerBoutonEffacerAppareil(const bool &actif) const
{
    if (!actif) {
        boutonEffacerAppareil->setEnabled(false);
    } else {
        boutonEffacerAppareil->setEnabled(MappeurFiches::nombreFiches(fragmentAppareils->idModele()) == 0);
    }
}

void ControleurOngletClients::effacerAppareil() const
{
    if (fragmentAppareils->idModele() != -1) {
        ControleurAppareils::effacerAppareil(fragmentAppareils->idModele());
    }
}

void ControleurOngletClients::voirAppareil() const
{
    if (fragmentAppareils->idModele() != -1) {
        ControleurAppareils::voirAppareil(fragmentAppareils->idModele());
    }
}

QSqlQuery ControleurOngletClients::requeteAppareils(const int &idClient) const
{
    QSqlQuery requete(*Application::bd);
    requete.prepare(*RequetesSQL::appareilsPourClient);
    requete.bindValue(":idClient", idClient);
    requete.exec();
    return requete;
}

void ControleurOngletClients::rechargerAppareils()
{
    peuplerAppareils(fragmentClients->idModele());
}

void ControleurOngletClients::rafraichirAppareils()
{
    int selection = fragmentAppareils->rangeeSelectionnee();
    rechargerAppareils();
    fragmentAppareils->selectionnerRangee(selection);
}

// Fiches

void ControleurOngletClients::peuplerFiches(const int &idAppareil)
{
    QSqlQueryModel* fiches = new QSqlQueryModel(this);
    fiches->setQuery(requeteFiches(idAppareil));
    fragmentFiches->peuplerTableau(fiches);
}

void ControleurOngletClients::ajouterFiche() const
{
    if (fragmentAppareils->idModele() != -1) {
        int id = ControleurFiches::ajouterFiche(fragmentAppareils->idModele());
        if (id != -1) {
            fragmentFiches->selectionnerModeleParId(id);
        }
    }
}

void ControleurOngletClients::traiterFiche() const
{
    if (fragmentFiches->idModele() != -1) {
        ControleurFiches::traiterFiche(fragmentFiches->idModele());
    }
}

void ControleurOngletClients::activerCritereFiches()
{
    commandeFiches = RequetesSQL::fichesActivesPourAppareil;
    peuplerFiches(fragmentAppareils->idModele());
}

void ControleurOngletClients::desactiverCritereFiches()
{
    commandeFiches = RequetesSQL::toutesFichesPourAppareil;
    peuplerFiches(fragmentAppareils->idModele());
}

QSqlQuery ControleurOngletClients::requeteFiches(const int &idAppareil) const
{
    QSqlQuery requete(*Application::bd);
    requete.prepare(*commandeFiches);
    requete.bindValue(":idAppareil", idAppareil);
    requete.exec();
    return requete;
}

void ControleurOngletClients::rechargerFiches()
{
    peuplerFiches(fragmentAppareils->idModele());
}

void ControleurOngletClients::rafraichirFiches()
{
    int selection = fragmentFiches->rangeeSelectionnee();
    rechargerFiches();
    fragmentFiches->selectionnerRangee(selection);
}
