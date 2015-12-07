#ifndef ACTION_H
#define ACTION_H

#include <QObject>

class Action
{

private:
    // Le numéro de l'action
    int id;

    // Le nomde l'Action
    QString nom;

    // La description de l'Action
    QString description;

public:

    /**
     * @brief Action
     * @param parent
     */
    explicit Action(QObject* parent = 0);

    /**
     * @brief Action
     * @param parent
     */
    Action(int, QString, QString, QObject* parent = 0);

    int getId() const;
    void setId(int value);

    QString getNom() const;
    void setNom(const QString &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    QString out();

public slots:
};

#endif // ACTION_H
