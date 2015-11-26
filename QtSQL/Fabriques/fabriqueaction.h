#ifndef FABRIQUEACTION_H
#define FABRIQUEACTION_H

#include <QObject>
#include "Modeles/action.h"
#include "gestionnaireconnexion.h"

class FabriqueAction : public QObject
{
    Q_OBJECT

private:
    GestionnaireConnexion *gc;

public:
    explicit FabriqueAction(GestionnaireConnexion* a_gc, QObject *parent = 0);

    Action* getAction(int id);

    QList<Action*> getActions(void);

signals:

public slots:

};

#endif // FABRIQUEACTION_H
