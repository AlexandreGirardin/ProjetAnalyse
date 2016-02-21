#include "aidemappeurs.h"

#include "Controleurs/application.h"

#include <QSqlQuery>
#include <QSqlRecord>

int AideMappeurs::derniereInsertion()
{
    int id = -1;
    QSqlQuery requete("SELECT LAST_INSERT_ID() as id", *Application::bd);
    if (requete.next()) {
        id = requete.record().value("id").toInt();
    }
    return id;
}
