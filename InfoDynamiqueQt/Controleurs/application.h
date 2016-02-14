#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

#include "Controleurs/controleurbd.h"
#include "Controleurs/controleurongletactions.h"
#include "Controleurs/controleurongletappareils.h"
#include "Controleurs/controleurongletclients.h"
#include "Controleurs/controleurongletfiches.h"
#include "Vues/vueprincipale.h"

#include <QMessageBox>

class Application : public QApplication
{
    Q_OBJECT

public:

    explicit Application(int &argc, char **argv);

    /**
     * @brief getInstance
     * Retourne l'instance de l'application en singleton
     * @return
     */
    static const Application* getInstance();

    /**
     * @brief getVuePrincipale
     * Retourne la fenêtre principale de l'application
     * @return
     */
    static VuePrincipale* vuePrincipale();

    // La base de donnée de l'application
    static QSqlDatabase* bd;

    // Le contrôleur de base de données de l'application
    static ControleurBD* controleurBD;

    // Démarre l'application
    void demarrer();

    // Imprime des informations pour tester
    void debug();

private:

    // Singleton
    static const Application* m_instance;

    // La vue principale de l'application
    static VuePrincipale* m_vuePrincipale;

    // Le contrôleur de la vue des clients
    ControleurOngletClients* ongletClients;

    // Si l'onglet des clients a été chargé
    bool clientsCharges;

    // Le contrôleur de la vue des fiches
    ControleurOngletFiches* ongletFiches;

    // Si l'onglet des fiches a été chargé
    bool fichesChargees;

    // Le contrôleur de la vue des appareils
    ControleurOngletAppareils* ongletAppareils;

    // Si l'onglet des appareils a été chargé
    bool appareilsCharges;

    // Le contrôleur de la vue des actions
    ControleurOngletActions* ongletActions;

    // Si l'onglet des actions a été chargé
    bool actionsChargees;

    // Connexion prenant en charge le chargement paresseux des onglet
    QMetaObject::Connection paresseux;

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
    static void erreur(const QString &message, const QString &titre = tr("Erreur"), QMessageBox::Icon type = QMessageBox::Warning);

public slots:

    /**
     * @brief chargerOnglet
     * Charge l'onglet sélectionné au besoin
     */
    void chargerOnglet();

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

};

#endif // APPLICATION_H
