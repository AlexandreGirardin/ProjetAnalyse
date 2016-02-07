#ifndef MAPPEURFICHES
#define MAPPEURFICHES

#include <QObject>

#include "Modeles/fiche.h"

#include <QSqlDatabase>
#include <QSqlRecord>

class MappeurFiches : public QObject
{
    Q_OBJECT

public:

    /**
     * @brief MappeurFiches
     * @param a_bd La base de données à utiliser
     * @param parent
     */
    explicit MappeurFiches(QObject* parent = 0);

    /**
     * @brief getFiche
     * @param id Le numéro de la fiche à mapper
     * @return le fabricant s'il existe, NULL autrement
     */
    static Fiche* getFiche(const int &id);

private:

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en pièce
     * @return Le fiche
     */
    static Fiche* mapper(const QSqlRecord &ligne);

};

#endif // MAPPEURFICHES

