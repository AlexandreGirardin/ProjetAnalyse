#ifndef MAPPEURFABRICANTS_H
#define MAPPEURFABRICANTS_H

#include "Modeles/fabricant.h"

#include <QSqlDatabase>
#include <QSqlRecord>

class MappeurFabricants {

    // Extrait des objets Fabricant de la base de données

public:

    /**
     * @brief getFabricant
     * @param id Le numéro du fabricant à mapper
     * @return le fabricant s'il existe, NULL autrement
     */
    static Fabricant* getFabricant(const int &id);

    /**
     * @brief getFabricants
     * @return La liste de tous les fabricants de la base de données
     */
    static QList<Fabricant*>* getFabricants();

private:

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en pièce
     * @return Le fabricant
     */
    static Fabricant* mapper(const QSqlRecord &ligne);

    /**
     * @brief ecrire
     * Effectue une opération SQL à l'intérieur d'une transaction
     * La transaction est annulée si l'opération échoue et validée autrement
     * @param action L'action à inclure dans l'opération SQL
     * @param commande La commande à exécuter
     * @return Succès de l'opération
     */
    static QList<Fabricant*>* mapper(QSqlQuery &requete);

};

#endif // MAPPEURFABRICANTS_H
