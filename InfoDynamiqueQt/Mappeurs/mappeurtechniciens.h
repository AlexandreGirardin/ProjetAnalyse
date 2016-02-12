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
     * @brief getTechnicien
     * @param id Le numéro du technicien à mapper
     * @return Le technicien s'il existe, NULL autrement
     */
    static Technicien* getTechnicien(const int &id);

    /**
     * @brief getTechniciens
     * @return La liste de tous les techniciens de la base de données
     */
    static QList<Technicien*>* getTechniciens();

    /**
     * @brief technicienPourFiche
     * @param idFiche
     * @return
     */
    static QList<Technicien*>* technicienPourFiche(const int &idFiche);

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
