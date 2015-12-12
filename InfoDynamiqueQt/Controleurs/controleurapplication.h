#ifndef CONTROLEURAPPLICATION_H
#define CONTROLEURAPPLICATION_H

#include <QObject>

#include "Controleurs/controleuractions.h"
#include "Controleurs/controleurappareils.h"
#include "Controleurs/controleurclients.h"
#include "Controleurs/controleurfiches.h"
#include "Vues/vueprincipale.h"

class ControleurApplication : public QObject {
    Q_OBJECT

    // Contrôle l'exécution de l'application

public:

    /**
     * @brief ControleurApplication
     * @param parent
     */
    explicit ControleurApplication(QObject* parent = 0);

    /**
     * @brief executer
     * Lance l'exécution de l'application
     */
    void executer();

private:

    // La vue principale de l'application
    VuePrincipale *vuePrincipale;

    // Le contrôleur de la vue des clients
    ControleurClients *controleurClients;

    // Le contrôleur de la vue des fiches
    ControleurFiches *controleurFiches;

    // Le contrôleur de la vue des appareils
    ControleurAppareils *controleurAppareils;

    // Le contrôleur de la vue des actions
    ControleurActions *controleurActions;

};

#endif // CONTROLEURAPPLICATION_H
