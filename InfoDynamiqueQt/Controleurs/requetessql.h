#ifndef REQUETESSQL_H
#define REQUETESSQL_H

#include <QObject>

class RequetesSQL : public QObject
{
    Q_OBJECT

public:

    // Requête permettant d'afficher les appareils
    static QString const * const afficherAppareils;
    // Requête permettant d'afficher les appareils correspondant à :filtre
    static QString const * const filtrerAppareils;

    // Requête permettant d'afficher toutes les actions
    static QString const * const afficherToutesActions;
    // Requête permettant d'afficher les actions actives
    static QString const * const afficherActionsActives;
    // Requête permettant d'afficher toutes les actions correspondant à :filtre
    static QString const * const filtrerToutesActions;
    // Requête permettant d'afficher les actions actives correspondant à :filtre
    static QString const * const filtrerActionsActives;
    // Requête permettant d'afficher les ensembles d'actions
    static QString const * const afficherEnsembles;
    // Requête permettant d'afficher les ensembles correspondant à :filtre
    static QString const * const filtrerEnsembles;

    // Requête permettant d'afficher les clients
    static QString const * const afficherClients;
    // Requête permettant d'afficher les clients correspondant à :filtre
    static QString const * const filtrerClients;
    // Requête permettant d'afficher les appareils ayant un :idClient
    static QString const * const appareilsPourClient;
    // Requête permettant d'afficher les fiches actives ayant un :idAppareil
    static QString const * const toutesFichesPourAppareil;
    // Requête permettant d'afficher toutes les fiches ayant un :idAppareil
    static QString const * const fichesActivesPourAppareil;

    // Requête permettant d'afficher toutes les fiches
    static QString const * const afficherFiches;
    // Requête permettant d'afficher les fiches correspondant à :filtre
    static QString const * const filtrerFiches;
};

#endif // REQUETESSQL_H
