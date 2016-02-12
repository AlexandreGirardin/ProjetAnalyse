#include "application.h"
#include "Vues/vueprincipale.h"

#include <QDebug>
#include "Mappeurs/mappeuractions.h"

Application::Application(int &argc, char **argv) :
    QApplication(argc, argv)
{
    m_instance = this;
    controleurBD = new ControleurBD(this);
    controleurBD->connecterDossiers();
    bd = controleurBD->getBd();
}

const Application* Application::m_instance = NULL;
VuePrincipale* Application::m_vuePrincipale = NULL;
QSqlDatabase* Application::bd = NULL;
ControleurBD* Application::controleurBD = NULL;

const Application* Application::getInstance()
{
    return m_instance;
}

void Application::demarrer()
{
    creerFenetre();
    chargerOnglet();
    m_vuePrincipale->show();
}

void Application::debug()
{
    QList<Action*>* listeActions = MappeurActions::getActions();
    for (QList<Action*>::const_iterator i = listeActions->constBegin(); i != listeActions->constEnd(); ++i)
    {
        qDebug() << (*i)->out();
    }
}

VuePrincipale* Application::vuePrincipale()
{
    return m_vuePrincipale;
}

void Application::creerFenetre()
{
    m_vuePrincipale = new VuePrincipale();
    controleurClients = new ControleurOngletClients(m_vuePrincipale->ongletClients());
    controleurFiches = new ControleurOngletFiches(m_vuePrincipale->ongletFiches());
    controleurAppareils = new ControleurOngletAppareils(m_vuePrincipale->ongletAppareils());
    controleurActions = new ControleurOngletActions(m_vuePrincipale->ongletActions());
    clientsCharges = false;
    fichesChargees = false;
    appareilsCharges = false;
    actionsChargees = false;
    paresseux = QObject::connect(m_vuePrincipale->onglets(), SIGNAL(currentChanged(int)), this, SLOT(chargerOnglet()));
}

void Application::chargerOnglet()
{
    QWidget* onglet = m_vuePrincipale->onglets()->currentWidget();
    if (onglet == m_vuePrincipale->ongletClients() && !clientsCharges) {
        controleurClients->peuplerClients();
        clientsCharges = true;
    } else if (onglet == m_vuePrincipale->ongletFiches() && !fichesChargees) {
        controleurFiches->peuplerFiches();
        fichesChargees = true;
    } else if (onglet == m_vuePrincipale->ongletAppareils() && !appareilsCharges) {
        controleurAppareils->peuplerAppareils();
        appareilsCharges = true;
    } else if (onglet == m_vuePrincipale->ongletActions() && !actionsChargees) {
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
