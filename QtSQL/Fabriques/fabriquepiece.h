#ifndef FABRIQUEPIECES_H
#define FABRIQUEPIECES_H

#include <QObject>
#include "gestionnaireconnexion.h"
#include "Modeles/piece.h"

class FabriquePiece : public QObject
{
    Q_OBJECT

private:
    GestionnaireConnexion *gc;

public:
    explicit FabriquePiece(GestionnaireConnexion *a_gc, QObject *parent = 0);

    Piece* getPiece(int id);

    QList<Piece*> getPieces(void);

signals:

public slots:

};

#endif // FABRIQUEPIECES_H
