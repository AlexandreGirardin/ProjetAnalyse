#ifndef CONTROLEURAPPAREILS_H
#define CONTROLEURAPPAREILS_H

#include <QObject>

#include "Controleurs/controleurappareils.h"
#include "Mappeurs/mappeurappareils.h"
#include "Vues/fragment.h"

class ControleurOngletAppareils : public QObject
{
    Q_OBJECT

    // Contrôle l'exécution de l'onglet Appareils de la vue principale

public:

    /**
     * @brief ControleurAppareils
     * @param vuePrincipale La vue à laquelle se rattache le contrôleur
     * @param parent
     */
    explicit ControleurOngletAppareils(QWidget *vue);

private:

    // Le fragment des appareils
    Fragment* fragment;

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
    void filtrerAppareils(const QString &filtre);

    /**
     * @brief recharger
     * Repeuple le tableau avec filtre de recherche au besoin
     */
    void recharger();

    /**
     * @brief rafraichirActions
     * Repeuple le tableau avec filtre de recherche au besoin et conserve la sélection
     */
    void rafraichir();

signals:

    /**
     * @brief donneesModifiees
     * Lancé lorsque les valeurs du tableau ont été modifiées
     */
    void donneesModifiees();

};

#endif // CONTROLEURAPPAREILS_H
