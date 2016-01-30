#ifndef MAPPEURTECHNICIENS_H
#define MAPPEURTECHNICIENS_H

#include <QObject>

#include "Modeles/technicien.h"

#include <QSqlDatabase>
#include <QSqlRecord>

class MappeurTechniciens : public QObject
{
    Q_OBJECT

    // Extrait des objets Technicien de la base de données

public:

    /**
     * @brief MappeurTechnicien
     * @param parent
     */
    explicit MappeurTechniciens(QObject* parent = 0);

    /**
     * @brief getTechnicien
     * @param id Le numéro du technicien à mapper
     * @return Le technicien s'il existe, NULL autrement
     */
    Technicien* getTechnicien(const int &id);

    /**
     * @brief getTechniciens
     * @return La liste de tous les techniciens de la base de données
     */
    QList<Technicien*>* getTechniciens();

private:

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en technicien
     * @return Le technicien
     */
    Technicien* mapper(const QSqlRecord &ligne);

    QList<Technicien*>* mapper(QSqlQuery &requete);
};

#endif // MAPPEURTECHNICIENS_H
