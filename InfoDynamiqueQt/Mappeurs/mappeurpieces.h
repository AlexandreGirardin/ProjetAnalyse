#ifndef MAPPEURPIECES_H
#define MAPPEURPIECES_H

#include <QObject>
#include <QSqlDatabase>

#include "Controleurs/controleurbd.h"
#include "Modeles/piece.h"

class MappeurPieces : public QObject
{
    Q_OBJECT
public:
    explicit MappeurPieces(QSqlDatabase *a_bd, QObject *parent = 0);

    QSqlDatabase bd;

    Piece* getPiece(int id);

    QList<Piece*> getPieces(void);

public slots:

};

#endif // MAPPEURPIECES_H
