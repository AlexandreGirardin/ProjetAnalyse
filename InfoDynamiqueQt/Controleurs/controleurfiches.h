#ifndef CONTROLEURGESTIONFICHE_H
#define CONTROLEURGESTIONFICHE_H

#include <QObject>

#include "Mappeurs/mappeurfiches.h"
#include "Vues/vuegestionfiche.h"

class ControleurFiches : public QObject
{
    Q_OBJECT

    // Contrôle l'exécution de la création, de la lecture et de la mise à jour des fiches

private:

    /**
     * @brief assignerFiche
     * Insère les informations d'une fiche dans les champs d'une fiche de gestion
     * @param vue La vue cible
     * @param fiche La fiche source
     */
    static void assignerFiche(VueGestionFiche* vue, const Fiche* fiche);

    /**
     * @brief extraireClient
     * Transfère la valeur des champs d'une vue dans un client
     * @param client Le client cible
     * @param vue La vue source
     */
    static void extraireFiche(Fiche* fiche, VueGestionFiche const * const vue);

public slots:

    /**
     * @brief ajouterFiche
     * Lance la création d'une nouvelle fiche pour un appareil sélectionné
     * @param idAppareil L'id de l'appareil
     */
    static void ajouterFiche(const int &idAppareil);
};

#endif // CONTROLEURGESTIONFICHE_H
