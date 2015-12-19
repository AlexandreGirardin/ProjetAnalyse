#ifndef MAPPEURPIECES_H
#define MAPPEURPIECES_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlRecord>

#include "Modeles/piece.h"

class MappeurPieces : public QObject
{
    Q_OBJECT

    // Extrait des objets Piece de la base de données

public:

    /**
     * @brief MappeurPieces::MappeurPieces
     * @param a_bd La base de données à utiliser
     * @param parent
     */
    explicit MappeurPieces(QSqlDatabase* a_bd, QObject* parent = 0);

    /**
     * @brief MappeurPieces::getPiece
     * @param id Le numéro de la pièce à mapper
     * @return La pièce si elle existe, NULL autrement
     */
    Piece* getPiece(int id);

    /**
     * @brief MappeurPieces::getPieces
     * @return La liste de toutes les pièces de la base de données
     */
    QList<Piece*>* getPieces();

private:

    /**
     * @brief bd La base de données source
     */
    QSqlDatabase* bd;

    /**
     * @brief MappeurPieces::mapper
     * @param ligne La ligne de la base de données à mapper en pièce
     * @return La pièce
     */
    Piece* mapper(QSqlRecord);

};

#endif // MAPPEURPIECES_H
