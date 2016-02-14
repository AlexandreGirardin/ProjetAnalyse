#ifndef MAPPEURTACHES_H
#define MAPPEURTACHES_H

#include "Modeles/tache.h"

#include <QSqlQuery>

class MappeurTaches {

public:

    /**
     * @brief getTache
     * @param id Le numéro de la tache à mapper
     * @return Le fabricant s'il existe, NULL autrement
     */
    static Tache* getTache(const int &id);

    /**
     * @brief getTaches
     * Construit toutes les tâches de la base de données
     * @return La liste de tous les ensembles de la base de données.
     */
    static QList<Tache*>* getTaches();

    /**
     * @brief tachesPourFiche
     * Retourne toutes les tâches associées à une fiche donnée
     * @param idFiche L'id de la fiche à chercher
     * @return La liste des tâches
     */
    static QList<Tache*>* tachesPourFiche(const int &idFiche);

    /**
     * @brief tachesPourAction
     * Retourne toutes les tâches associées à une action donnée
     * @param idAction L'id de l'action à chercher
     * @return La liste des tâches
     */
    static QList<Tache*>* tachesPourAction(const int &idAction);

private:

    /**
     * @brief mapper
     * Extrait les informations d'un résultat d'une requête vers une action
     * @param ligne La ligne de la base de données à mapper en action
     * @return L'action
     */
    static Tache* mapper(const QSqlRecord &ligne);

    /**
     * @brief mapper
     * Construit toutes les tâches se retrouvant dans les résultats d'une requête SQL
     * @param requete La requête à mapper
     * @return Les tâches présentes dans la requête
     */
    static QList<Tache*>* mapper(QSqlQuery &requete);
};

#endif // MAPPEURTACHES_H
