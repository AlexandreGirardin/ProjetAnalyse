#include "application.h"
#include "Vues/vueprincipale.h"

#include <QDebug>

Application::Application(int &argc, char **argv) :
    QApplication(argc, argv)
{
    m_instance = this;
    controleurBD = new ControleurBD(this);
    controleurBD->connecterDossiers();
    bd = controleurBD->getBd();
    actions = new MappeurActions(this);
    appareils = new MappeurAppareils(this);
    clients = new MappeurClients(this);
    ensembles = new MappeurEnsembles(this);
    fabricants = new MappeurFabricants(this);
    pieces = new MappeurPieces(this);
    statuts = new MappeurStatuts(this);
    techniciens = new MappeurTechniciens(this);
    typesAppareils = new MappeurTypeAppareils(this);
}

const Application* Application::m_instance = NULL;
VuePrincipale* Application::vuePrincipale = NULL;
QSqlDatabase* Application::bd = NULL;
ControleurBD* Application::controleurBD = NULL;
MappeurActions* Application::actions = NULL;
MappeurAppareils* Application::appareils = NULL;
MappeurClients* Application::clients = NULL;
MappeurEnsembles* Application::ensembles = NULL;
MappeurFabricants* Application::fabricants = NULL;
MappeurPieces* Application::pieces = NULL;
MappeurStatuts* Application::statuts = NULL;
MappeurTechniciens* Application::techniciens = NULL;
MappeurTypeAppareils* Application::typesAppareils = NULL;

const Application* Application::getInstance()
{
    return m_instance;
}

void Application::demarrer()
{
    creerFenetre();
    chargerOnglet();
    vuePrincipale->show();
}

void Application::debug()
{
    QList<Action*>* listeActions = actions->getActions();
    for (QList<Action*>::const_iterator i = listeActions->constBegin(); i != listeActions->constEnd(); ++i)
    {
        qDebug() << (*i)->out();
    }
}

VuePrincipale* Application::getVuePrincipale()
{
    return vuePrincipale;
}

void Application::creerFenetre()
{
    vuePrincipale = new VuePrincipale();
    controleurClients = new ControleurClients(vuePrincipale->getOngletClients());
    controleurFiches = new ControleurFiches(vuePrincipale->getOngletFiches());
    controleurAppareils = new ControleurAppareils(vuePrincipale->getOngletAppareils());
    controleurActions = new ControleurActions(vuePrincipale->getOngletActions());
    clientsCharges = false;
    fichesChargees = false;
    appareilsCharges = false;
    actionsChargees = false;
    paresseux = QObject::connect(vuePrincipale->getOnglets(), SIGNAL(currentChanged(int)), this, SLOT(chargerOnglet()));
}

void Application::chargerOnglet()
{
    QWidget* onglet = vuePrincipale->getOnglets()->currentWidget();
    if (onglet == vuePrincipale->getOngletClients() && !clientsCharges) {
        controleurClients->peuplerClients();
        clientsCharges = true;
    } else if (onglet == vuePrincipale->getOngletFiches() && !fichesChargees) {
        controleurFiches->peuplerFiches();
        fichesChargees = true;
    } else if (onglet == vuePrincipale->getOngletAppareils() && !appareilsCharges) {
        controleurAppareils->peuplerAppareils();
        appareilsCharges = true;
    } else if (onglet == vuePrincipale->getOngletActions() && !actionsChargees) {
        controleurActions->peuplerActions();
        controleurActions->peuplerEnsembles();
        actionsChargees = true;
    }
    verifierParesseux();
}

void Application::verifierParesseux()
{
    if (clientsCharges && fichesChargees && appareilsCharges && actionsChargees) {
        QObject::disconnect(paresseux);
    }
}
