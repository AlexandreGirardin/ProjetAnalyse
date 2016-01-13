#ifndef MAPPEURFABRICANTS_H
#define MAPPEURFABRICANTS_H

#include <QObject>

#include "Modeles/fabricant.h"

#include <QSqlDatabase>
#include <QSqlRecord>

class MappeurFabricants : public QObject
{
    Q_OBJECT

    // Extrait des objets Fabricant de la base de données

public:

    /**
     * @brief MappeurFabricants
     * @param a_bd La base de données à utiliser
     * @param parent
     */
    explicit MappeurFabricants(QSqlDatabase* a_bd, QObject* parent = 0);

    /**
     * @brief getFabricant
     * @param id Le numéro du fabricant à mapper
     * @return le fabricant s'il existe, NULL autrement
     */
    Fabricant* getFabricant(int id);

    /**
     * @brief getFabricants
     * @return La liste de tous les fabricants de la base de données
     */
    QList<Fabricant*>* getFabricants();

private:

    /**
     * @brief bd La base de données source
     */
    QSqlDatabase* bd;

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en pièce
     * @return Le fabricant
     */
    Fabricant* mapper(QSqlRecord);

};

#endif // MAPPEURFABRICANTS_H
