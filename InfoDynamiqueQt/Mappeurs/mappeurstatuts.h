#ifndef MAPPEURSTATUTS_H
#define MAPPEURSTATUTS_H

#include <QObject>

#include "Modeles/statut.h"

#include <QSqlDatabase>
#include <QSqlRecord>

class MappeurStatuts : public QObject
{
    Q_OBJECT

    // Extrait des objets Statut (fiches ou pièces) de la base de données

public:

    /**
     * @brief MappeurStatuts
     * @param a_bd La base de données à utiliser
     * @param parent
     */
    explicit MappeurStatuts(QObject* parent = 0);

    /**
     * @brief getStatutFiche
     * @param id Le numéro du statutFiche à mapper
     * @return Le statut si elle existe. NULL autrement
     */
    Statut* getStatutFiche(int id);

    /**
     * @brief getStatutsFiche
     * @return La liste de tous les statuts des fiches
     */
    QList<Statut*>* getStatutsFiche(void);

    /**
     * @brief getStatutAction
     * @param id Le numéro du statutAction à mapper
     * @return Le statut s'il existe, NULL autrement
     */
    Statut* getStatutAction(int id);

    /**
     * @brief getStatutsAction
     * @return La liste de tous les statuts des actions
     */
    QList<Statut*>* getStatutsAction(void);

private:

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en pièce
     * @return La pièce
     */
    Statut* mapper(QSqlRecord);

};

#endif // MAPPEURSTATUTS_H
