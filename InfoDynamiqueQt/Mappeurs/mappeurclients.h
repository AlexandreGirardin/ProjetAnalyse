#ifndef MAPPEURCLIENTS_H
#define MAPPEURCLIENTS_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QVariant>

#include "Controleurs/controleurbd.h"
#include "Modeles/client.h"


class MappeurClients : public QObject
{
    Q_OBJECT
public:
    explicit MappeurClients(QSqlDatabase *a_bd, QObject *parent = 0);

    /**
     * @brief getClient
     * @param id Le numéro du client à mapper
     * @return Le client s'il existe, NULL autrement
     */
    Client* getClient(int id);

private:

    /**
     * @brief bd La base de données source
     */
    QSqlDatabase* bd;

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en client
     * @return Le client
     */
    Client* mapper(QSqlRecord ligne);
signals:

public slots:

};

#endif // MAPPEURCLIENTS_H
