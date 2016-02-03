#ifndef ENSEMBLEACTIONS_H
#define ENSEMBLEACTIONS_H

#include "Modeles/action.h"

class EnsembleActions : public ModeleBD {
    Q_OBJECT

    // Regroupement prédéfini de tâches permettant une création de fiches simplifiée

private:

    int id;

    QString nom;

    QString description;

    // La liste des tâches faisant partie de l'ensemble
    QList<Action*>* actions;

public:

    /**
     * @brief EnsembleTaches
     * @param parent
     */
    explicit EnsembleActions(QObject* parent = 0);

    QList<Action*>* getActions() const;
    void setActions(QList<Action*>* value);

    // Représentation textuelle de l'ensemble de tâches
    QString getNom() const;
    void setNom(const QString &value);
    QString getDescription() const;
    void setDescription(const QString &value);
    int getId() const;
    void setId(const int &value);
    QString out();
};

#endif // ENSEMBLEACTIONS_H
