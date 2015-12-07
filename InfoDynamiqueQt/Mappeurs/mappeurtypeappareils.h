#ifndef MAPPEURTYPEAPPAREILS_H
#define MAPPEURTYPEAPPAREILS_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlRecord>

#include "Controleurs/controleurbd.h"
#include "Modeles/typeappareil.h"

class MappeurTypeAppareils : public QObject
{
    Q_OBJECT

public:

    /**
     * @brief MappeurTypeAppareil
     * @param a_bc La base de données à utiliser
     * @param parent
     */
    explicit MappeurTypeAppareils(QSqlDatabase* a_bc, QObject* parent = 0);

    /**
     * @brief getTypeAppareil
     * @param id Le numéro du type d'appareil à mapper
     * @return Le type d'appareil si il existe, NULL autremeent
     */
    TypeAppareil* getTypeAppareil(int id);

    /**
     * @brief getTypesAppareil
     * @return La liste de tous les types d'appareils de la base de données
     */
    QList<TypeAppareil*>* getTypesAppareil(void);

private:

    /**
     * @brief bd La base de données source
     */
    QSqlDatabase* bd;

    /**
     * @brief MappeurPieces::mapper
     * @param ligne La ligne de la base de données à mapper en pièce
     * @return La pièce
     */
    TypeAppareil* mapper(QSqlRecord);

public slots:

};

#endif // MAPPEURTYPEAPPAREILS_H
