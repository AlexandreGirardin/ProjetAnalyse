#ifndef MAPPEURFABRICANT_H
#define MAPPEURFABRICANT_H

#include <QObject>
#include "gestionnaireconnexion.h"
#include "Modeles/fabricant.h"

class MappeurFabricant : public QObject
{
    Q_OBJECT

private:
    GestionnaireConnexion *gc;

public:
    explicit MappeurFabricant(GestionnaireConnexion *a_gc, QObject *parent = 0);

    Fabricant* getFabricant(int id);

    QList<Fabricant*> getFabricants(void);

signals:

public slots:

};

#endif // MAPPEURFABRICANT_H
