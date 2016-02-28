#ifndef MAPPEURTACHES_H
#define MAPPEURTACHES_H

class Fiche;
class Tache;

template <class T> class QList;
class QString;
class QSqlQuery;
class QSqlRecord;

class MappeurTaches {

public:

    /**
     * @brief getTache
     * @param id Le numéro de la tache à mapper
     * @return Le fabricant s'il existe, NULL autrement
     */
    static Tache* get(const int &id);

    /**
     * @brief getTaches
     * Construit toutes les tâches de la base de données
     * @return La liste de tous les ensembles de la base de données.
     */
    static QList<Tache*>* get();

    static QList<Tache*>* get(const QList<int>* listeId);

    /**
     * @brief tachesPourFiche
     * Retourne toutes les tâches associées à une fiche donnée
     * @param idFiche L'id de la fiche à chercher
     * @return La liste des tâches
     */
    static QList<Tache*>* tachesPourFiche(const int &idFiche);

    /**
     * @brief tachesPourAction
     * Retourne le nombre total de tâches associées à une action donnée
     * @param idAction L'id de l'action à chercher
     * @return Le nombre de tâches
     */
    static int tachesPourAction(const int &idAction);

    // TODO
    static int prioriteMinimale();

    // TODO
    static int prioriteMaximale();

    static bool inserer(Tache* tache);

    static bool inserer(const QList<Tache*>* taches);

    static bool mettreAJour(const Tache *tache);

    static bool supprimer(const Tache* tache);

    static bool supprimer(const QList<Tache*>* taches);

    static bool syncTaches(const Fiche* fiche);

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

    /**
     * @brief preparerRequete
     * Assigne les valeurs d'une tache à une requête préparée
     * @param tache La tâche source
     * @param commande La commande SQL à préparer
     * @return La commande préparée
     */
    static QSqlQuery* preparerRequete(const Tache* tache, const QString &commande);

    /**
     * @brief ecrire
     * Exécute une commande sans transaction
     * @param tache La tâche à inclure dans l'opération SQL
     * @param commande La commande à exécuter
     * @return Succès de l'opération
     */
    static bool ecrire(const Tache* tache, const QString &commande);
};

#endif // MAPPEURTACHES_H
