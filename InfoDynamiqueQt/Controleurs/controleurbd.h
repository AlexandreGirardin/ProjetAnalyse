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
    QSqlDatabase* bd();

    /**
     * @brief nomBd
     * @return Le nom de la base de données
     */
    static const QString nomBd;

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

    void reconnecter();

    void fermer();

signals:

    void connexionRatee();

    void connexionEtablie();

    void annule();

};

#endif // CONTROLEURCONNEXION_H
