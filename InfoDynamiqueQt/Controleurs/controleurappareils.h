#ifndef CONTROLEURAPPAREILS_H
#define CONTROLEURAPPAREILS_H

#include <QObject>
#include "Vues/vueprincipale.h"
#include "Vues/vuesecondaire.h"
#include "Vues/vuefragment.h"

class ControleurAppareils : public QObject
{
    Q_OBJECT
public:
    explicit ControleurAppareils(VuePrincipale *vuePrincipale, QObject *parent = 0);

private:
    VueSecondaire *vueSecondaireAppareils;
    VueFragment *fragment;

signals:

public slots:
};

#endif // CONTROLEURAPPAREILS_H
