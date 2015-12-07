#ifndef CONTROLEURCLIENTS_H
#define CONTROLEURCLIENTS_H

#include <QObject>
#include "Controleurs/controleurgestionclient.h"
#include "Controleurs/controleurgestionappareil.h"
#include "Controleurs/controleurgestionfiche.h"
#include "Vues/vueprincipale.h"
#include "Vues/vuesecondaire.h"
#include "Vues/vuefragment.h"

class ControleurClients : public QObject
{
    Q_OBJECT

public:

    /**
     * @brief ControleurClients
     * @param vuePrincipale
     * @param parent
     */
    explicit ControleurClients(VuePrincipale* vuePrincipale, QObject* parent = 0);

private:

    // Le contrôleur de gestion de clients
    ControleurGestionClient *controleurGestionClient;

    // Le contrôleur de gestion d'appareils
    ControleurGestionAppareil *controleurGestionAppareil;

    // Le contrôleur de gestion de fiches
    ControleurGestionFiche *controleurGestionFiche;

    // La vue secondaire à contrôler
    VueSecondaire *vueSecondaireClients;

    // Le fragment des clients
    VueFragment *fragmentClients;

    // Le fragment des appareils
    VueFragment *fragmentAppareils;

    // Le fragment des fiches
    VueFragment *fragmentFiches;

    /**
     * @brief configurerFragmentClients
     * Configure fragmentClients
     */
    void configurerFragmentClients();

    /**
     * @brief configurerFragmentClients
     * Configure fragmentAppareils
     */
    void configurerFragmentAppareils();

    /**
     * @brief configurerFragmentClients
     * Configure fragmentFiches
     */
    void configurerFragmentFiches();

signals:

public slots:
    void clientSelectionne(QModelIndex);
    void afficherFiches(QModelIndex);
    void peuplerClients();
    void peuplerAppareils(int idClient);
    void peuplerFiches(int idAppareil);
};

#endif // CONTROLEURCLIENTS_H
