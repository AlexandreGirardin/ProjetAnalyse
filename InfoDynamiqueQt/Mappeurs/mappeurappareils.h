#ifndef MAPPEURAPPAREILS_H
#define MAPPEURAPPAREILS_H

#include <QObject>

#include "Mappeurs/mappeurtypeappareils.h"

#include "Modeles/appareil.h"
#include "Modeles/client.h"

#include <QSqlDatabase>
#include <QSqlRecord>
#include <QVariant>

class MappeurAppareils : public QObject
{
    Q_OBJECT

    // Extrait des objets Appareil de la base de données

public:

    /**
     * @brief MappeurAppareils
     * @param a_bd La base de données à utiliser
     * @param parent
     */
    explicit MappeurAppareils(QSqlDatabase* a_bd, QObject* parent = 0);

    /**
     * @brief getAppareil
     * @param id Le numéro de l'appareil à mapper
     * @return L'appareil s'il existe, NULL autrement
     */
    Appareil* getAppareil(int id);

    QList<Appareil*>* appareilsPourClient(Client* client);

private:

    /**
     * @brief bd La base de données source
     */
    QSqlDatabase* bd;

    // Le mappeur utilisé pour fabriquer les objets Type des appareils
//    MappeurTypeAppareils* mappeurType;

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en appareil
     * @return L'appareil
     */
    Appareil* mapper(QSqlRecord ligne);


signals:

public slots:

};

#endif // MAPPEURAPPAREILS_H
