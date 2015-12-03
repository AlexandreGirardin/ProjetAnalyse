#ifndef CONTROLEURCONNEXION_H
#define CONTROLEURCONNEXION_H

#include <QObject>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>

class ControleurBD : public QObject
{
    Q_OBJECT
public:
    explicit ControleurBD(QObject *parent = 0);
    QSqlDatabase db;
    QSqlQuery requete(const QString commande);

signals:

public slots:

};

#endif // CONTROLEURCONNEXION_H
