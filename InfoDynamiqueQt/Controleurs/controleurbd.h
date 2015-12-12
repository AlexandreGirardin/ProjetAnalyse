#ifndef CONTROLEURCONNEXION_H
#define CONTROLEURCONNEXION_H

#include <QObject>
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

};

#endif // CONTROLEURCONNEXION_H
