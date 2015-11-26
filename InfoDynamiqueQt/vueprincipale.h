#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class VuePrincipale;
}

class VuePrincipale : public QMainWindow
{
    Q_OBJECT

public:
    explicit VuePrincipale(QWidget *parent = 0);
    ~VuePrincipale();

private:
    Ui::VuePrincipale *ui;
};

#endif // MAINWINDOW_H
