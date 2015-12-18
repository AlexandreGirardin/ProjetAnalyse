#ifndef ACTION_H
#define ACTION_H

#include <QObject>

class Action
{

private:
    // Le numéro de l'action
    int id;

    // Le nom de l'Action
    QString nom;

    // La description de l'Action
    QString description;

public:

    /**
     * @brief Action Constructeur d'action
     * @param parent
     */
    explicit Action(QObject* parent = 0);

    /**
     * @brief Action Constructeur d'Action
     * @param parent
     */
    Action(int, QString, QString, QObject* parent = 0);


    /**
     * @brief getId Permet d'aller chercher la valeur de l'ID de l'Action
     * @return
     */
    int getId() const;
    /**
     * @brief setId Permet de changer la valeur de l'ID de l'Action
     * @param value l'id à attribuer
     */
    void setId(int value);


    /**
     * @brief getNom Permet d'aller chercher le nom de l'Action
     * @return
     */
    QString getNom() const;
    /**
     * @brief setNom Permet d'aller chercher le nom de l'Action
     * @param value le nom à attribuer
     */
    void setNom(const QString &value);


    /**
     * @brief getDescription Permet d'aller chercher la description de l'Action
     * @return
     */
    QString getDescription() const;
    /**
     * @brief setDescription Permet d'aller chercher la description de l'Action
     * @param value la description à attribuer
     */
    void setDescription(const QString &value);

    QString out();

public slots:
};

#endif // ACTION_H
