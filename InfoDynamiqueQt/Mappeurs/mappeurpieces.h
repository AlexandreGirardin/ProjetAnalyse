#ifndef MAPPEURPIECES_H
#define MAPPEURPIECES_H

class Fiche;
class Piece;

template <class T> class QList;
class QString;
class QSqlQuery;
class QSqlRecord;

class MappeurPieces {

    // Lit et écrit des objets Pieces dans la base de données

public:

    /**
     * @brief get
     * @param id Le numéro de la pièce à mapper
     * @return La pièce si elle existe, NULL autrement
     */
    static Piece* get(const int &id);

    /**
     * @brief get
     * @return La liste de toutes les pièces de la base de données
     */
    static QList<Piece*>* get();

    /**
     * @brief piecesPourFiche
     * Trouve les pieces appartenant à une fiche
     * @param idFche La fiche cible
     * @return La liste des pieces appartenant à la fiche
     */
    static QList<Piece*>* pourFiche(const int &idFiche);

    /**
     * @brief inserer
     * Insère une nouvelle pièce dans la base de données
     * @param piece La pièce à insérer
     * @param idFiche La fiche à laquelle associer la pièce
     * @return Succès
     */
    static bool inserer(Piece* piece, const int &idFiche);

    /**
     * @brief inserer
     * Insère plusieurs pièces dans la base de données
     * @param pieces Les pièces à insérer
     * @param idFiche La fiche à laquelle associer les pièces
     * @return Succès
     */
    static bool inserer(const QList<Piece*>* pieces, const int &idFiche);

    /**
     * @brief mettreAJour
     * Met à jour une pièce dans la base de donnée
     * @param piece La pièce à modifier
     * @return Succès
     */
    static bool mettreAJour(const Piece* piece);

    /**
     * @brief supprimer
     * Efface une pièce de la base de données
     * @param piece La pièce à supprimer
     * @return Succès
     */
    static bool supprimer(const Piece* piece);

    /**
     * @brief supprimer
     * Efface des pièces de la base de données
     * @param pieces Les pièces à supprimer
     * @return Succès
     */
    static bool supprimer(const QList<Piece*>* pieces);

    /**
     * @brief sync
     * S'assure que seules les pièces actuelles d'une fiche sont dans la base de données
     * @param fiche La fiche dont on souhaite synchroniser les pièces
     * @return Succès
     */
    static bool sync(const Fiche* fiche);

private:

    /**
     * @brief MappeurPieces::mapper
     * @param ligne La ligne de la base de données à mapper en pièce
     * @return La pièce
     */
    static Piece* mapper(const QSqlRecord &ligne);

    /**
     * @brief mapper
     * Construit toutes les pieces se retrouvant dans les résulats d'une requête SQL
     * @param requete La requête à mapper
     * @return Les pièces présentes dans la requête
     */
    static QList<Piece*>* mapper(QSqlQuery &requete);

    /**
     * @brief preparerRequete Assigne les valeurs d'une pièce à une requête préparée
     * @param piece La pièce source
     * @param commande La commande SQL à préparer
     * @return La commande préparée
     */
    static QSqlQuery* preparerRequete(const Piece* piece, const QString &commande);

    /**
     * @brief ecrire
     * Effectue une opération SQL
     * @param appareil La pièce à inclure dans l'opération SQL
     * @param commande La commande à exécuter
     * @return Succès de l'opération
     */
    static bool ecrire(const Piece *piece, const QString &commande);
};

#endif // MAPPEURPIECES_H
