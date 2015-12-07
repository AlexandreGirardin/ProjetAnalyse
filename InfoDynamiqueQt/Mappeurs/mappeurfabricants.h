#ifndef MAPPEURFABRICANTS_H
#define MAPPEURFABRICANTS_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlRecord>

#include "Controleurs/controleurbd.h"
#include "Modeles/fabricant.h"

class MappeurFabricants : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief MappeurFabricants
     * @param a_bd La base de données à utiliser
     * @param parent
     */
    explicit MappeurFabricants(QSqlDatabase* a_bd, QObject* parent = 0);

    /**
     * @brief getFabricant
     * @param id le numéro du fabricant à mapper
     * @return le fabricant si il existe, NULL autrement
     */
    Fabricant* getFabricant(int id);

    /**
     * @brief getFabricants
     * @return la liste de tous les fabricants de la base de données
     */
    QList<Fabricant*>* getFabricants(void);

private:

    /**
     * @brief bd la base de données source
     */
    QSqlDatabase* bd;

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en pièce
     * @return le fabricant
     */
    Fabricant* mapper(QSqlRecord);

signals:

public slots:

};

#endif // MAPPEURFABRICANTS_H
