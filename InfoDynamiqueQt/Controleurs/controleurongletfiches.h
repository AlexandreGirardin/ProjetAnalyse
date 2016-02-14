#ifndef CONTROLEURFICHES_H
#define CONTROLEURFICHES_H

#include <QObject>

#include "Vues/fragment.h"

class ControleurOngletFiches : public QObject
{
    Q_OBJECT

    // Contrôle l'exécution de l'onglet Fiches de la vue principale

public:

    /**
     * @brief ControleurFiches
     * @param vuePrincipale La vue à laquelle se rattache le contrôleur
     * @param parent
     */
    explicit ControleurOngletFiches(QWidget* vue);

private:

    Fragment* fragment;

    QPushButton* boutonTraiter;

public slots:

    /**
     * @brief peuplerFiches
     * Peuple la table du fragment avec toutes les fiches
     */
    void peuplerFiches();

    /**
     * @brief modifierFiche
     * Lance la modification de la fiche actuellement sélectionnée
     */
    void modifierFiche() const;

    /**
     * @brief traiterFiche
     * Lance le traitement de la fiche sélectionnée
     */
    void traiterFiche() const;

    /**
     * @brief filtrerFiches
     * Filtre les fiches affichées selon la correspondance avec une chaîne
     * @param filtre Critère de filtre à utiliser
     */
    void filtrerFiches(const QString &filtre);

    void recharger();

    void rafraichir();
};

#endif // CONTROLEURFICHES_H
