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
    QTabWidget* onglets() const;

    /**
     * @brief getOngletActions
     * @return L'onglet de gestion des actions
     */
    QWidget* ongletActions() const;

    /**
     * @brief getOngletAppareils
     * @return L'onglet de gestion des appareils
     */
    QWidget* ongletAppareils() const;

    /**
     * @brief getOngletClients
     * @return L'onglet de gestion des clients
     */
    QWidget* ongletClients() const;

    /**
     * @brief getOngletFiches
     * @return L'onglet de gestion des fiches
     */
    QWidget* ongletFiches() const;

private:
    Ui::VuePrincipale* ui;

    void closeEvent(QCloseEvent *event);
signals:

    void deconnexion();

};

#endif // MAINWINDOW_H
