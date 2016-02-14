#ifndef CONTROLEURACTIONS_H
#define CONTROLEURACTIONS_H

#include <QObject>

#include "Modeles/action.h"
#include "Vues/vuegestionaction.h"

class ControleurActions : public QObject
{
    Q_OBJECT

    // Contrôle la gestion (création, modification, suppression) des actions

private:

    /**
     * @brief assignerAction
     * Assigne les informations de l'action dans les champs de la vue
     * @param vue La vue cible
     * @param action L'action source
     */
    static void assignerAction(VueGestionAction* vue, const Action* action);

    /**
     * @brief extraireAction
     * Assigne les informations contenues dans une vue à une action
     * @param action L'action cible
     * @param vue La vue source
     */
    static void extraireAction(Action* action, const VueGestionAction* vue);

public slots:

    /**
     * @brief creerAction
     * Lance la création d'une nouvelle action
     */
    static void creerAction();

    /**
     * @brief creerAction
     * Lance la création d'une nouvelle action et la retourne
     */
    static Action* creerEtRetournerAction();

    /**
     * @brief modifierAction
     * Lance la modification d'une action
     * @param idAction L'id de l'action à modifier
     */
    static void modifierAction(const int &idAction);

    /**
     * @brief changerEtat
     * Inverse l'état actuel d'une action
     * @param idAction L'id de l'action à basculer
     */
    static void changerEtat(const int &idAction);

    /**
     * @brief effacerAction
     * Efface une action si elle n'a jamais été utilisée
     * @param idAction L'id de l'action à effacer
     */
    static void effacerAction(const int &idAction);
};

#endif // CONTROLEURACTIONS_H
