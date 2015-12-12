#ifndef CONTROLEURFICHES_H
#define CONTROLEURFICHES_H

#include <QObject>

#include "Vues/vueprincipale.h"
#include "Vues/vuefragment.h"

class ControleurFiches : public QObject
{
    Q_OBJECT

    // Contrôle l'exécution de l'onglet Fiches de la vue principale

public:

    /**
     * @brief ControleurFiches
     * @param vuePrincipale La vue à laquelle se rattache le contrôleur
     * @param parent
     */
    explicit ControleurFiches(VuePrincipale* vuePrincipale, QObject* parent = 0);

private:

    // Le fragment des fiches
    VueFragment *fragment;

    /**
     * @brief requeteFiches
     * La requête utilisée pour peupler les fiches
     */
    const QString* requeteFiches;

public slots:

    /**
     * @brief peuplerFiches
     * Peuple la table du fragment avec toutes les fiches
     */
    void peuplerFiches();

    /**
     * @brief modifierFiche
     * Lance la modification de la fiche sélectionnée
     */
    void modifierFiche();

    /**
     * @brief modifierFiche
     * Lance la visualisation de la fiche sélectionnée
     */
    void voirFiche();
};

#endif // CONTROLEURFICHES_H
