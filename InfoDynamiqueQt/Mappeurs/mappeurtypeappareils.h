#ifndef MAPPEURTYPEAPPAREILS_H
#define MAPPEURTYPEAPPAREILS_H

#include <QObject>

#include "Modeles/typeappareil.h"

#include <QSqlDatabase>
#include <QSqlRecord>

class MappeurTypeAppareils : public QObject
{
    Q_OBJECT

    // Extrait des objets Appareil de la base de données

public:

    /**
     * @brief MappeurTypeAppareil
     * @param a_bd La base de données à utiliser
     * @param parent
     */
    explicit MappeurTypeAppareils(QObject* parent = 0);

    /**
     * @brief getTypeAppareil
     * @param id Le numéro du type d'appareil à mapper
     * @return Le type d'appareil si il existe, NULL autremeent
     */
    TypeAppareil* getTypeAppareil(const int &idType);

    /**
     * @brief getTypesAppareil
     * @return La liste de tous les types d'appareils de la base de données
     */
    QList<TypeAppareil*>* getTypesAppareil();

private:

    /**
     * @brief MappeurPieces::mapper
     * @param ligne La ligne de la base de données à mapper en pièce
     * @return La pièce
     */
    TypeAppareil* mapper(const QSqlRecord &ligne);

    QList<TypeAppareil*>* mapper(QSqlQuery &requete);
};

#endif // MAPPEURTYPEAPPAREILS_H
