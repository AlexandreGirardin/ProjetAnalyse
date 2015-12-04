#ifndef CONTROLEURCONNEXION_H
#define CONTROLEURCONNEXION_H

#include <QObject>
#include <QtSql/QSql>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>

class ControleurBD : public QObject
{
    Q_OBJECT

private:

    // La base de donnée principale
    QSqlDatabase bd;

public:

    explicit ControleurBD(QObject* parent = 0);

    /**
     * @brief getBd
     * @return La base de donnée principale
     */
    QSqlDatabase* getBd();

signals:

public slots:

};

#endif // CONTROLEURCONNEXION_H
