#include "application.h"
#include "Vues/vueprincipale.h"

#include <QDebug>
#include "Mappeurs/mappeuractions.h"

Application::Application(int &argc, char **argv) :
    QApplication(argc, argv)
{
    m_instance = this;
    controleurBD = new ControleurBD(this);
}

const Application* Application::m_instance = NULL;

VuePrincipale* Application::m_vuePrincipale = NULL;

QSqlDatabase* Application::bd = NULL;

ControleurBD* Application::controleurBD = NULL;

const Application* Application::getInstance()
{
    return m_instance;
}

void Application::connecter()
{
    QObject::connect(controleurBD, SIGNAL(connexionEtablie()), this, SLOT(demarrer()));
    QObject::connect(controleurBD, SIGNAL(connexionRatee()), controleurBD, SLOT(connecterDossiers()));
    controleurBD->connecterDossiers();
}

void Application::demarrer()
{
    bd = controleurBD->bd();
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
    ongletClients = new ControleurOngletClients(m_vuePrincipale->ongletClients());
    ongletFiches = new ControleurOngletFiches(m_vuePrincipale->ongletFiches());
    ongletAppareils = new ControleurOngletAppareils(m_vuePrincipale->ongletAppareils());
    ongletActions = new ControleurOngletActions(m_vuePrincipale->ongletActions());
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
        ongletClients->charger(m_vuePrincipale->ongletClients());
        clientsCharges = true;
    } else if (onglet == m_vuePrincipale->ongletFiches() && !fichesChargees) {
        ongletFiches->peuplerFiches();
        fichesChargees = true;
    } else if (onglet == m_vuePrincipale->ongletAppareils() && !appareilsCharges) {
        ongletAppareils->charger(m_vuePrincipale->ongletAppareils());
        appareilsCharges = true;
    } else if (onglet == m_vuePrincipale->ongletActions() && !actionsChargees) {
        ongletActions->charger(m_vuePrincipale->ongletActions());
        actionsChargees = true;
    }
    verifierParesseux();
}

void Application::erreurEcriture(const QString &message)
{
    erreur(tr("Une erreur s'est produite lors de l'écriture:\n")+message, tr("Erreur lors de l'écriture"));
}

void Application::erreurSuppression(const QString &message)
{
    erreur(tr("Une erreur s'est produite lors de la suppression:\n")+message, tr("Erreur lors de la suppression"));
}

void Application::erreur(const QString &message, const QString &titre, QMessageBox::Icon type)
{
    QMessageBox* alerte = new QMessageBox(type, titre, message, QMessageBox::Ok, vuePrincipale());
    alerte->exec();
    alerte->deleteLater();
}

void Application::verifierParesseux()
{
    if (clientsCharges && fichesChargees && appareilsCharges && actionsChargees) {
        QObject::disconnect(paresseux);
    }
}
