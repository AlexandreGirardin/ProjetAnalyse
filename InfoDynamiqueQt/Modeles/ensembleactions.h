#ifndef ENSEMBLEACTIONS_H
#define ENSEMBLEACTIONS_H

#include "Modeles/action.h"

class EnsembleActions : public ModeleBD {
    Q_OBJECT

    // Regroupement prédéfini de tâches permettant une création de fiches simplifiée

private:

    int m_id;

    QString m_nom;

    QString m_description;

    // La liste des tâches faisant partie de l'ensemble
    QList<Action*>* m_actions;

public:

    /**
     * @brief EnsembleTaches
     * @param parent
     */
    explicit EnsembleActions(QObject* parent = 0);

    QList<Action*>* actions() const;
    void setActions(QList<Action*>* value);

    // Représentation textuelle de l'ensemble de tâches
    QString nom() const;
    void setNom(const QString &value);
    QString description() const;
    void setDescription(const QString &value);
    int id() const;
    void setId(const int &value);
    QString out() const;
};

#endif // ENSEMBLEACTIONS_H
