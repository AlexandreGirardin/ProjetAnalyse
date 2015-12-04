#ifndef CONTROLEURCONNEXION_H
#define CONTROLEURCONNEXION_H

#include <QObject>
#include <QtSql/QSql>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>

class ControleurBD : public QObject
{
    Q_OBJECT
public:
    explicit ControleurBD(QObject *parent = 0);
    QSqlQuery requete(const QString commande);

    QSqlDatabase *getBd();

private:
    QSqlDatabase bd;

signals:

public slots:

};

#endif // CONTROLEURCONNEXION_H
