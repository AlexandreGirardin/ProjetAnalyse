#ifndef ACTION_H
#define ACTION_H

#include "Modeles/modelebd.h"

class Action: public ModeleBD {

    // Définition d'une action effectuée sur un appareil par un technicien

private:

    // Le numéro de l'action
    int id;

    // Le nom de l'action
    QString nom;

    // La description de l'action
    QString description;

    // Si l'action est pratiquée par l'entreprise
    bool etat;

public:

    /**
     * @brief Action Constructeur d'Action
     * @param parent
     */
    explicit Action(QObject* parent = 0);

    /**
     * @brief getId
     * @return L'id de l'action
     */
    int getId() const;

    /**
     * @brief setId
     * @param value L'id à assigner à l'action
     */
    void setId(int value);

    /**
     * @brief getNom
     * @return Le nom de l'action
     */
    QString getNom() const;

    /**
     * @brief setNom
     * @param value Le nom à assigner à l'action
     */
    void setNom(const QString &value);

    /**
     * @brief getDescription
     * @return La description de l'action
     */
    QString getDescription() const;

    /**
     * @brief setDescription
     * @param value La description à assigner à l'action
     */
    void setDescription(const QString &value);

    /**
     * @brief out
     * @return Représentation textuelle de l'action
     */
    QString out();

    /**
     * @brief getEtat Si l'action est pratiquée par l'entreprise
     * @return L'état de l'action
     */
    bool getEtat() const;

    /**
     * @brief setEtat Définit l'état de l'action
     * @param value L'était à assigner
     */
    void setEtat(bool value);

    /**
     * @brief etatOut Chaîne affichable correspondant à l'état
     * @return 'Vrai' ou 'faux'
     */
    QString etatOut();
};

#endif // ACTION_H
