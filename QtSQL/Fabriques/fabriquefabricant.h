#ifndef FABRIQUEFABRICANT_H
#define FABRIQUEFABRICANT_H

#include <QObject>
#include "Modeles/fabricant.h"
#include "gestionnaireconnexion.h"

class FabriqueFabricant : public QObject
{
    Q_OBJECT

private:
    GestionnaireConnexion *gc;

public:
    explicit FabriqueFabricant(GestionnaireConnexion *a_gc, QObject *parent = 0);

    Fabricant* getFabricant(int id);

    QList<Fabricant*> getFabricants(void);

signals:

public slots:

};

#endif // FABRIQUEFABRICANT_H
