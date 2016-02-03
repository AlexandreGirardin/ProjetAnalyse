#ifndef REQUETESSQL_H
#define REQUETESSQL_H

#include <QObject>

class RequetesSQL : public QObject
{
    Q_OBJECT

public:

    // Requête permettant d'afficher les appareils
    static const QString* afficherAppareils;
    // Requête permettant d'afficher les appareils correspondant à :filtre
    static const QString* filtrerAppareils;

    // Requête permettant d'afficher toutes les actions
    static const QString* afficherToutesActions;
    // Requête permettant d'afficher les actions actives
    static const QString* afficherActionsActives;
    // Requête permettant d'afficher toutes les actions correspondant à :filtre
    static const QString* filtrerToutesActions;
    // Requête permettant d'afficher les actions actives correspondant à :filtre
    static const QString* filtrerActionsActives;
    // Requête permettant d'afficher les ensembles d'actions
    static const QString* afficherEnsembles;

    // Requête permettant d'afficher les clients
    static const QString* afficherClients;
    // Requête permettant d'afficher les clients correspondant à :filtre
    static const QString* filtrerClients;
    // Requête permettant d'afficher les appareils ayant un :idClient
    static const QString* appareilsPourClient;
    // Requête permettant d'afficher les fiches actives ayant un :idAppareil
    static const QString* toutesFichesPourAppareil;
    // Requête permettant d'afficher toutes les fiches ayant un :idAppareil
    static const QString* fichesActivesPourAppareil;

    // Requête permettant d'afficher toutes les fiches
    static const QString* afficherFiches;
    // Requête permettant d'afficher les fiches correspondant à :filtre
    static const QString* filtrerFiches;

    // Requête permettant de lister toutes les base de données d'un serveur
    static const QString* listerBD;
};

#endif // REQUETESSQL_H
