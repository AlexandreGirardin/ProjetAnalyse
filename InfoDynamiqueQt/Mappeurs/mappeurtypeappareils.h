#ifndef MAPPEURTYPEAPPAREILS_H
#define MAPPEURTYPEAPPAREILS_H

#include "Modeles/typeappareil.h"

#include <QSqlDatabase>
#include <QSqlRecord>

class MappeurTypeAppareils {

    // Extrait des objets Appareil de la base de données

public:

    /**
     * @brief getTypeAppareil
     * @param id Le numéro du type d'appareil à mapper
     * @return Le type d'appareil si il existe, NULL autremeent
     */
    static TypeAppareil* getTypeAppareil(const int &idType);

    /**
     * @brief getTypesAppareil
     * @return La liste de tous les types d'appareils de la base de données
     */
    static QList<TypeAppareil*>* getTypesAppareil();

private:

    /**
     * @brief MappeurPieces::mapper
     * @param ligne La ligne de la base de données à mapper en pièce
     * @return La pièce
     */
    static TypeAppareil* mapper(const QSqlRecord &ligne);

    /**
     * @brief mapper
     * Construit tous les typesAppareil se retrouvant dans les résulats d'une requête SQL
     * @param requete La requête à mapper
     * @return Les typesAppareil présents dans la requête
     */
    static QList<TypeAppareil*>* mapper(QSqlQuery &requete);
};

#endif // MAPPEURTYPEAPPAREILS_H
