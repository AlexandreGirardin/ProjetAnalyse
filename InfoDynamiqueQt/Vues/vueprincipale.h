#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;

namespace Ui {
class VuePrincipale;
}

class VuePrincipale : public QMainWindow
{
    Q_OBJECT

    // Vue principale de l'application, regroupant les autres vues dans des onglets

    QPushButton* boutonRecharger;

    void repositionnerBoutonRecharger();

    void configurerBoutonRecharger();

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

    /**
     * @brief resizeEvent
     * Intercepte les redimensionnements pour replacer le boutonRecharger
     */
    void resizeEvent(QResizeEvent*);

    /**
     * @brief getBoutonRecharger
     * retourne le bouton qui permet de rafraichir l'application
     * @return
     */
    QPushButton* getBoutonRecharger() const;

private:

    Ui::VuePrincipale* ui;

    /**
     * @brief closeEvent
     * Redéfinition de l'action lors de la fermeture de la fenêtre
     * Ignore l'événement et émet le signal deconnexion()
     * @param event L'événement de fermeture de fenêtre
     */
    void closeEvent(QCloseEvent* event);

signals:

    /**
     * @brief deconnexion
     * Émis lorsque l'usager tente de fermer la fenêtre
     */
    void deconnexion();

};

#endif // MAINWINDOW_H
