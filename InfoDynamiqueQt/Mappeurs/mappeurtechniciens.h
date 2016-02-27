#ifndef MAPPEURTECHNICIENS_H
#define MAPPEURTECHNICIENS_H

class Technicien;

template <class T> class QList;
class QString;
class QSqlQuery;
class QSqlRecord;

class MappeurTechniciens {

    // Lit et écrit des objets Technicien dans la base de données

public:

    /**
     * @brief getTechnicien
     * @param id Le numéro du technicien à mapper
     * @return Le technicien s'il existe, NULL autrement
     */
    static Technicien* get(const int &id);

    /**
     * @brief getTechniciens
     * @return La liste de tous les techniciens de la base de données
     */
    static QList<Technicien*>* get();

private:

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en technicien
     * @return Le technicien
     */
    static Technicien* mapper(const QSqlRecord &ligne);

    /**
     * @brief mapper
     * Construit tous les techniciens se retrouvant dans les résulats d'une requête SQL
     * @param requete La requête à mapper
     * @return Les techniciens présents dans la requête
     */
    static QList<Technicien*>* mapper(QSqlQuery &requete);
};

#endif // MAPPEURTECHNICIENS_H
