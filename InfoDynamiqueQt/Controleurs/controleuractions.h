#ifndef CONTROLEURACTIONS_H
#define CONTROLEURACTIONS_H

#include <QObject>
#include "Vues/vueprincipale.h"
#include "Vues/vuesecondaire.h"
#include "Vues/vuefragment.h"

class ControleurActions : public QObject
{
    Q_OBJECT
public:
    explicit ControleurActions(VuePrincipale *vuePrincipale, QObject *parent = 0);

private:
    VueSecondaire *vueSecondaireActions;
    VueFragment *fragmentActions;
    VueFragment *fragmentEnsembles;

signals:

public slots:
};

#endif // CONTROLEURACTIONS_H
