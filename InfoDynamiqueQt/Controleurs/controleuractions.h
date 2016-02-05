#ifndef CONTROLEURACTIONS_H
#define CONTROLEURACTIONS_H

#include <QObject>

#include "Controleurs/controleurensembles.h"

#include "Modeles/action.h"

#include "Vues/vuefragment.h"
#include "Vues/vuegestionaction.h"

#include <QSqlQuery>
#include <QSplitter>

class ControleurActions : public QObject
{
    Q_OBJECT

    // Contrôle l'exécution de l'onglet Actions de la vue principale

public:

    /**
     * @brief ControleurActions
     * @param vuePrincipale La vue à laquelle se rattache le contrôleur
     * @param parent
     */
    explicit ControleurActions(QWidget* conteneur);

private:

    /**
     * @brief assignerAction
     * Assigne les informations de l'action dans les champs de la vue
     * @param vue La vue cible
     * @param action L'action source
     */
    void assignerAction(VueGestionAction* vue, const Action *action) const;

public slots:

    /**
     * @brief modifierAction
     * Lance la modification de l'action sélectionnée
     */
    void modifierAction(const int &idAction);

    /**
     * @brief voirAction
     * Lance la visualisation de l'action sélectionnée
     */
    void voirAction(const int &idAction) const;

    /**
     * @brief changerEtat
     * Inverse l'état actuel de l'action sélectionnée
     */
    void changerEtat(const int &idAction);

signals:

    /**
     * @brief donneesModifiees
     * Lancé lorsque les valeurs du tableau ont été modifiées
     */
    void actionsModifiees();

//    void ensemblesModifies();

};

#endif // CONTROLEURACTIONS_H
