#ifndef CONTROLEURAPPAREILS_H
#define CONTROLEURAPPAREILS_H

#include <QObject>

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
    explicit ControleurOngletAppareils(QObject *parent = 0);

    /**
     * @brief charger
     * Charge le fragment et le peuple
     * @param vue La vue devant contenir le fragment
     */
    void charger(QWidget *vue);

private:

    // Le fragment des appareils
    Fragment* fragment;

    // Le bouton de suppression d'appareil
    QPushButton* boutonSupprimer;

    /**
     * @brief configurerBoutonSupprimer
     * Configure le bouton de suppression d'appareil
     */
    void configurerBoutonSupprimer();

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

    /**
     * @brief supprimer
     * Lance la suppression de l'appareil sélectionné
     */
    void supprimer() const;

    /**
     * @brief activerBoutonSupprimer
     * Change l'état du bouton de suppression d'appareil
     * @param actif Si un appareil est sélectionné
     */
    void activerBoutonSupprimer(const bool actif);

signals:

    /**
     * @brief donneesModifiees
     * Lancé lorsque les valeurs du tableau ont été modifiées
     */
    void donneesModifiees();

};

#endif // CONTROLEURAPPAREILS_H
