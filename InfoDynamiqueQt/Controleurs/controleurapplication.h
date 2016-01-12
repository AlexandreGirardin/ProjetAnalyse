#ifndef CONTROLEURAPPLICATION_H
#define CONTROLEURAPPLICATION_H

#include <QObject>

#include "Controleurs/controleuractions.h"
#include "Controleurs/controleurappareils.h"
#include "Controleurs/controleurclients.h"
#include "Controleurs/controleurfiches.h"

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
    VuePrincipale* vuePrincipale;

    // Le contrôleur de la vue des clients
    ControleurClients* controleurClients;

    bool clientsCharges;

    // Le contrôleur de la vue des fiches
    ControleurFiches* controleurFiches;

    bool fichesChargees;

    // Le contrôleur de la vue des appareils
    ControleurAppareils* controleurAppareils;

    bool appareilsCharges;

    // Le contrôleur de la vue des actions
    ControleurActions* controleurActions;

    bool actionsChargees;

    QMetaObject::Connection paresseux;

    void verifierParesseux();

public slots:

    void chargerOnglet();

};

#endif // CONTROLEURAPPLICATION_H
