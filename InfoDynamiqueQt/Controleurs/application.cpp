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
    actions = new MappeurActions(bd, this);
    appareils = new MappeurAppareils(bd, this);
    clients = new MappeurClients(bd, this);
    fabricants = new MappeurFabricants(bd, this);
    pieces = new MappeurPieces(bd, this);
    statuts = new MappeurStatuts(bd, this);
    techniciens = new MappeurTechniciens(bd, this);
    typesAppareils = new MappeurTypeAppareils(bd, this);
}

Application* Application::m_instance = NULL;
VuePrincipale* Application::vuePrincipale = NULL;
QSqlDatabase* Application::bd = NULL;
ControleurBD* Application::controleurBD = NULL;
MappeurActions* Application::actions = NULL;
MappeurAppareils* Application::appareils = NULL;
MappeurClients* Application::clients = NULL;
MappeurFabricants* Application::fabricants = NULL;
MappeurPieces* Application::pieces = NULL;
MappeurStatuts* Application::statuts = NULL;
MappeurTechniciens* Application::techniciens = NULL;
MappeurTypeAppareils* Application::typesAppareils = NULL;

Application* Application::getInstance()
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

VuePrincipale *Application::getVuePrincipale()
{
    return vuePrincipale;
}

void Application::creerFenetre()
{
    vuePrincipale = new VuePrincipale();
    controleurClients = new ControleurClients(vuePrincipale, this);
    controleurFiches = new ControleurFiches(vuePrincipale, this);
    controleurAppareils = new ControleurAppareils(vuePrincipale, this);
    controleurActions = new ControleurActions(vuePrincipale, this);
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
