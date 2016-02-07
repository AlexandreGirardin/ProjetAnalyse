#ifndef CONTROLEURCLIENTS_H
#define CONTROLEURCLIENTS_H

#include <QObject>

#include "Controleurs/controleurgestionappareil.h"
#include "Controleurs/controleurgestionclient.h"
#include "Controleurs/controleurgestionfiche.h"
#include "Vues/fragment.h"

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
    explicit ControleurClients(QWidget* vue);

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
    Fragment* fragmentClients;

    // Le fragment des appareils
    Fragment* fragmentAppareils;

    // Le fragment des fiches
    Fragment* fragmentFiches;

    // La commande SQL actuelle servant à peupler le fragmentFiches
    const QString* commandeFiches;

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

    /**
     * @brief requeteAppareils
     * @param idClient Le client dont on souhaite afficher les appareils
     * @return La requête utilisée pour peupler les appareils
     */
    QSqlQuery requeteAppareils(const int &idClient) const;

    /**
     * @brief requeteFiches
     * @param idAppareil L'appareil dont on souhaite afficher les fiches
     * @return La requête utilisée pour peupler les fiches
     */
    QSqlQuery requeteFiches(const int &idAppareil) const;

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
    void peuplerAppareils(const int &idClient);

    /**
     * @brief peuplerFiches
     * Peuple la table de fragmentFiches avec toutes les fiches de l'appareil donné
     * @param int L'id de l'appareil
     */
    void peuplerFiches(const int &idAppareil);

    /**
     * @brief ajouterAppareil
     * Lance la création d'un appareil pour un client
     * @param idClient L'id du client
     */
    void ajouterAppareil() const;

    /**
     * @brief ajouterFiche
     * Lance la création d'une fiche pour un appareil
     * @param idAppareil
     */
    void ajouterFiche() const;

    /**
     * @brief modifierClient
     * Lance la modification du client sélectionné
     */
    void modifierClient() const;

    /**
     * @brief modifierAppareil
     * Lance la modification de l'appareil sélectionné
     */
    void modifierAppareil() const;

    /**
     * @brief modifierFiche
     * Lance la modification de la fiche sélectionné
     */
    void modifierFiche() const;

    /**
     * @brief filtrerClients
     * Filtre les clients affichés selon la correspondance avec une chaîne
     * @param filtre Critère de filtre à utiliser
     */
    void filtrerClients(const QString &filtre);


    /**
     * @brief filtrerAppareils
     * Filtre les appareils affichés selon la correspondance avec une chaîne
     * @param filtre Critère de filtre à utiliser
     */
    void filtrerAppareils(const QString &filtre);

private slots:

    /**
     * @brief modifierClient
     * Lance la visualisation du client sélectionné
     */
    void voirClient() const;

    /**
     * @brief modifierAppareil
     * Lance la visualisation de l'appareil sélectionné
     */
    void voirAppareil() const;

    /**
     * @brief modifierFiche
     * Lance la visualisation de la fiche sélectionnée
     */
    void voirFiche() const;

    /**
     * @brief activerCritereActions
     * Réassigne les commandes SQL pour n'afficher que les fiches actives
     */
    void activerCritereFiches();

    /**
     * @brief activerCritereActions
     * Réassigne les commandes SQL pour afficher toutes les fiches
     */
    void desactiverCritereFiches();

    /**
     * @brief rechargerClients
     */
    void rechargerClients();

    /**
     * @brief rechargerAppareils
     * Repeuple le fragmentAppareils en tenant compte du filtre actuel
     */
    void rechargerAppareils();

    void rechargerNombreAppareils(const int &idClient);
};

#endif // CONTROLEURCLIENTS_H
