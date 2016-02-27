#ifndef MAPPEURSTATUTS_H
#define MAPPEURSTATUTS_H

class Statut;

template <class T> class QList;
class QString;
class QSqlQuery;
class QSqlRecord;

class MappeurStatuts {

    // Lit et écrit des objets Statut (Fiches ou Tâches) dans la base de données

public:

    /**
     * @brief getStatutFiche
     * @param id Le numéro du statutFiche à mapper
     * @return Le statut si elle existe. NULL autrement
     */
    static Statut* getStatutFiche(const int &idStatut);

    /**
     * @brief getStatutsFiche
     * @return La liste de tous les statuts des fiches
     */
    static QList<Statut*>* getStatutsFiche();

    /**
     * @brief getStatutTache
     * @param id Le numéro du statutAction à mapper
     * @return Le statut s'il existe, NULL autrement
     */
    static Statut* getStatutTache(const int &idStatut);

    /**
     * @brief getStatutsTache
     * @return La liste de tous les statuts des actions
     */
    static QList<Statut*>* getStatutsTache();

private:

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en pièce
     * @return La pièce
     */
    static Statut* mapper(const QSqlRecord &ligne);

    /**
     * @brief mapper
     * Construit tous les statuts se retrouvant dans les résulats d'une requête SQL
     * @param requete La requête à mapper
     * @return Les statuts présents dans la requête
     */
    static QList<Statut*>* mapper(QSqlQuery &requete);

    /**
     * @brief getStatut
     * Fonction interne retournant un statut générique
     * @param idStatut L'id du statut à construire
     * @param commande La commande permettant d'obtenir le statut
     * @return Le statut (tâches ou fiches)
     */
    static Statut* getStatut(const int &idStatut, const QString &commande);
};

#endif // MAPPEURSTATUTS_H
