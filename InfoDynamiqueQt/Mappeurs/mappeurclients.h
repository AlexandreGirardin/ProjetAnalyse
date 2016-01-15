#ifndef MAPPEURCLIENTS_H
#define MAPPEURCLIENTS_H

#include <QObject>

#include "Modeles/client.h"

#include <QSqlDatabase>
#include <QSqlRecord>
#include <QVariant>


class MappeurClients : public QObject
{
    Q_OBJECT

    // Extrait des objets Client de la base de données

public:

    /**
     * @brief MappeurClients
     * @param a_bd La base de données à utiliser
     * @param parent
     */
    explicit MappeurClients(QObject* parent = 0);

    /**
     * @brief getClient
     * @param id Le numéro du client à mapper
     * @return Le client s'il existe, NULL autrement
     */
    Client* getClient(int id);

private:

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en client
     * @return Le client
     */
    Client* mapper(QSqlRecord ligne);

};

#endif // MAPPEURCLIENTS_H
