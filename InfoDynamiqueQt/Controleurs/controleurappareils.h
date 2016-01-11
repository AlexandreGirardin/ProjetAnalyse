#ifndef CONTROLEURAPPAREILS_H
#define CONTROLEURAPPAREILS_H

#include <QObject>

#include "Vues/vueprincipale.h"
#include "Vues/vuefragment.h"
#include "Mappeurs/mappeurappareils.h"
#include "Vues/vuegestionappareil.h"
#include "Vues/vueappareil.h"

class ControleurAppareils : public QObject
{
    Q_OBJECT

    // Contrôle l'exécution de l'onglet Appareils de la vue principale

public:

    /**
     * @brief ControleurAppareils
     * @param vuePrincipale La vue à laquelle se rattache le contrôleur
     * @param parent
     */
    explicit ControleurAppareils(VuePrincipale* vuePrincipale, QObject* parent = 0);

    /**
     * @brief ongletDejaCharge
     * Si l'onglet a déjà été peuplé une première fois
     * Utilisé pour le chargement paresseux initial
     */
    bool ongletDejaCharge;

private:

    // Le fragment des appareils
    VueFragment* fragment;

    // La commande SQL utilisée pour sélectionner les appareils
    const QString* commandeAppareils;

    // La commande SQL utilisée pour chercher des appareils
    const QString* commandeFiltrerAppareils;

    // Assigne les commandes SQL
    void definirCommandes();

    /**
     * @brief mappeur
     */
    MappeurAppareils* mappeur;

    void assignerAppareil(VueAppareil* vue, Appareil* appareil);

public slots:

    /**
     * @brief peuplerAppareils
     * Peuple la table du fragment avec tous les appareils
     */
    void peuplerAppareils();

    /**
     * @brief modifierAppareil
     * Lance la modification de l'appareil sélectionné
     */
    void modifierAppareil();

    /**
     * @brief modifierAppareil
     * Lance la visualisation de l'appareil sélectionné
     */
    void voirAppareil();

    /**
     * @brief filtrerAppareils
     * Filtre les appareils affichés selon la correspondance avec une chaîne
     * @param filtre Critère de filtre à utiliser
     */
    void filtrerAppareils(QString filtre);
};

#endif // CONTROLEURAPPAREILS_H
