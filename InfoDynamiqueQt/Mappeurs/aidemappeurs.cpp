#include "aidemappeurs.h"

#include "Controleurs/application.h"

#include <QDateTime>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

int AideMappeurs::derniereInsertion()
{
    int id = -1;
    QSqlQuery requete("SELECT LAST_INSERT_ID() as id", *Application::bd);
    if (requete.next()) {
        id = requete.record().value("id").toInt();
    }
    return id;
}

void AideMappeurs::noterModification()
{
    QSqlQuery requete("UPDATE date SET derniereModification = CURRENT_TIMESTAMP", *Application::bd);
    requete.exec();
    emit Application::get()->donneesModifiees();
}

QDateTime* AideMappeurs::derniereModification()
{
    QDateTime* date = new QDateTime;
    QSqlQuery requete("SELECT derniereModification FROM date", *Application::bd);
    requete.exec();
    if (requete.next()) {
        delete date;
        date = new QDateTime(requete.record().value("derniereModification").toDateTime());
    }
    return date;
}
