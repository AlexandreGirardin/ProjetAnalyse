#ifndef MAPPEURTECHNICIEN_H
#define MAPPEURTECHNICIEN_H

#include <QObject>
#include "gestionnaireconnexion.h"
#include "Modeles/technicien.h"

class MappeurTechnicien : public QObject
{
    Q_OBJECT

private:
    GestionnaireConnexion *gc;

public:
    explicit MappeurTechnicien(GestionnaireConnexion *a_gc, QObject *parent = 0);

    Technicien* getTechnicien(int id);

    QList<Technicien*> getTechniciens(void);

signals:

public slots:

};

#endif // MAPPEURTECHNICIEN_H
