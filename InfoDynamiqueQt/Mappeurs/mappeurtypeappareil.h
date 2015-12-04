#ifndef MAPPEURTYPEAPPAREIL_H
#define MAPPEURTYPEAPPAREIL_H

#include <QObject>
#include "gestionnaireconnexion.h"
#include "Modeles/typeappareil.h"

class MappeurTypeAppareil : public QObject
{
    Q_OBJECT

private:
    GestionnaireConnexion *gc;

public:
    explicit MappeurTypeAppareil(GestionnaireConnexion *a_gc, QObject *parent = 0);

    TypeAppareil* getTypeAppareil(int id);

    QList<TypeAppareil*> getTypesAppareil(void);
signals:

public slots:
};

#endif // MAPPEURTYPEAPPAREIL_H
