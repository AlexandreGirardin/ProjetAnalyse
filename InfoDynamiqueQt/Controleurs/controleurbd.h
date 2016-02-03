#ifndef CONTROLEURCONNEXION_H
#define CONTROLEURCONNEXION_H

#include <QObject>

#include "Vues/vueconnexion.h"

#include <QtSql/QSql>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>

class ControleurBD : public QObject
{
    Q_OBJECT

    // Définit la connexion avec les bases de données

private:

    // La base de données principale
    QSqlDatabase bd;

public:

    /**
     * @brief ControleurBD
     * @param parent
     */
    explicit ControleurBD(QObject* parent = 0);

    /**
     * @brief getBd
     * @return La base de donnée principale
     */
    QSqlDatabase* getBd();

    /**
     * @brief connecterDossiers
     * Établit la connexion avec la base de données principale
     * Elle sera accessible statiquement par QSqlDatabase::database("dossiers)
     */
    void connecterDossiers();

    /**
     * @brief nomBd
     * @return Le nom de la base de données
     */
    static const QString nomBd();

    /**
     * @brief meta
     * @return Le méta-caractère de la base de données
     */
    static const QString* meta;

private:

    /**
     * @brief configurerBoutonConnecter
     * Connecte le bouton Connecter
     */
    void configurerBoutonConnecter();

    /**
     * @brief vueConnexion
     */
    VueConnexion* vue;

public slots:

    /**
     * @brief peuplerBd
     * peuple la table de la vueConnexion avec toutes les BD du serveur.
     */
    void peuplerBd();

    /**
     * @brief clicConnecter
     * Informe lors de la demande de connexion
     */
    void clicConnecter();

};

#endif // CONTROLEURCONNEXION_H
