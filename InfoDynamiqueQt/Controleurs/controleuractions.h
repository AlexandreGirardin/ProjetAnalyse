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

public:
    explicit ControleurActions(VuePrincipale* vuePrincipale, QObject* parent = 0);

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
    void peuplerAppareils();

};

#endif // CONTROLEURACTIONS_H
