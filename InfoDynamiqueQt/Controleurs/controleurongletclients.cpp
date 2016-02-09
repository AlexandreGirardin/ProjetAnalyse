#include "Controleurs/controleurongletclients.h"

#include "Controleurs/application.h"
#include "Controleurs/requetessql.h"

#include <QDebug>
#include <QLayout>
#include <QSqlQueryModel>

ControleurClients::ControleurClients(QWidget* vue)
    : QObject(vue)
{
    splitter = new QSplitter(Qt::Vertical, vue);
    vue->layout()->addWidget(splitter);
    splitter->setChildrenCollapsible(false);
    configurerFragmentClients();
    configurerFragmentAppareils();
    configurerFragmentFiches();
    fragmentClients->champ()->setFocus();
}

// Configuration

void ControleurClients::configurerFragmentClients()
{
    fragmentClients = new Fragment(splitter);
    fragmentClients->setEtiquette(tr("Clients"));
    fragmentClients->retirerCaseCocher();
    controleurGestionClient = new ControleurGestionClient(fragmentClients);
    QObject::connect(fragmentClients, SIGNAL(clicCreer()), controleurGestionClient, SLOT(ajouterClient()));
    QObject::connect(fragmentClients, SIGNAL(clicEditer()), this, SLOT(modifierClient()));
    QObject::connect(fragmentClients, SIGNAL(clicVoir()), this, SLOT(voirClient()));
    QObject::connect(fragmentClients, SIGNAL(rechercher(QString)), this, SLOT(filtrerClients(QString)));
    QObject::connect(fragmentClients, SIGNAL(doubleClicModele()), this, SLOT(voirClient()));
    QObject::connect(controleurGestionClient, SIGNAL(donneesModifiees()), this, SLOT(rechargerClients()));
}

void ControleurClients::configurerFragmentAppareils()
{
    fragmentAppareils = new Fragment(splitter);
    fragmentAppareils->setEtiquette(tr("Appareils"));
    fragmentAppareils->retirerCaseCocher();
    fragmentAppareils->retirerChamp();
    controleurGestionAppareil = new ControleurGestionAppareil(fragmentAppareils);
    QObject::connect(fragmentAppareils, SIGNAL(clicCreer()), this, SLOT(ajouterAppareil()));
    QObject::connect(fragmentAppareils, SIGNAL(clicEditer()), this, SLOT(modifierAppareil()));
    QObject::connect(fragmentAppareils, SIGNAL(clicVoir()), this, SLOT(voirAppareil()));
    QObject::connect(fragmentAppareils, SIGNAL(doubleClicModele()), this, SLOT(voirAppareil()));
    QObject::connect(controleurGestionAppareil, SIGNAL(donneesModifiees()), this, SLOT(rechargerAppareils()));
    QObject::connect(controleurGestionAppareil, SIGNAL(nombreAppareilsChange(int)), this, SLOT(rechargerNombreAppareils()));
    QObject::connect(fragmentClients, SIGNAL(modeleSelectionne(int)), this, SLOT(peuplerAppareils(int)));
    QObject::connect(fragmentClients, SIGNAL(modeleSelectionne(int)), fragmentAppareils, SLOT(show()));
    QObject::connect(fragmentClients, SIGNAL(modeleRelache()), fragmentAppareils, SLOT(relacherModele()));
    QObject::connect(fragmentClients, SIGNAL(modeleRelache()), fragmentAppareils, SLOT(hide()));
}

void ControleurClients::configurerFragmentFiches()
{
    commandeFiches = RequetesSQL::toutesFichesPourAppareil;
    fragmentFiches = new Fragment(splitter);
    fragmentFiches->setEtiquette(tr("Fiches"));
    fragmentFiches->caseCocher()->setChecked(true);
    fragmentFiches->caseCocher()->setText(tr("Afficher toutes les fiches"));
    fragmentFiches->retirerChamp();
    controleurGestionFiche = new ControleurGestionFiche(fragmentFiches);
    QObject::connect(fragmentFiches, SIGNAL(clicCreer()), this, SLOT(ajouterFiche()));
    QObject::connect(fragmentFiches, SIGNAL(clicEditer()), this, SLOT(modifierFiche()));
    QObject::connect(fragmentFiches, SIGNAL(caseCochee()), this, SLOT(desactiverCritereFiches()));
    QObject::connect(fragmentFiches, SIGNAL(caseDecochee()), this, SLOT(activerCritereFiches()));
    QObject::connect(fragmentFiches, SIGNAL(doubleClicModele()), this, SLOT(voirFiche()));
    QObject::connect(fragmentAppareils, SIGNAL(modeleSelectionne(int)), this, SLOT(peuplerFiches(int)));
    QObject::connect(fragmentAppareils, SIGNAL(modeleSelectionne(int)), fragmentFiches, SLOT(show()));
    QObject::connect(fragmentAppareils, SIGNAL(modeleRelache()), fragmentFiches, SLOT(relacherModele()));
    QObject::connect(fragmentAppareils, SIGNAL(modeleRelache()), fragmentFiches, SLOT(hide()));
}

// Clients

void ControleurClients::peuplerClients()
{
    QSqlQueryModel* clients = new QSqlQueryModel(this);
    clients->setQuery(*RequetesSQL::afficherClients, *Application::bd);
    fragmentClients->peuplerTableau(clients);
    fragmentClients->getTableau()->hideColumn(fragmentClients->getColonneId());
}

