#ifndef MAPPEURTACHES_H
#define MAPPEURTACHES_H

#include "Modeles/tache.h"

#include <QSqlQuery>

class MappeurTaches {

public:

    static Tache* getTache(const int &id);

    static QList<Tache*>* getTaches();

    static QList<Tache*>* tachesPourFiche(const int &idFiche);

    static QList<Tache*>* tachesPourAction(const int &idAction);

private:

    /**
     * @brief mapper
     * Extrait les informations d'un résultat d'une requête vers une action
     * @param ligne La ligne de la base de données à mapper en action
     * @return L'action
     */
    static Tache* mapper(const QSqlRecord &ligne);

    static QList<Tache*>* mapper(QSqlQuery &requete);
};

#endif // MAPPEURTACHES_H
