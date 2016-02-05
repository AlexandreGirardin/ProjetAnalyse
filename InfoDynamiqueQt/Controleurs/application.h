#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

#include "Controleurs/controleurongletactions.h"
#include "Controleurs/controleurappareils.h"
#include "Controleurs/controleurbd.h"
#include "Controleurs/controleurclients.h"
#include "Controleurs/controleurfiches.h"
#include "Controleurs/requetessql.h"

#include "Mappeurs/mappeuractions.h"
#include "Mappeurs/mappeurappareils.h"
#include "Mappeurs/mappeurensembles.h"
#include "Mappeurs/mappeurclients.h"
#include "Mappeurs/mappeurfabricants.h"
#include "Mappeurs/mappeurpieces.h"
#include "Mappeurs/mappeurstatuts.h"
#include "Mappeurs/mappeurtaches.h"
#include "Mappeurs/mappeurtechniciens.h"
#include "Mappeurs/mappeurtypeappareils.h"

#include "Vues/vueprincipale.h"

class Application : public QApplication
{
    Q_OBJECT

public:

    explicit Application(int &argc, char **argv);

    /**
     * @brief getInstance
     * Retourne l'instance de l'application en singleton
     * @return
     */
    static const Application* getInstance();

    /**
     * @brief getVuePrincipale
     * Retourne la fenêtre principale de l'application
     * @return
     */
    static VuePrincipale* vuePrincipale();

    // La base de donnée de l'application
    static QSqlDatabase* bd;

    // Le contrôleur de base de données de l'application
    static ControleurBD* controleurBD;

    // Mappeur d'actions de l'application
    static MappeurActions* actions;

    // Mappeur d'appareils de l'application
    static MappeurAppareils* appareils;

    // Mappeur de clients de l'application
    static MappeurClients* clients;

    // Mappeur d'ensembles d'actions de l'application
    static MappeurEnsembles* ensembles;

    // Mappeur de fabricants de l'application
    static MappeurFabricants* fabricants;

    // Mappeur de pièces de l'application
    static MappeurPieces* pieces;

    // Mappeur de statuts de l'application
    static MappeurStatuts* statuts;

    // Mappeur de techniciens de l'application
    static MappeurTechniciens* techniciens;

    // Mappeurs de types d'appareil de l'application
    static MappeurTypeAppareils* typesAppareils;

    // Démarre l'application
    void demarrer();

    // Imprime des informations pour tester
    void debug();

private:

    // Singleton
    static const Application* m_instance;

    // La vue principale de l'application
    static VuePrincipale* m_vuePrincipale;

    // Le contrôleur de la vue des clients
    ControleurClients* controleurClients;

    // Si l'onglet des clients a été chargé
    bool clientsCharges;

    // Le contrôleur de la vue des fiches
    ControleurFiches* controleurFiches;

    // Si l'onglet des fiches a été chargé
    bool fichesChargees;

    // Le contrôleur de la vue des appareils
    ControleurAppareils* controleurAppareils;

    // Si l'onglet des appareils a été chargé
    bool appareilsCharges;

    // Le contrôleur de la vue des actions
    ControleurOngletActions* controleurActions;

    // Si l'onglet des actions a été chargé
    bool actionsChargees;

    // Connexion prenant en charge le chargement paresseux des onglet
    QMetaObject::Connection paresseux;

    /**
     * @brief verifierParesseux
     * Vérifie si le chargement paresseux est terminé
     */
    void verifierParesseux();

    /**
     * @brief creerFenetre
     * Configure la fenêtre principale de l'application
     */
    void creerFenetre();

    /**
     * @brief executer
     * Lance l'exécution de l'application
     */
    void executer();

public slots:

    /**
     * @brief chargerOnglet
     * Charge l'onglet sélectionné au besoin
     */
    void chargerOnglet();

};

#endif // APPLICATION_H
