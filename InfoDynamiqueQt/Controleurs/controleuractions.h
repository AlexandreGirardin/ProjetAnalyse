#ifndef CONTROLEURACTIONS_H
#define CONTROLEURACTIONS_H

#include <QObject>
#include <QSqlQuery>
#include <QSplitter>

#include "Vues/vueprincipale.h"
#include "Vues/vuefragment.h"

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
    explicit ControleurActions(VuePrincipale* vuePrincipale, QObject* parent = 0);

    /**
     * @brief ongletDejaCharge
     * Si l'onglet a déjà été peuplé une première fois
     * Utilisé pour le chargement paresseux initial
     */
    bool ongletDejaCharge;

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

    // La requête utilisée pour peupler les actions
    const QString* requeteActions;

    // La requête utilisée pour peupler les ensembles
    const QString* requeteEnsembles;

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

};

#endif // CONTROLEURACTIONS_H
