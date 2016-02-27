#ifndef CONTROLEURFICHES_H
#define CONTROLEURFICHES_H

#include <QObject>

class Fragment;

class QPushButton;

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

    // Le fragment permettant de contrôler les fiches
    Fragment* fragment;

    // Le bouton permettant de traiter la fiche sélectionner
    QPushButton* boutonTraiter;

    // La requête SQL actuelle pour fiches sans filtre de recherche
    const QString* requeteFiches;

    // La requête SQL actuelle pour fiches avec filtre de recherche
    const QString* requeteFichesFiltre;

public slots:

    /**
     * @brief peuplerFiches
     * Peuple la table du fragment avec toutes les fiches
     */
    void peuplerFiches();

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

    /**
     * @brief recharger
     * Repeuple le fragment en tenant compte du filtre actuel
     */
    void recharger();

    /**
     * @brief rafraichir
     * Recharge le fragment et conserve la sélection
     */
    void rafraichir();

    /**
     * @brief activerCritereFiches
     * Le fragment n'affichera que les fiches correspondant au filtre qui ne sont pas fermées
     */
    void activerCritereFiches();

    /**
     * @brief desactiverCritereFiches
     * Le fragment affichera toutes les fiches correspondant au filtre
     */
    void desactiverCritereFiches();
};

#endif // CONTROLEURFICHES_H
