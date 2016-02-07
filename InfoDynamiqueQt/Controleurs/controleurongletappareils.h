#ifndef CONTROLEURAPPAREILS_H
#define CONTROLEURAPPAREILS_H

#include <QObject>

#include "Mappeurs/mappeurappareils.h"

#include "Vues/vueappareil.h"
#include "Vues/fragment.h"
#include "Vues/vuegestionappareil.h"
#include "Controleurs/controleurgestionappareil.h"

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
    explicit ControleurAppareils(QWidget *vue);

private:

    // Le contrôleur de gestion d'appareils
    ControleurGestionAppareil* controleurGestionAppareil;

    // Le fragment des appareils
    VueFragment* fragment;

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
    void modifierAppareil() const;

    /**
     * @brief modifierAppareil
     * Lance la visualisation de l'appareil sélectionné
     */
    void voirAppareil() const;

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

signals:

    /**
     * @brief donneesModifiees
     * Lancé lorsque les valeurs du tableau ont été modifiées
     */
    void donneesModifiees();

};

#endif // CONTROLEURAPPAREILS_H
