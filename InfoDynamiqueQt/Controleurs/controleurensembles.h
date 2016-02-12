#ifndef CONTROLEURGESTIONENSEMBLE_H
#define CONTROLEURGESTIONENSEMBLE_H

#include <QObject>

#include "Vues/vueensemble.h"
#include "Vues/vuegestionensemble.h"

class ControleurEnsembles : public QObject
{
    Q_OBJECT

private:

    /**
     * @brief assignerEnsemble
     * Insère les informations d'un ensemble dans les champs d'une fiche de gestion
     * @param vue La vue cible
     * @param ensemble L'ensemble source
     */
    static void assignerEnsemble(VueGestionEnsemble* vue, const EnsembleActions* ensemble);

    /**
     * @brief assignerEnsemble
     * Insère les informations d'un ensemble dans les champs d'une fiche d'affichage
     * @param vue La vue cible
     * @param ensemble L'ensemble source
     */
    static void assignerEnsemble(VueEnsemble *vue, const EnsembleActions *ensemble);

    /**
     * @brief extraireEnsemble
     * Transfère la valeur des champs d'une vue dans un ensemble
     * @param ensemble L'ensemble cible
     * @param vue La vue source
     */
    static void extraireEnsemble(EnsembleActions* ensemble, const VueGestionEnsemble* vue);

public:

    /**
     * @brief creerEnsemble
     * Lance la création d'un nouvel ensemble
     */
    static void creerEnsemble();

    /**
     * @brief modifierEnsemble
     * Lance l'édition de l'ensemble actuellement sélectionné
     */
    static void modifierEnsemble(const int &idEnsemble);

    /**
     * @brief voirEnsemble
     * Lance la visualisation de l'ensemble donné
     * @param idEnsemble L'id de l'ensemble à afficher
     */
    static void voirEnsemble(const int &idEnsemble);

    /**
     * @brief supprimerEnsemble
     * Lance la suppression de l'ensemble donné
     * @param idEnsemble L'id de l'ensemble à supprimer
     */
    static void supprimerEnsemble(const int &idEnsemble);

};

#endif // CONTROLEURGESTIONENSEMBLE_H
