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

    /**
     * @brief ControleurFiches
     * @param vuePrincipale
     * @param parent
     */
    explicit ControleurFiches(VuePrincipale* vuePrincipale, QObject* parent = 0);

private:

    // La vue secondaire à contrôler
    VueSecondaire *vueSecondaireFiches;

    // Le fragment des fiches
    VueFragment *fragment;

signals:

public slots:
};

#endif // CONTROLEURFICHES_H
