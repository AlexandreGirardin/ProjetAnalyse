#include "Mappeurs/mappeurfiches.h"

#include "Controleurs/application.h"

#include <QDebug>
#include <QSqlError>

MappeurFiches::MappeurFiches(QObject* parent) : QObject(parent)
{
}

Fiche *MappeurFiches::getFiche(const int &id)
{
}
