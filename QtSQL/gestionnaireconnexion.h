#ifndef GESTIONNAIRECONNEXION_H
#define GESTIONNAIRECONNEXION_H

#include <QObject>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QDebug>

class GestionnaireConnexion : public QObject
{
    Q_OBJECT
public:
    explicit GestionnaireConnexion(QObject *parent = 0);
    QSqlDatabase db;
    QSqlQuery requete(const QString commande);

private:

signals:

public slots:
};


#endif // GESTIONNAIRECONNEXION_H
