#ifndef CONTROLEURACTIONS_H
#define CONTROLEURACTIONS_H

#include <QObject>

#include "Controleurs/controleurensembles.h"
#include "Modeles/action.h"
#include "Vues/fragment.h"
#include "Vues/vuegestionaction.h"

#include <QSqlQuery>
#include <QSplitter>

class ControleurActions : public QObject
{
    Q_OBJECT

    // Contrôle l'exécution de l'onglet Actions de la vue principale

private:

    /**
     * @brief assignerAction
     * Assigne les informations de l'action dans les champs de la vue
     * @param vue La vue cible
     * @param action L'action source
     */
    static void assignerAction(VueGestionAction* vue, const Action *action);

public slots:

    /**
     * @brief creerAction
     * Lance la création d'une nouvelle action
     */
    static void creerAction();

    /**
     * @brief modifierAction
     * Lance la modification de l'action sélectionnée
     */
    static void modifierAction(const int &idAction);

    /**
     * @brief voirAction
     * Lance la visualisation de l'action sélectionnée
     */
    static void voirAction(const int &idAction);

    /**
     * @brief changerEtat
     * Inverse l'état actuel de l'action sélectionnée
     */
    static void changerEtat(const int &idAction);

};

#endif // CONTROLEURACTIONS_H
