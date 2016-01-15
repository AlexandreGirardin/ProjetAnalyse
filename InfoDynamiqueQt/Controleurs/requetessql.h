#ifndef REQUETESSQL_H
#define REQUETESSQL_H

#include <QObject>

class RequetesSQL : public QObject
{
    Q_OBJECT

public:

    static const QString* afficherAppareils;
    static const QString* filtrerAppareils;

    static const QString* afficherToutesActions;
    static const QString* afficherActionsActives;
    static const QString* filtrerToutesActions;
    static const QString* filtrerActionsActives;
    static const QString* afficherEnsembles;

    static const QString* afficherClients;
    static const QString* filtrerClients;
    static const QString* appareilsPourClient;
    static const QString* toutesFichesPourAppareil;

    static const QString* afficherFiches;
    static const QString* filtrerFiches;
    static const QString* fichesActivesPourAppareil;
};

#endif // REQUETESSQL_H
