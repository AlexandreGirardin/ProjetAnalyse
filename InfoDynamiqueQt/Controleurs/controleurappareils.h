#ifndef CONTROLEURGESTIONAPPAREIL_H
#define CONTROLEURGESTIONAPPAREIL_H

#include <QObject>

#include "Modeles/appareil.h"
#include "Vues/vueappareil.h"
#include "Vues/vuegestionappareil.h"

class ControleurAppareils : public QObject
{
    Q_OBJECT

    // Contrôle l'exécution de la création, de la lecture et de la mise à jour des appareils

private:

    /**
     * @brief assignerAppareil
     * Insère les informations d'un appareil dans les champs d'une fiche de gestion
     * @param vue La vue cible
     * @param appareil L'appareil source
     */
    static void assignerAppareil(VueGestionAppareil* vue, const Appareil* appareil);

    /**
     * @brief assignerAppareil
     * Insère les informations d'un appareil dans les champs d'une fiche
     * @param vue La vue cible
     * @param appareil L'appareil source
     */
    static void assignerAppareil(VueAppareil* vue, const Appareil* appareil);

    /**
     * @brief extraireAppareil
     * Transfère la valeur des champs d'une vue dans un appareil
     * @param appareil L'appareil cible
     * @param vue La vue source
     */
    static void extraireAppareil(Appareil* appareil, const VueGestionAppareil *vue);

public slots:

    /**
     * @brief ajouterAppareil
     * Lance la création d'un nouvel appareil
     * @param idClient L'id du client
     */
    static void ajouterAppareil(const int &idClient);

    /**
     * @brief modifierAppareil
     * Lance la modification de l'appareil
     * @param idAppareil L'id de l'appareil à modifier
     */
    static void modifierAppareil(const int &idAppareil);

    /**
     * @brief voirAppareil
     * Lance la visualisation de l'appareil
     * @param idAppareil L'id de l'appareil à visualiser
     */
    static void voirAppareil(const int &idAppareil);
};

#endif // CONTROLEURGESTIONAPPAREIL_H
