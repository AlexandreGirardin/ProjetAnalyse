#ifndef MAPPEURTECHNICIENS_H
#define MAPPEURTECHNICIENS_H

#include <QObject>

#include "Modeles/technicien.h"

#include <QSqlDatabase>
#include <QSqlRecord>

class MappeurTechniciens : public QObject
{
    Q_OBJECT

    // Extrait des objets Technicien de la base de données

public:

    /**
     * @brief MappeurTechnicien
     * @param a_bd La base de données à utiliser
     * @param parent
     */
    explicit MappeurTechniciens(QSqlDatabase* a_bd, QObject* parent = 0);

    /**
     * @brief getTechnicien
     * @param id Le numéro du technicien à mapper
     * @return La pièce si elle existe, NULL autrement
     */
    Technicien* getTechnicien(int id);

    /**
     * @brief getTechniciens
     * @return La liste de tous les techniciens de la base de données
     */
    QList<Technicien*>* getTechniciens();

private:

    /**
     * @brief bd La base de données source
     */
    QSqlDatabase* bd;

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en pièce
     * @return Le technicien
     */
    Technicien* mapper(QSqlRecord);

};

#endif // MAPPEURTECHNICIENS_H
