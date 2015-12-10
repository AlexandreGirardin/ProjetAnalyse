#ifndef CONTROLEURAPPAREILS_H
#define CONTROLEURAPPAREILS_H

#include <QObject>

#include "Vues/vueprincipale.h"
#include "Vues/vuefragment.h"

class ControleurAppareils : public QObject
{
    Q_OBJECT

public:
    explicit ControleurAppareils(VuePrincipale* vuePrincipale, QObject* parent = 0);

private:
    VueFragment* fragment;

    /**
     * @brief requeteFiches
     * La requête utilisée pour peupler les fiches
     */
    const QString* requeteAppareils;

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
};

#endif // CONTROLEURAPPAREILS_H
