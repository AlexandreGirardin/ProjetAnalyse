#ifndef MAPPEURACTION_H
#define MAPPEURACTION_H

#include <QObject>
#include "Modeles/action.h"
#include "gestionnaireconnexion.h"

class MappeurAction : public QObject
{
    Q_OBJECT

private:
    GestionnaireConnexion *gc;

public:
    explicit MappeurAction(GestionnaireConnexion* a_gc, QObject *parent = 0);

    Action* getAction(int id);

    QList<Action*> getActions(void);

signals:

public slots:

};

#endif // MAPPEURACTION_H
