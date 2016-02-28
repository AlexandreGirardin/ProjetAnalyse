#ifndef MAPPEURFABRICANTS_H
#define MAPPEURFABRICANTS_H

class Fabricant;

template <class T> class QList;
class QString;
class QSqlQuery;
class QSqlRecord;

class MappeurFabricants {

    // Lit et écrit des objets Fabricant dans la base de données

public:

    /**
     * @brief get
     * @param id Le numéro du fabricant à mapper
     * @return le fabricant s'il existe, NULL autrement
     */
    static Fabricant* get(const int &id);

    /**
     * @brief get
     * @return La liste de tous les fabricants de la base de données
     */
    static QList<Fabricant*>* get();

private:

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en pièce
     * @return Le fabricant
     */
    static Fabricant* mapper(const QSqlRecord &ligne);

    /**
     * @brief mapper
     * Construit tous les fabricants se retrouvant dans les résultats d'une requête SQL
     * @param requete La requête à mapper
     * @return Les fabricants présents dans la requête
     */
    static QList<Fabricant*>* mapper(QSqlQuery &requete);

};

#endif // MAPPEURFABRICANTS_H
