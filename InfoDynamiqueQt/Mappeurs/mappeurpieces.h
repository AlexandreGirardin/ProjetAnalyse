#ifndef MAPPEURPIECES_H
#define MAPPEURPIECES_H

#include "Modeles/piece.h"

#include <QSqlQuery>
#include <QSqlRecord>

class MappeurPieces {

    // Extrait des objets Piece de la base de données

public:

    /**
     * @brief MappeurPieces::getPiece
     * @param id Le numéro de la pièce à mapper
     * @return La pièce si elle existe, NULL autrement
     */
    static Piece* getPiece(const int &id);

    /**
     * @brief MappeurPieces::getPieces
     * @return La liste de toutes les pièces de la base de données
     */
    static QList<Piece*>* getPieces();

    /**
     * @brief piecesPourFiche
     * Trouve les pieces appartenant à une fiche
     * @param idFche La fiche cible
     * @return La liste des pieces appartenant à la fiche
     */
    static QList<Piece*>* piecesPourFiche(const int &idFiche);

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
};

#endif // MAPPEURPIECES_H
