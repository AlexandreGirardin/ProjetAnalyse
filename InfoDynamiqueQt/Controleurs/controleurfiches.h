#ifndef CONTROLEURFICHES_H
#define CONTROLEURFICHES_H

#include <QObject>

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
    explicit ControleurFiches(QWidget* vue);

private:

    // Le fragment des fiches
    VueFragment* fragment;

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
    void voirFiche() const;


    /**
     * @brief filtrerFiches
     * Filtre les fiches affichées selon la correspondance avec une chaîne
     * @param filtre Critère de filtre à utiliser
     */
    void filtrerFiches(const QString &filtre);
};

#endif // CONTROLEURFICHES_H
