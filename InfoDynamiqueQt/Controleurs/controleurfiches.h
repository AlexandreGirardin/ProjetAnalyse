#ifndef CONTROLEURFICHES_H
#define CONTROLEURFICHES_H

#include <QObject>
#include "Vues/vueprincipale.h"
#include "Vues/vuesecondaire.h"
#include "Vues/vuefragment.h"

class ControleurFiches : public QObject
{
    Q_OBJECT
public:
    explicit ControleurFiches(VuePrincipale *, QObject *parent = 0);

private:
    VueSecondaire *vueSecondaireFiches;
    VueFragment *fragment;

signals:

public slots:
};

#endif // CONTROLEURFICHES_H