void ControleurClients::modifierClient() const
{
    if (fragmentClients->getIdModele() != -1) {
        controleurGestionClient->modifierClient(fragmentClients->getIdModele());
    }
}

void ControleurClients::voirClient() const
{
    if (fragmentClients->getIdModele() != -1) {
        controleurGestionClient->voirClient(fragmentClients->getIdModele());
    }
}

void ControleurClients::filtrerClients(const QString &filtre)
{
    if (filtre.isEmpty()) {
        peuplerClients();
    } else {
        QSqlQuery requete = QSqlQuery(*Application::bd);
        requete.prepare(*RequetesSQL::filtrerClients);
        const QString meta = *ControleurBD::meta;
        requete.bindValue(":filtre", meta + filtre + meta);
        requete.exec();
        QSqlQueryModel* resultats = new QSqlQueryModel(this);
        resultats->setQuery(requete);
        fragmentClients->peuplerTableau(resultats);
        fragmentClients->getTableau()->hideColumn(fragmentClients->getColonneId());
    }
}

void ControleurClients::rechargerClients()
{
    filtrerClients(fragmentClients->getFiltre());
}

// Appareils

void ControleurClients::peuplerAppareils(const int &idClient)
{
    QSqlQueryModel* appareils = new QSqlQueryModel(this);
    appareils->setQuery(requeteAppareils(idClient));
    fragmentAppareils->peuplerTableau(appareils);
    fragmentAppareils->getTableau()->hideColumn(fragmentAppareils->getColonneId());
}

void ControleurClients::ajouterAppareil() const
{
    if (fragmentClients->getIdModele() != -1) {
        controleurGestionAppareil->ajouterAppareil(fragmentClients->getIdModele());
    }
}

void ControleurClients::modifierAppareil() const
{
    if (fragmentAppareils->getIdModele() != -1) {
        controleurGestionAppareil->modifierAppareil(fragmentAppareils->getIdModele());
    }
}

void ControleurClients::voirAppareil() const
{
    if (fragmentAppareils->getIdModele() != -1) {
        controleurGestionAppareil->voirAppareil(fragmentAppareils->getIdModele());
    }
}

QSqlQuery ControleurClients::requeteAppareils(const int &idClient) const
{
    QSqlQuery requete = QSqlQuery(*Application::bd);
    requete.prepare(*RequetesSQL::appareilsPourClient);
    requete.bindValue(":idClient", idClient);
    requete.exec();
    return requete;
}

void ControleurClients::filtrerAppareils(const QString &filtre)
{
    if (filtre.isEmpty()) {
        peuplerAppareils(fragmentClients->getIdModele());
    } else {
        QSqlQuery requete = QSqlQuery(*Application::bd);
        requete.prepare(*RequetesSQL::filtrerAppareils);
        const QString meta = *ControleurBD::meta;
        requete.bindValue(":filtre", meta + filtre + meta);
        requete.exec();
        QSqlQueryModel* resultats = new QSqlQueryModel(this);
        resultats->setQuery(requete);
        fragmentAppareils->peuplerTableau(resultats);
        fragmentAppareils->getTableau()->hideColumn(fragmentAppareils->getColonneId());
    }
}

void ControleurClients::rechargerAppareils()
{
    filtrerAppareils("");
}

void ControleurClients::rechargerNombreAppareils()
{
    int dernierIndex = fragmentClients->getDernierIndexSelectionne();
    rechargerClients();
    fragmentClients->getTableau()->selectRow(dernierIndex);
}

// Fiches

void ControleurClients::peuplerFiches(const int &idAppareil)
{
    QSqlQueryModel* fiches = new QSqlQueryModel(this);
    fiches->setQuery(requeteFiches(idAppareil));
    fragmentFiches->peuplerTableau(fiches);
    fragmentFiches->getTableau()->hideColumn(fragmentFiches->getColonneId());
}

void ControleurClients::ajouterFiche() const
{
    if (fragmentAppareils->getIdModele() != -1) {
        controleurGestionFiche->ajouterFiche(fragmentAppareils->getIdModele());
    }
}

void ControleurClients::modifierFiche() const
{
    if (fragmentFiches->getIdModele() != -1) {
        controleurGestionFiche->modifierFiche(fragmentFiches->getIdModele());
    }
}

void ControleurClients::voirFiche() const
{
    if (fragmentFiches->getIdModele() != -1) {
        controleurGestionFiche->modifierFiche(fragmentFiches->getIdModele());
    }
}

void ControleurClients::activerCritereFiches()
{
    commandeFiches = RequetesSQL::fichesActivesPourAppareil;
    peuplerFiches(fragmentAppareils->getIdModele());
}

void ControleurClients::desactiverCritereFiches()
{
    commandeFiches = RequetesSQL::toutesFichesPourAppareil;
    peuplerFiches(fragmentAppareils->getIdModele());
}

QSqlQuery ControleurClients::requeteFiches(const int &idAppareil) const
{
    QSqlQuery requete = QSqlQuery(*Application::bd);
    requete.prepare(*commandeFiches);
    requete.bindValue(":idAppareil", idAppareil);
    requete.exec();
    return requete;
}
