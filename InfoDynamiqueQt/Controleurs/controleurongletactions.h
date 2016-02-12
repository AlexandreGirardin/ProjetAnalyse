#ifndef CONTROLEURONGLETACTIONS_H
#define CONTROLEURONGLETACTIONS_H

#include <QObject>

#include "Controleurs/controleuractions.h"
#include "Controleurs/controleurensembles.h"
#include "Vues/fragment.h"

#include <QSplitter>

class ControleurOngletActions : public QObject
{
    Q_OBJECT

public:

    explicit ControleurOngletActions(QWidget *parent = 0);

    /**
     * @brief configurerFragmentActions
     * Configure et connecte le fragment de gestion des actions
     */
    void configurerFragmentActions();

    /**
     * @brief configurerFragmentEnsembles
     * Configure et connecte le fragment de gestion des actions
     */
    void configurerFragmentEnsembles();

    /**
     * @brief splitter
     * Permet aux fragments d'êtres redimensionnéss
     */
    QSplitter* splitter;

    // Vue permettant de contrôleur les actions
    Fragment* fragmentActions;

    // Vue permettant de contrôler les ensembles
    Fragment* fragmentEnsembles;

    // La requête SQL actuelle pour actions sans filtre de recherche
    const QString* requeteActions;

    // La requête SQL actuelle pour actions avec filtre de recherche
    const QString* requeteActionsFiltre;

public slots:

    /**
     * @brief rechargerActions
     * Repeuple les actions en tenant compte du filtre actuel
     */
    void rechargerActions();

    /**
     * @brief peuplerActions
     * Peuple le fragmentAction sans filtre
     */
    void peuplerActions();

    /**
     * @brief filtrerActions
     * Peuple le fragmentAction en utilisant le filtre donné
     * @param filtre Le filtre à utiliser
     */
    void filtrerActions(const QString &filtre);

    /**
     * @brief creerAction
     * Lance la création d'une nouvelle action
     */
    void creerAction();

    /**
     * @brief modifierAction
     * Lance la modification de l'action sélectionnée
     */
    void modifierAction();

    /**
     * @brief voirAction
     * Lance la visualisation de l'action sélectionnée
     */
    void voirAction();

    /**
     * @brief changerEtatAction
     * Inverse l'état de la tâche sélectionnée
     */
    void changerEtatAction();

    /**
     * @brief activerCritereActions
     * Fait en sorte que seules les actions actives soient affichées
     */
    void activerCritereActions();

    /**
     * @brief desactiverCritereActions
     * Fait en sorte que toutes les actions, actives ou non, soient affichées
     */
    void desactiverCritereActions();

    /**
     * @brief rechargerEnsembles
     * Repeuple les ensembles en tenant compte du filtre actuel
     */
    void rechargerEnsembles();

    /**
     * @brief peuplerEnsembles
     * Peuple le fragmentEnsembles sans filtre
     */
    void peuplerEnsembles();

    /**
     * @brief filtrerEnsembles
     * Peuple le fragmentEnsembles en utilisant le filtre donné
     * @param filtre Le filtre à utiliser
     */
    void filtrerEnsembles(const QString &filtre);

    /**
     * @brief creerEnsemble
     * Lance la création d'un nouvel ensemble
     */
    void creerEnsemble();

    /**
     * @brief modifierEnsemble
     * Lance la modification de l'ensemble sélectionné
     */
    void modifierEnsemble();

    /**
     * @brief voirEnsemble
     * Lance la visualisation de l'ensemble sélectionné
     */
    void voirEnsemble();

    /**
     * @brief supprimerEnsemble
     * Lance la suppression de l'ensemble sélectionné
     */
    void supprimerEnsemble();
};

#endif // CONTROLEURONGLETACTIONS_H
