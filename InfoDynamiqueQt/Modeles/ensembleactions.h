#ifndef ENSEMBLEACTIONS_H
#define ENSEMBLEACTIONS_H

#include "Modeles/modelebd.h"

class Action;

class EnsembleActions : public ModeleBD {

    // Regroupement prédéfini de tâches permettant une création de fiches simplifiée

private:

    // Nom de l'ensemble
    QString m_nom;

    // Description de l'ensemble
    QString m_description;

    // La liste des actions faisant partie de l'ensemble
    QList<Action*>* m_actions;

public:

    /**
     * @brief EnsembleTaches
     * @param parent
     */
    explicit EnsembleActions(QObject* parent = 0);

    /**
     * @brief actions
     * Les actions faisant partie de l'ensemble
     * @return La liste des actions
     */
    QList<Action*>* actions() const;

    /**
     * @brief setActions
     * Assigne une liste d'actions à l'ensemble
     * Supprime l'ancienne liste ainsi que toutes les actions qu'elle contient
     * Ne pas assigner de liste pouvant contenir des actions provenant originalement du même ensemble
     * ou il y aura des entrées NULL dans la liste
     * @param value La liste d'actions à assigner
     */
    void setActions(QList<Action*>* value);

    /**
     * @brief nom
     * Le nom de l'ensemble
     * @return Le nom de l'ensemble
     */
    QString nom() const;

    /**
     * @brief setNom
     * Assigne un nom à l'ensemble
     * @param value Le nom à assigner à l'ensemble
     */
    void setNom(const QString &value);

    /**
     * @brief description
     * La description de l'ensemble
     * @return La description de l'ensemble
     */
    QString description() const;

    /**
     * @brief setDescription
     * Assigne une description à l'ensemble
     * @param value La description à assigner à l'ensemble
     */
    void setDescription(const QString &value);

    /**
     * @brief out
     * @return Représentation textuelle de l'ensemble de tâches
     */
    QString out() const;
};

#endif // ENSEMBLEACTIONS_H
