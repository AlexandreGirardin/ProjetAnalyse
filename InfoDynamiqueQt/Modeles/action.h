#ifndef ACTION_H
#define ACTION_H

#include "Modeles/modelebd.h"

class Action: public ModeleBD {

    // Définition d'une action effectuée sur un appareil par un technicien

private:

    // Le nom de l'action
    QString m_nom;

    // La description de l'action
    QString m_description;

    // Si l'action est pratiquée par l'entreprise
    bool m_etat;

public:

    /**
     * @brief Action Constructeur d'Action
     * @param parent
     */
    explicit Action(QObject* parent = 0);

    /**
     * @brief getNom
     * @return Le nom de l'action
     */
    QString nom() const;

    /**
     * @brief setNom
     * @param value Le nom à assigner à l'action
     */
    void setNom(const QString &value);

    /**
     * @brief getDescription
     * @return La description de l'action
     */
    QString description() const;

    /**
     * @brief setDescription
     * @param value La description à assigner à l'action
     */
    void setDescription(const QString &value);

    /**
     * @brief getEtat Si l'action est pratiquée par l'entreprise
     * @return L'état de l'action
     */
    bool etat() const;

    /**
     * @brief setEtat Définit l'état de l'action
     * @param value L'était à assigner
     */
    void setEtat(const bool &value);

    /**
     * @brief etatOut Chaîne affichable correspondant à l'état
     * @return 'Vrai' ou 'faux'
     */
    QString etatOut() const;

    /**
     * @brief out
     * @return Représentation textuelle de l'action
     */
    QString out() const;
};

#endif // ACTION_H
