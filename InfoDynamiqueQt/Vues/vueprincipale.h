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


public:

    /**
     * @brief VuePrincipale
     * Le constructeur de la vue
     * @param parent Le widget parent de la vue
     */
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
     * @return Le bouton qui permet de rafraichir les données l'application
     */
    QPushButton* getBoutonRecharger() const;

private:

    // Interface utilisée pour la vue
    Ui::VuePrincipale* ui;

    /**
     * @brief closeEvent
     * Redéfinition de l'action lors de la fermeture de la fenêtre
     * Ignore l'événement et émet le signal deconnexion()
     * @param event L'événement de fermeture de fenêtre
     */
    void closeEvent(QCloseEvent* event);

    // Bouton permettant de rafraichir les données de l'application
    QPushButton* boutonRecharger;

    /**
     * @brief repositionnerBoutonRecharger
     * Permet le repositionnement du bouton recharger
     */
    void repositionnerBoutonRecharger();

    /**
     * @brief configurerBoutonRecharger
     * Configure les paramètres du bouton recharger
     */
    void configurerBoutonRecharger();

public slots:

    /**
     * @brief cacherBoutonRecharger
     * Permet de cacher le bouton recharger
     */
    void cacherBoutonRecharger() const;

    /**
     * @brief afficherBoutonRecharger
     * Permet d'afficher le bouton recharger
     */
    void afficherBoutonRecharger() const;

signals:

    /**
     * @brief deconnexion
     * Émis lorsque l'usager tente de fermer la fenêtre
     */
    void deconnexion();

};

#endif // MAINWINDOW_H
