#ifndef CONTROLEURACTIONS_H
#define CONTROLEURACTIONS_H

#include <QObject>

#include "Controleurs/controleurgestionensemble.h"

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

    // Le séparateur redimensionnable contenant les fragments
    QSplitter* splitter;

    // Le fragment des actions
    VueFragment* fragmentActions;

    // Le fragment des ensembles
    VueFragment* fragmentEnsembles;

    /**
     * @brief configurerFragmentActions
     * Configure fragmentActions
     */
    void configurerFragmentActions();

    /**
     * @brief configurerFragmentEnsembles
     * Configure fragmentEnsembles
     */
    void configurerFragmentEnsembles();

    // La requête SQL actuelle pour actions sans filtre de recherche
    const QString* requeteActions;

    // La requête SQL actuelle pour actions avec filtre de recherche
    const QString* requeteActionsFiltre;

    /**
     * @brief assignerAction
     * Assigne les informations de l'action dans les champs de la vue
     * @param vue La vue cible
     * @param action L'action source
     */
    void assignerAction(VueGestionAction* vue, const Action *action) const;

    ControleurGestionEnsemble* controleurEnsemble;

public slots:

    /**
     * @brief peuplerActions
     * Peuple la table du fragmentActions avec toutes les actions
     */
    void peuplerActions();

    /**
     * @brief peuplerEnsembles
     * Peuple la table de fragmentEnsembles avec tous les ensembles
     */
    void peuplerEnsembles();

    /**
     * @brief activerCritereActions
     * Réassigne les commandes SQL pour n'afficher que les actions actives
     */
    void activerCritereActions();

    /**
     * @brief activerCritereActions
     * Réassigne les commandes SQL pour afficher toutes les actions
     */
    void desactiverCritereActions();

    /**
     * @brief filtrerActions
     * Peuple le tableau avec les actions qui correspondent à un critère de recherche
     * @param filtre Le critère de recherche
     */
    void filtrerActions(const QString &filtre);

    /**
     * @brief modifierAction
     * Lance la modification de l'action sélectionnée
     */
    void modifierAction();

    void modifierEnsemble();

    void voirEnsemble();

    void creerEnsemble();

    void supprimerEnsemble();

    /**
     * @brief voirAction
     * Lance la visualisation de l'action sélectionnée
     */
    void voirAction() const;

    /**
     * @brief changerEtat
     * Inverse l'état actuel de l'action sélectionnée
     */
    void changerEtat();

    /**
     * @brief recharger
     * Repeuple le tableau avec filtre de recherche au besoin
     */
    void rechargerActions();

private slots:

    /**
     * @brief rechargerEnsembles
     */
    void rechargerEnsembles();

    void filtrerEnsembles(const QString &filtre);

signals:

    /**
     * @brief donneesModifiees
     * Lancé lorsque les valeurs du tableau ont été modifiées
     */
    void actionsModifiees();

    void ensemblesModifies();

};

#endif // CONTROLEURACTIONS_H
