#ifndef ENSEMBLETACHES_H
#define ENSEMBLETACHES_H

#include <QObject>

#include "Modeles/action.h"

class EnsembleTaches : public QObject {
    Q_OBJECT

    // Regroupement prédéfini de tâches permettant une création de fiches simplifiée

public:

    /**
     * @brief EnsembleTaches
     * @param parent
     */
    explicit EnsembleTaches(QObject *parent = 0);

    // La liste des tâches faisant partie de l'ensemble
    QList<Action*> actions;

    // Représentation textuelle de l'ensemble de tâches
    QString out(void);

};

#endif // ENSEMBLETACHES_H
