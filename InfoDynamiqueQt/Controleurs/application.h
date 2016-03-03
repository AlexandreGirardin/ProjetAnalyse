#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

class ControleurConnexion;
class ControleurOngletActions;
class ControleurOngletAppareils;
class ControleurOngletClients;
class ControleurOngletFiches;
class VuePrincipale;

class QSqlDatabase;
class QTimer;
#include <QMessageBox>


class Application : public QApplication
{
    Q_OBJECT

public:

    explicit Application(int &argc, char **argv);

    /**
     * @brief get
     * Retourne l'instance de l'application en singleton
     * @return
     */
    static Application* get();

    /**
     * @brief demarrer
     * Lance l'application
     */
    void demarrer();

    /**
     * @brief getVuePrincipale
     * Retourne la fenêtre principale de l'application
     * @return
     */
    static VuePrincipale* vuePrincipale();

    // La base de donnée de l'application
    static QSqlDatabase* bd;

private:

    // Le contrôleur de base de données de l'application
    static ControleurConnexion* connexion;

    // Singleton
    static Application* m_instance;

    // La vue principale de l'application
    static VuePrincipale* m_vuePrincipale;

    // Contrôle les clients, leurs appareils et leurs fiches
    ControleurOngletClients* ongletClients;

    // Contrôle les fiches
    ControleurOngletFiches* ongletFiches;

    // Contrôle les appareils
    ControleurOngletAppareils* ongletAppareils;

    // Contrôle les actions et les appareils
    ControleurOngletActions* ongletActions;

    // Connexion prenant en charge le chargement paresseux des onglets
    // Détruite lorsque tous les onglets ont été chargés
    QMetaObject::Connection paresseux;

    // Si l'onglet des clients a été chargé
    bool clientsCharges;

    // Si l'onglet des fiches a été chargé
    bool fichesChargees;

    // Si l'onglet des appareils a été chargé
    bool appareilsCharges;

    // Si l'onglet des actions a été chargé
    bool actionsChargees;

    /**
     * @brief verifierParesseux
     * Vérifie si le chargement paresseux est terminé
     */
    void verifierParesseux();

    /**
     * @brief creerFenetre
     * Configure la fenêtre principale de l'application
     */
    void creerFenetre();

    /**
     * @brief chargerParametres
     * Configure l'application selon les paramètres sauvegardés
     */
    void chargerParametres();

    /**
     * @brief executer
     * Lance l'exécution de l'application
     */
    void executer();

    /**
     * @brief erreur
     * Affiche un message d'erreur
     * @param message Le contenu du message à afficher
     * @param titre Le titre de la fenêtre à afficher
     * @param type Le type de message à afficher
     */
    static void erreur(const QString &message, const QString &titre = tr("Erreur"), const QMessageBox::Icon type = QMessageBox::Warning);

    QDateTime* derniereModification;

    QTimer* chrono;

private slots:

    /**
     * @brief connecter
     * Établit une connexion à la base de données
     */
    void connecter();

    /**
     * @brief demarrer
     * Démarre la fenêtre principale
     * Lancé une fois la connexion à la base de données établie
     */
    void ouvrirFenetre();

    /**
     * @brief fermer
     * Ferme l'application suite à une annulation de la connexion
     */
    void fermer();

    /**
     * @brief sauvegarderParametres
     * Enregistre les paramètres de session
     */
    void sauvegarderParametres();

    /**
     * @brief chargerOnglet
     * Charge l'onglet sélectionné au besoin
     */
    void chargerOnglet();

    /**
     * @brief deconnexion
     * Ferme la fenêtre et relance le dialogue de connexion à une base de données
     */
    void deconnexion();

    void verifierModifications();

    void rechargerDonnees();

public slots:

    /**
     * @brief erreurEcriture
     * Affiche un message d'avertissement d'erreur d'écriture
     * @param message L'erreur à afficher
     */
    static void erreurEcriture(const QString &message);

    /**
     * @brief erreurSuppression
     * Affiche un message d'avertissement d'erreur de suppression
     * @param message L'erreur à afficher
     */
    static void erreurSuppression(const QString &message);

    void donneesModifiees();

signals:

    /**
     * @brief clientsModifies
     * Émis lorsque les données des clients ont été modifiées
     */
    void clientModifie() const;

    /**
     * @brief nombreClientsChange
     * Émis lorsqu'un client a été ajouté ou supprimé
     */
    void nombreClientsChange() const;

    /**
     * @brief appareilsModifies
     * Émis lorsque les données des appareils ont été modifiées
     */
    void appareilModifie() const;

    /**
     * @brief nombreAppareilsChange
     * Émis lorsqu'un appareil a été ajouté ou supprimé
     */
    void nombreAppareilsChange() const;

    /**
     * @brief fichesModifiees
     * Émis lorsque les données des fiches ont été modifiées
     */
    void ficheModifiee() const;

    /**
     * @brief nombreFichesChange
     * Émis lorsqu'une fiche a été ajoutée ou supprimée
     */
    void nombreFichesChange() const;

    /**
     * @brief actionsModifiees
     * Émis lorsque les données des actions ont été modifiées
     */
    void actionModifiee() const;

    /**
     * @brief nombreActionsChange
     * Émis lorsqu'une action a été ajoutée ou supprimée
     */
    void nombreActionsChange() const;

    /**
     * @brief ensembleModifie
     * Émis lorsqu'un ensemble a été mis à jour
     */
    void ensembleModifie() const;

    /**
     * @brief ensemblesModifies
     * Émis lorsqu'un ensemble a été ajouté ou supprimé
     */
    void nombreEnsemblesModifie() const;

    /**
     * @brief rafraichirTout
     * Émis lorsque le bouton rafraichir est cliqué.
     */
    void rafraichirTout() const;

    void nouvellesModifications() const;

};

#endif // APPLICATION_H
