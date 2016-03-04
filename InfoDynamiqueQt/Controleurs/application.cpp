#include "application.h"
#include "Vues/vueprincipale.h"

#include "Mappeurs/aidemappeurs.h"
#include "Controleurs/controleurconnexion.h"
#include "Controleurs/controleurongletactions.h"
#include "Controleurs/controleurongletappareils.h"
#include "Controleurs/controleurongletclients.h"
#include "Controleurs/controleurongletfiches.h"

#include <QDateTime>
#include <QPushButton>
#include <QSettings>
#include <QTimer>

Application* Application::m_instance = NULL;
VuePrincipale* Application::m_vuePrincipale = NULL;
QSqlDatabase* Application::bd = NULL;
ControleurConnexion* Application::connexion = NULL;

Application::Application(int &argc, char **argv) :
    QApplication(argc, argv)
{
    m_instance = this;
}

Application* Application::get()
{
    return m_instance;
}

void Application::demarrer()
{
    connexion = new ControleurConnexion("dossiers", this);
    chargerParametres();
    creerFenetre();
    connecter();
}

void Application::connecter()
{
    connect(connexion, SIGNAL(connexionEtablie()), this, SLOT(ouvrirFenetre()));
    connect(connexion, SIGNAL(connexionRatee()), connexion, SLOT(connecterDossiers()));
    connect(connexion, SIGNAL(annule()), this, SLOT(fermer()));
    connexion->connecterDossiers();
}

void Application::ouvrirFenetre()
{
    bd = connexion->bd();
    derniereModification = AideMappeurs::derniereModification();
    chrono = new QTimer(m_vuePrincipale);
    connect(chrono, SIGNAL(timeout()), this, SLOT(verifierModifications()));
    chrono->start(15000);
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
    m_vuePrincipale->hide();
    clientsCharges = false;
    fichesChargees = false;
    appareilsCharges = false;
    actionsChargees = false;
    paresseux = connect(m_vuePrincipale->onglets(), SIGNAL(currentChanged(int)), this, SLOT(chargerOnglet()));
    connect(m_vuePrincipale->getBoutonRecharger(), SIGNAL(clicked()), get(), SLOT(rechargerDonnees()));
    connect(m_instance, SIGNAL(nouvellesModifications()), m_vuePrincipale, SLOT(afficherBoutonRecharger()));
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
    chrono->stop();
    sauvegarderParametres();
    m_vuePrincipale->hide();
    connexion->fermer();
    connexion->deleteLater();
    m_vuePrincipale->deleteLater();
    demarrer();
}

void Application::verifierModifications()
{
    QDateTime* nouvelleDate = AideMappeurs::derniereModification();
    if (derniereModification != NULL && derniereModification->isValid()) {
        if (*nouvelleDate > *derniereModification) {
            delete derniereModification;
            derniereModification = nouvelleDate;
            emit nouvellesModifications();
        }
    }
}

void Application::rechargerDonnees()
{
    emit rafraichirTout();
    m_vuePrincipale->cacherBoutonRecharger();
}

void Application::erreurEcriture(const QString &message)
{
    erreur(tr("Une erreur s'est produite lors de l'écriture:\n")+message, tr("Erreur lors de l'écriture"));
}

void Application::erreurSuppression(const QString &message)
{
    erreur(tr("Une erreur s'est produite lors de la suppression:\n")+message, tr("Erreur lors de la suppression"));
}

void Application::donneesModifiees()
{
    QDateTime* ancienne = &*derniereModification;
    derniereModification = AideMappeurs::derniereModification();
    delete ancienne;
}

void Application::fermer()
{
    connexion->fermer();
    m_vuePrincipale->showMinimized();
    m_vuePrincipale->deleteLater();
}

void Application::erreur(const QString &message, const QString &titre, const QMessageBox::Icon type)
{
    QMessageBox* alerte = new QMessageBox(type, titre, message, QMessageBox::Ok, vuePrincipale());
    alerte->exec();
    alerte->deleteLater();
}

void Application::verifierParesseux()
{
    if (clientsCharges && fichesChargees && appareilsCharges && actionsChargees) {
        disconnect(paresseux);
    }
}
