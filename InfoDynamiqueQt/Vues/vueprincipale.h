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

    /**
     * @brief getOnglets
     * @return La barre d'onglets de la vue principale
     */
    QTabWidget* getOnglets() const;

    /**
     * @brief getOngletActions
     * @return L'onglet de gestion des actions
     */
    QWidget* getOngletActions() const;

    /**
     * @brief getOngletAppareils
     * @return L'onglet de gestion des appareils
     */
    QWidget* getOngletAppareils() const;

    /**
     * @brief getOngletClients
     * @return L'onglet de gestion des clients
     */
    QWidget* getOngletClients() const;

    /**
     * @brief getOngletFiches
     * @return L'onglet de gestion des fiches
     */
    QWidget* getOngletFiches() const;

private:
    Ui::VuePrincipale* ui;
};

#endif // MAINWINDOW_H
