#ifndef FABRIQUESTATUT_H
#define FABRIQUESTATUT_H

#include <QObject>
#include "Modeles/statut.h"
#include "gestionnaireconnexion.h"
#include "QDebug"

class FabriqueStatut : public QObject
{
    Q_OBJECT

private:
    GestionnaireConnexion *gc;

public:
    explicit FabriqueStatut(GestionnaireConnexion *a_gc, QObject *parent = 0);

    Statut *getStatut(int id);
signals:

public slots:
};

#endif // FABRIQUESTATUT_H
