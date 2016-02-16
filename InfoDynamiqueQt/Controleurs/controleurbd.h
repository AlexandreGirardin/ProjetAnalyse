#ifndef CONTROLEURCONNEXION_H
#define CONTROLEURCONNEXION_H

#include <QObject>

#include "Vues/vueconnexion.h"

#include <QSqlDriver>
#include <QSqlQuery>

class ControleurBD : public QObject
{
    Q_OBJECT

    // Définit la connexion avec les bases de données

private:

    // La base de données principale
    QSqlDatabase m_bd;

    // La vue servant à recueillir les informations de connexion
    VueConnexion* vue;

    void chargerChamps();

public:

    /**
     * @brief ControleurBD
     * @param parent
     */
    explicit ControleurBD(const QString &nom, QObject* parent = 0);

    /**
     * @brief getBd
     * @return La base de donnée principale
     */
    QSqlDatabase* bd();

     // Le nom de la base de données
    QString nomBd;

public slots:

    /**
     * @brief peuplerBd
     * peuple la table de la vueConnexion avec toutes les BD du serveur.
     */
    void listerBd();

    /**
     * @brief clicConnecter
     * Informe lors de la demande de connexion
     */
    void sonderHote();

    /**
     * @brief connecterDossiers
     * Établit la connexion avec la base de données principale
     * Elle sera accessible statiquement par QSqlDatabase::database("dossiers)
     */
    void connecterDossiers();

    /**
     * @brief fermer
     * Ferme la base de données et le contrôleur
     */
    void fermer();

signals:

    /**
     * @brief connexionRatee
     * Émis lorsque la tentative de connexion échoue
     */
    void connexionRatee();

    /**
     * @brief connexionEtablie
     * Émis lorsque la tentative de connexion réussit
     */
    void connexionEtablie();

    /**
     * @brief annule
     * Émis lorsque la fenêtre de dialogue est fermée autrement que par le bouton Ok
     */
    void annule();

};

#endif // CONTROLEURCONNEXION_H
