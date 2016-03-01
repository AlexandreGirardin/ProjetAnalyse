#ifndef MAPPEURTACHES_H
#define MAPPEURTACHES_H

class Action;
class Fiche;
class Tache;

template <class T> class QList;
class QString;
class QSqlQuery;
class QSqlRecord;

class MappeurTaches {

public:

    /**
     * @brief get
     * @param id Le numéro de la tache à mapper
     * @return Le fabricant s'il existe, NULL autrement
     */
    static Tache* get(const int &id);

    /**
     * @brief get
     * Construit toutes les tâches de la base de données
     * @return La liste de tous les ensembles de la base de données.
     */
    static QList<Tache*>* get();

    /**
     * @brief get
     * Retourne toutes les tâches dont l'id se retrouve dans un liste
     * @param listeId La liste des tâches à mapper
     * @return Les tâches
     */
    static QList<Tache*>* get(const QList<int>* listeId);

    /**
     * @brief pourFiche
     * Retourne toutes les tâches associées à une fiche donnée
     * @param idFiche L'id de la fiche à chercher
     * @return La liste des tâches
     */
    static QList<Tache*>* pourFiche(const int &idFiche);

    /**
     * @brief pourAction
     * Retourne le nombre total de tâches associées à une action donnée
     * @param idAction L'id de l'action à chercher
     * @return Le nombre de tâches
     */
    static int pourAction(const int &idAction);

    /**
     * @brief prioriteMinimale
     * @return La priorité minimale permise pour une tâche
     * @todo L'écrire dans la base de données
     */
    static int prioriteMinimale();

    /**
     * @brief prioriteMaximale
     * @return La priorité maximale permise pour une tâche
     * @todo L'écrire dans la base de données
     */
    static int prioriteMaximale();

    /**
     * @brief inserer
     * Insère une nouvelle tâche dans la base de données
     * @param tache La tâche à insérer
     * @return Succès
     */
    static bool inserer(Tache* tache);

    /**
     * @brief inserer
     * Insère des nouvelles tâches dans la base de données
     * @param taches Les tâches à insérer
     * @return Succès
     */
    static bool inserer(const QList<Tache*>* taches);

    /**
     * @brief mettreAJour
     * Modifie une tâche dans la base de données
     * @param tache La tâche à mettre à jour
     * @return Succès
     */
    static bool mettreAJour(const Tache *tache);

    /**
     * @brief supprimer
     * Efface une tâche de la base de données
     * @param tache La tâche à supprimer
     * @return Succès
     */
    static bool supprimer(const Tache* tache);

    /**
     * @brief supprimer
     * Efface des tâches de la base de données
     * @param taches Les tâches à supprimer
     * @return Succès
     */
    static bool supprimer(const QList<Tache*>* taches);

    /**
     * @brief syncTaches
     * S'assure que seules les tâches actuelles de la fiche soit dans la base de données
     * @param fiche La fiche dont on souhaite synchroniser les tâches
     * @return Succès
     */
    static bool syncTaches(const Fiche* fiche);

    static QList<Tache*>* construirePourActions(const QList<Action*>* actions);

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
