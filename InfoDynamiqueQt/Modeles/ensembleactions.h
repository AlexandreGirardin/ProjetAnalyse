#ifndef ENSEMBLEACTIONS_H
#define ENSEMBLEACTIONS_H

#include <QObject>

#include "Modeles/action.h"

class EnsembleActions : public QObject {
    Q_OBJECT

    // Regroupement prédéfini de tâches permettant une création de fiches simplifiée

public:

    /**
     * @brief EnsembleTaches
     * @param parent
     */
    explicit EnsembleActions(QObject* parent = 0);

    // La liste des tâches faisant partie de l'ensemble
    QList<Action*> actions;

    // Représentation textuelle de l'ensemble de tâches
    QString out();

};

#endif // ENSEMBLEACTIONS_H
