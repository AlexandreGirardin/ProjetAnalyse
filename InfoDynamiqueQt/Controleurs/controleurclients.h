#ifndef CONTROLEURCLIENTS_H
#define CONTROLEURCLIENTS_H

#include <QObject>

#include "Controleurs/controleurgestionappareil.h"
#include "Controleurs/controleurgestionclient.h"
#include "Controleurs/controleurgestionfiche.h"

#include "Vues/vuefragment.h"
#include "Vues/vueprincipale.h"

#include <QSqlQuery>
#include <QSplitter>

class ControleurClients : public QObject
{
    Q_OBJECT

    // Contrôle l'exécution de l'onglet Clients de la vue principale

public:

    /**
     * @brief ControleurClients
     * @param vuePrincipale La vue à laquelle se rattache le contrôleur
     * @param parent
     */
    explicit ControleurClients(VuePrincipale* vuePrincipale, QObject* parent = 0);

private:

    // Le séparateur redimensionnable contenant les fragments
    QSplitter* splitter;

    // Si l'onglet contrôlé a déjà été activé

    // Le contrôleur de gestion de clients
    ControleurGestionClient* controleurGestionClient;

    // Le contrôleur de gestion d'appareils
    ControleurGestionAppareil* controleurGestionAppareil;

    // Le contrôleur de gestion de fiches
    ControleurGestionFiche* controleurGestionFiche;

    // Le fragment des clients
    VueFragment* fragmentClients;

    // Le fragment des appareils
    VueFragment* fragmentAppareils;

    // Le fragment des fiches
    VueFragment* fragmentFiches;

    /**
     * @brief configurerFragmentClients
     * Configure fragmentClients
     */
    void configurerFragmentClients();

    /**
     * @brief configurerFragmentClients
     * Configure fragmentAppareils
     */
    void configurerFragmentAppareils();

    /**
     * @brief configurerFragmentClients
     * Configure fragmentFiches
     */
    void configurerFragmentFiches();

    // Assigne les commandes SQL
    void definirCommandes();

    // La commande SQL utilisée pour sélectionner les clients
    const QString* commandeClients;

    // La commande SQL utilisée pour sélectionner les appareils
    const QString* commandeAppareils;

    // La commande SQL utilisée pour sélectionner les fiches
    const QString* commandeFiches;

    // La requête utilisée pour chercher des clients
    const QString* commandeFiltreClients;

    /**
     * @brief requeteAppareils
     * @param idClient Le client dont on souhaite afficher les appareils
     * @return La requête utilisée pour peupler les appareils
     */
    QSqlQuery requeteAppareils(int idClient) const;

    /**
     * @brief requeteFiches
     * @param idAppareil L'appareil dont on souhaite afficher les fiches
     * @return La requête utilisée pour peupler les fiches
     */
    QSqlQuery requeteFiches(int idAppareil) const;

public slots:

    /**
     * @brief peuplerClients
     * Peuple la table du fragmentClients avec tous les clients
     */
    void peuplerClients();

    /**
     * @brief peuplerAppareils
     * Peuple la table de fragmentAppareils avec tous les appareils du client donné
     * @param int L'id du client
     */
    void peuplerAppareils(int idClient);

    /**
     * @brief peuplerFiches
     * Peuple la table de fragmentFiches avec toutes les fiches de l'appareil donné
     * @param int L'id de l'appareil
     */
    void peuplerFiches(int idAppareil);

    /**
     * @brief modifierClient
     * Lance la modification du client sélectionné
     */
    void modifierClient();

    /**
     * @brief filtrerClients
     * Filtre les clients affichés selon la correspondance avec une chaîne
     * @param filtre Critère de filtre à utiliser
     */
    void filtrerClients(QString filtre);

private slots:

    /**
     * @brief modifierClient
     * Lance la visualisation du client sélectionné
     */
    void voirClient();

    /**
     * @brief modifierAppareil
     * Lance la visualisation de l'appareil sélectionné
     */
    void voirAppareil();

    /**
     * @brief modifierFiche
     * Lance la visualisation de la fiche sélectionnée
     */
    void voirFiche();
};

#endif // CONTROLEURCLIENTS_H
