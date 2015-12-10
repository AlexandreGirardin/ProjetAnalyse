#ifndef CONTROLEURCLIENTS_H
#define CONTROLEURCLIENTS_H

#include <QObject>
#include <QSqlQuery>
#include <QSplitter>

#include "Controleurs/controleurgestionclient.h"
#include "Controleurs/controleurgestionappareil.h"
#include "Controleurs/controleurgestionfiche.h"
#include "Vues/vueprincipale.h"
#include "Vues/vuesecondaire.h"
#include "Vues/vuefragment.h"

class ControleurClients : public QObject
{
    Q_OBJECT

public:

    /**
     * @brief ControleurClients
     * @param vuePrincipale
     * @param parent
     */
    explicit ControleurClients(VuePrincipale* vuePrincipale, QObject* parent = 0);

private:

    QSplitter* splitter;

    // Le contrôleur de gestion de clients
    ControleurGestionClient *controleurGestionClient;

    // Le contrôleur de gestion d'appareils
    ControleurGestionAppareil *controleurGestionAppareil;

    // Le contrôleur de gestion de fiches
    ControleurGestionFiche *controleurGestionFiche;

    // La vue secondaire à contrôler
    VueSecondaire *vueSecondaireClients;

    // Le fragment des clients
    VueFragment *fragmentClients;

    // Le numéro de la colonne contenant les id des clients dans fragmentClients
    int colonneIdClients;

    // Le fragment des appareils
    VueFragment *fragmentAppareils;

    // Le numéro de la colonne contenant les id des appareils dans fragmentAppareils
    int colonneIdAppareils;

    // Le fragment des fiches
    VueFragment *fragmentFiches;

    // Le numéro de la colonne contenant les id des fiches dans fragmentFiches
    int colonneIdFiches;

    int idClient;
    int idAppareil;
    int idFiche;

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
     * @brief requeteClients
     * La requête utilisée pour peupler les clients
     */
    const QString* requeteClients;

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

signals:

    /**
     * @brief clientSelectionne
     * Signal émis lorsqu'un client est sélectionné dans fragmentClients
     * @param int L'id du client
     */
    void clientSelectionne(int);

    /**
     * @brief clientRelache
     * Signal émis lorsque le client sélectionné est relâché
     */
    void clientRelache();

    /**
     * @brief appareilSelectionne
     * Signal émis lorsqu'un appareil est sélectionné dans fragmentAppareils
     * @param int L'id de l'appareil
     */
    void appareilSelectionne(int);

    /**
     * @brief appareilRelache
     * Signal émis lorsque l'appareil sélectionné est relâché
     */
    void appareilRelache();

    /**
     * @brief ficheSelectionnee
     * Signal émis lorsqu'une fiche est sélectionnée dans fragmentFiche
     */
    void ficheSelectionnee(int);

    /**
     * @brief ficheRelachee
     * Signal émis lorsque la fiche sélectionnée est relâchée
     * @param int L'id de la fiche
     */
    void ficheRelachee();

public slots:

    /**
     * @brief selectionnerClient
     * Réagit à une sélection de client
     * Émet clientSelectionne
     * @param QModelIndex L'index de la case sélectionnée dans fragmentClients
     */
    void selectionnerClient(QModelIndex);

    /**
     * @brief relacherClient
     * Réagit à une désélection de client
     * Émet clientRelache
     */
    void relacherClient();

    /**
     * @brief peuplerClients
     * Peuple la table du fragmentClients avec tous les clients
     * Émet clientRelache
     */
    void peuplerClients();

    /**
     * @brief selectionnerAppareil
     * Réagit à une sélection d'appareil
     * Émet appareilSelectionne
     * @param QModelIndex L'index de la case sélectionnée dans fragmentAppareils
     */
    void selectionnerAppareil(QModelIndex);

    /**
     * @brief relacherAppareil
     * Réagit à une désélection d'appareil
     * Émet appareilRelache
     */
    void relacherAppareil();

    /**
     * @brief peuplerAppareils
     * Peuple la table de fragmentAppareils avec tous les appareils du client donné
     * Émet appareilRelache
     * @param int L'id du client
     */
    void peuplerAppareils(int idClient);

    /**
     * @brief selectionnerFiche
     * Réagit à une sélection de fiche
     * Émet ficheSelectionnee
     * @param QModelIndex L'index de la case sélectionnée dans fragmentFiches
     */
    void selectionnerFiche(QModelIndex);

    /**
     * @brief relacherFiche
     * Réagit à une désélection de fiche
     * Émet ficheRelachee
     */
    void relacherFiche();

    /**
     * @brief peuplerFiches
     * Peuple la table de fragmentFiches avec toutes les fiches de l'appareil donné
     * Émet ficheRelachee
     * @param int L'id de l'appareil
     */
    void peuplerFiches(int idAppareil);

    /**
     * @brief modifierClient
     */
    void modifierClient();
};

#endif // CONTROLEURCLIENTS_H
