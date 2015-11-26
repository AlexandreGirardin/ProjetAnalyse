#ifndef MAPPEURPIECE_H
#define MAPPEURPIECE_H

#include <QObject>
#include "gestionnaireconnexion.h"
#include "Modeles/piece.h"

class MappeurPiece : public QObject
{
    Q_OBJECT

private:
    GestionnaireConnexion *gc;

public:
    explicit MappeurPiece(GestionnaireConnexion *a_gc, QObject *parent = 0);

    Piece* getPiece(int id);

    QList<Piece*> getPieces(void);

signals:

public slots:

};

#endif // MAPPEURPIECE_H
