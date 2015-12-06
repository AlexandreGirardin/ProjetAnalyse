#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vuesecondaire.h"

namespace Ui {
class VuePrincipale;
}

class VuePrincipale : public QMainWindow
{
    Q_OBJECT

public:
    explicit VuePrincipale(QWidget *parent = 0);
    ~VuePrincipale();

    Ui::VuePrincipale *getUi() const;

private:
    Ui::VuePrincipale *ui;
    VueSecondaire *vueAppareils;
    VueSecondaire *vueFiches;
    VueSecondaire *vueActions;
    VueSecondaire *vueEnsembles;
};

#endif // MAINWINDOW_H
