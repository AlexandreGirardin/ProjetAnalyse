#ifndef REQUETESSQL_H
#define REQUETESSQL_H

#include <QObject>

class RequetesSQL : public QObject
{
    Q_OBJECT

public:

    explicit RequetesSQL(QObject *parent = 0);
    RequetesSQL* m_instance;

    static QString* afficherAppareils;
    static QString* filtrerAppareils;

    static QString* afficherToutesActions;
    static QString* afficherActionsActives;
    static QString* filtrerToutesActions;
    static QString* filtrerActionsActives;
    static QString* afficherEnsembles;

};

#endif // REQUETESSQL_H
