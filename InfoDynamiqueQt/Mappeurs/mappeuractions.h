#ifndef MAPPEURACTIONS_H
#define MAPPEURACTIONS_H

#include <QObject>

#include "Modeles/action.h"

#include <QSqlDatabase>
#include <QSqlRecord>

class MappeurActions : public QObject
{
    Q_OBJECT

    // Extrait des objets Action de la base de données

public:

    /**
     * @brief MappeurActions
     * @param a_bd La base de données à utiliser
     * @param parent
     */
    explicit MappeurActions(QSqlDatabase* a_bd, QObject* parent = 0);

    /**
     * @brief getAction
     * @param id Le numéro de l'action à mapper
     * @return L'action si elle existe. NULL autrement
     */
    Action* getAction(int id);

    /**
     * @brief getActions
     * @return La liste de toutes les actions de la base de données.
     */
    QList<Action*>* getActions();

private:

    /**
     * @brief bd la base de donnéessource
     */
    QSqlDatabase* bd;

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en pièce
     * @return l'Action
     */
    Action* mapper(QSqlRecord);

};

#endif // MAPPEURACTIONS_H
