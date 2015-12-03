#ifndef MAPPEURPIECES_H
#define MAPPEURPIECES_H

#include <QObject>
#include "Controleurs/controleurconnexion.h"
#include "Modeles/piece.h"

class MappeurPieces : public QObject
{
    Q_OBJECT
public:
    explicit MappeurPieces(ControleurBD *a_gc, QObject *parent = 0);

    ControleurBD *gc;

    Piece* getPiece(int id);

    QList<Piece*> getPieces(void);

public slots:

};

#endif // MAPPEURPIECES_H
