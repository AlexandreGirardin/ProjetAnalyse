#ifndef CONTROLEURCLIENTS_H
#define CONTROLEURCLIENTS_H

#include <QObject>

class Fragment;

class QPushButton;
class QSplitter;
class QSqlQuery;

class ControleurOngletClients : public QObject
{
    Q_OBJECT

    // Contrôle l'exécution de l'onglet Clients de la vue principale

public:

    /**
     * @brief ControleurClients
     * @param vuePrincipale La vue à laquelle se rattache le contrôleur
     * @param parent
     */
    explicit ControleurOngletClients(QObject* parent = 0);

    /**
     * @brief charger
     * Charge les fragments et les peuple
     * @param vue La vue devant contenir les fragments
     */
    void charger(QWidget* vue);

private:

    // Le séparateur redimensionnable contenant les fragments
    QSplitter* splitter;

    // Le fragment des clients
    Fragment* fragmentClients;

    // Le fragment des appareils
    Fragment* fragmentAppareils;

    // Le fragment des fiches
    Fragment* fragmentFiches;

    // Le bouton de suppression de client
    QPushButton* boutonEffacerClient;

    // Le bouton de suppression d'appareil
    QPushButton* boutonEffacerAppareil;

    // Le bouton de traitement de fiche
    QPushButton* boutonTraiter;

    // Le bouton de visualisation du rapport
    QPushButton* boutonRapport;

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
     * @brief ajouterClient
     * Lance la création d'un nouveau client
     */
    void ajouterClient() const;

    /**
     * @brief modifierClient
     * Lance la modification du client sélectionné
     */
    void modifierClient() const;

    /**
     * @brief effacerClient
     * Lance la suppression du client sélectionné
     * Ne supprime qu'un client qui n'a aucun appareil
     */
    void effacerClient() const;

    /**
     * @brief peuplerAppareils
     * Peuple la table de fragmentAppareils avec tous les appareils du client donné
     * @param int L'id du client
     */
    void peuplerAppareils(const int &idClient);

    /**
     * @brief ajouterAppareil
     * Lance la création d'un appareil pour un client
     * @param idClient L'id du client
     */
    void ajouterAppareil() const;

    /**
     * @brief modifierAppareil
     * Lance la modification de l'appareil sélectionné
     */
    void modifierAppareil() const;

    /**
     * @brief effacerAppareil
     * Lance la suppression de l'appareil sélectionné
     * Ne supprime qu'un appareil qui n'a aucune fiche
     */
    void effacerAppareil() const;

    /**
     * @brief peuplerFiches
     * Peuple la table de fragmentFiches avec toutes les fiches de l'appareil donné
     * @param int L'id de l'appareil
     */
    void peuplerFiches(const int &idAppareil);

    /**
     * @brief ajouterFiche
     * Lance la création d'une fiche pour un appareil
     * @param idAppareil
     */
    void ajouterFiche() const;

    /**
     * @brief traiterFiche
     */
    void traiterFiche() const;

    /**
     * @brief rapportFiche
     */
    void rapportFiche() const;

    /**
     * @brief filtrerClients
     * Filtre les clients affichés selon la correspondance avec une chaîne
     * @param filtre Critère de filtre à utiliser
     */
    void filtrerClients(const QString &filtre);

private slots:

    /**
     * @brief activerBoutonEffacerClient
     * Change l'état du bouton de suppression de client
     * @param actif Si un client est sélectionné
     */
    void activerBoutonEffacerClient(const bool &actif) const;

    /**
     * @brief activerBoutonEffacerAppareil
     * Change l'état du bouton de suppression d'appareil
     * @param actif Si un appareil est sélectionné
     */
    void activerBoutonEffacerAppareil(const bool &actif) const;

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
     * @brief rafraichirClients
     * Recharge les clients en conservant la sélection actuelle
     */
    void rafraichirClients();

    /**
     * @brief rechargerAppareils
     * Repeuple le fragmentAppareils en tenant compte du filtre actuel
     */
    void rechargerAppareils();

    /**
     * @brief rafraichirAppareils
     * Recharge le fragmentAppareils et conserve la sélection
     */
    void rafraichirAppareils();

    /**
     * @brief rechargerFiches
     * Repeuple le fragmentFiches en tenant compte du filtre actuel
     */
    void rechargerFiches();

    /**
     * @brief rafraichirFiches
     * Recharge le fragmentFiches et conserve la sélection
     */
    void rafraichirFiches();
};

#endif // CONTROLEURCLIENTS_H
