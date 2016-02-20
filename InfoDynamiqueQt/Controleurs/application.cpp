#include "application.h"
#include "Vues/vueprincipale.h"

#include <QDebug>
#include <QSettings>

const Application* Application::m_instance = NULL;
VuePrincipale* Application::m_vuePrincipale = NULL;
QSqlDatabase* Application::bd = NULL;
ControleurBD* Application::controleurBD = NULL;

Application::Application(int &argc, char **argv) :
    QApplication(argc, argv)
{
    m_instance = this;
}

const Application* Application::getInstance()
{
    return m_instance;
}

void Application::demarrer()
{
    controleurBD = new ControleurBD("dossiers", this);
    chargerParametres();
    creerFenetre();
    connecter();
}

void Application::connecter()
{
    connect(controleurBD, SIGNAL(connexionEtablie()), this, SLOT(ouvrirFenetre()));
    connect(controleurBD, SIGNAL(connexionRatee()), controleurBD, SLOT(connecterDossiers()));
    connect(controleurBD, SIGNAL(annule()), this, SLOT(fermer()));
    controleurBD->connecterDossiers();
}

void Application::ouvrirFenetre()
{
    bd = controleurBD->bd();
    chargerOnglet();
    m_vuePrincipale->show();
}

void Application::chargerParametres()
{
    QCoreApplication::setOrganizationName("InfoDynamique");
    QCoreApplication::setOrganizationDomain("infodynamique.com");
    QCoreApplication::setApplicationName("Dossiers");
}

void Application::sauvegarderParametres()
{
    QSettings parametres;
    parametres.setValue("fenetre/dimensions", m_vuePrincipale->saveGeometry());
}

VuePrincipale* Application::vuePrincipale()
{
    return m_vuePrincipale;
}

void Application::creerFenetre()
{
    QSettings settings;
    m_vuePrincipale = new VuePrincipale();
    m_vuePrincipale->restoreGeometry(settings.value("fenetre/dimensions").toByteArray());
    clientsCharges = false;
    fichesChargees = false;
    appareilsCharges = false;
    actionsChargees = false;
    paresseux = connect(m_vuePrincipale->onglets(), SIGNAL(currentChanged(int)), this, SLOT(chargerOnglet()));
    connect(m_vuePrincipale, SIGNAL(deconnexion()), this, SLOT(deconnexion()));
}

void Application::chargerOnglet()
{
    QWidget* onglet = m_vuePrincipale->onglets()->currentWidget();
    if (onglet == m_vuePrincipale->ongletClients() && !clientsCharges) {
        ongletClients = new ControleurOngletClients(m_vuePrincipale->ongletClients());
        ongletClients->charger(m_vuePrincipale->ongletClients());
        clientsCharges = true;
    } else if (onglet == m_vuePrincipale->ongletFiches() && !fichesChargees) {
        ongletFiches = new ControleurOngletFiches(m_vuePrincipale->ongletFiches());
        ongletFiches->peuplerFiches();
        fichesChargees = true;
    } else if (onglet == m_vuePrincipale->ongletAppareils() && !appareilsCharges) {
        ongletAppareils = new ControleurOngletAppareils(m_vuePrincipale->ongletAppareils());
        ongletAppareils->charger(m_vuePrincipale->ongletAppareils());
        appareilsCharges = true;
    } else if (onglet == m_vuePrincipale->ongletActions() && !actionsChargees) {
        ongletActions = new ControleurOngletActions(m_vuePrincipale->ongletActions());
        ongletActions->charger(m_vuePrincipale->ongletActions());
        actionsChargees = true;
    }
    verifierParesseux();
}

void Application::deconnexion()
{
    sauvegarderParametres();
    m_vuePrincipale->hide();
    controleurBD->fermer();
    controleurBD->deleteLater();
    m_vuePrincipale->deleteLater();
    demarrer();
}

void Application::erreurEcriture(const QString &message)
{
    erreur(tr("Une erreur s'est produite lors de l'écriture:\n")+message, tr("Erreur lors de l'écriture"));
}

void Application::erreurSuppression(const QString &message)
{
    erreur(tr("Une erreur s'est produite lors de la suppression:\n")+message, tr("Erreur lors de la suppression"));
}

void Application::fermer()
{
    controleurBD->fermer();
    m_vuePrincipale->show();
    m_vuePrincipale->deleteLater();
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
