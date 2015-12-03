#ifndef MAPPEURSTATUT_H
#define MAPPEURSTATUT_H

#include <QObject>
#include "gestionnaireconnexion.h"
#include "Modeles/statut.h"

class MappeurStatut : public QObject
{
    Q_OBJECT

private:
    GestionnaireConnexion *gc;

public:
    explicit MappeurStatut(GestionnaireConnexion *a_gc, QObject *parent = 0);

    Statut* getStatutFiche(int id);

    QList<Statut*> getStatutsFiche(void);

    Statut* getStatutAction(int id);

    QList<Statut*> getStatutsAction(void);
signals:

public slots:
};

#endif // MAPPEURSTATUT_H
