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

    static bool inserer(Piece* piece, const int &idFiche);

    static bool inserer(const QList<Piece*>* pieces, const int &idFiche);

    static bool mettreAJour(const Piece* piece);

    static bool supprimer(const Piece* piece);

    static bool supprimer(const QList<Piece*>* pieces);

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

    static QSqlQuery* preparerRequete(const Piece* piece, const QString &commande);

    static bool ecrire(const Piece *piece, const QString &commande);
};

#endif // MAPPEURPIECES_H
