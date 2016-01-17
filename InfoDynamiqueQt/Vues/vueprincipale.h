#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class VuePrincipale;
}

class VuePrincipale : public QMainWindow
{
    Q_OBJECT

    // Vue principale de l'application, regroupant les autres vues dans des onglets

public:
    explicit VuePrincipale(QWidget* parent = 0);
    ~VuePrincipale();

    QTabWidget* getOnglets() const;

    QWidget* getOngletActions() const;
    QWidget* getOngletAppareils() const;
    QWidget* getOngletClients() const;
    QWidget* getOngletFiches() const;
private:
    Ui::VuePrincipale* ui;
};

#endif // MAINWINDOW_H
