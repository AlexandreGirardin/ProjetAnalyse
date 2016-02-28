#ifndef MAPPEURAPPAREILS_H
#define MAPPEURAPPAREILS_H

class Appareil;

template <class T> class QList;
class QString;
class QSqlQuery;
class QSqlRecord;

class MappeurAppareils {

    // Lit et écrit des objets Appareil dans la base de données

public:

    /**
     * @brief get
     * @param id Le numéro de l'appareil à mapper
     * @return L'appareil s'il existe, NULL autrement
     */
    static Appareil* get(const int &id);

    /**
     * @brief pourClient
     * Trouve les appareils appartenant à un client
     * @param client Le client cible
     * @return La liste des appareils appartenant au client
     */
    static QList<Appareil*>* pourClient(const int &idClient);

    /**
     * @brief nombrePourClient
     * Retourne le nombre d'appareils appartenant à un client
     * @param idClient Le client à chercher
     * @return Le nombre total d'appareils du client
     */
    static int nombrePourClient(const int &idClient);

    /**
     * @brief inserer
     * Insère un nouvel appareil dans la base de données
     * @param appareil L'appareil à ajouter
     * @return Succès
     */
    static bool inserer(Appareil* appareil);

    /**
     * @brief mettreAJour
     * Met à jour un appareil dans la base de données
     * @param appareil L'appareil à mettre à jour
     * @return Succès
     */
    static bool mettreAJour(const Appareil* appareil);

    /**
     * @brief supprimer
     * Efface un appareil de la base de données
     * Échouera si l'appareil possède des fiches
     * @param appareil L'appareil à effacer
     * @return Succès
     */
    static bool supprimer(const Appareil* appareil);

private:

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en appareil
     * @return L'appareil
     */
    static Appareil* mapper(const QSqlRecord &ligne);


    /**
     * @brief mapper
     * Construit tous les appareils se retrouvant dans les résulats d'une requête SQL
     * @param requete La requête à mapper
     * @return Les appareils présents dans la requête
     */
    static QList<Appareil*>* mapper(QSqlQuery &requete);

    /**
     * @brief preparerRequete Assigne les valeurs d'un appareil à une requête préparée
     * @param appareil L'appareil source
     * @param commande La commande SQL à préparer
     * @return La commande préparée
     */
    static QSqlQuery* preparerRequete(const Appareil* appareil, const QString &commande);

    /**
     * @brief ecrire
     * Effectue une opération SQL à l'intérieur d'une transaction
     * La transaction est annulée si l'opération échoue et validée autrement
     * @param appareil L'appareil à inclure dans l'opération SQL
     * @param commande La commande à exécuter
     * @return Succès de l'opération
     */
    static bool ecrire(const Appareil* appareil, const QString &commande);

};

#endif // MAPPEURAPPAREILS_H
