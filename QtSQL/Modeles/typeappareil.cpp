#include "typeappareil.h"

TypeAppareil::TypeAppareil(QObject *parent) :
    QObject(parent)
{
}
QString TypeAppareil::getNom() const
{
    return nom;
}

void TypeAppareil::setNom(const QString &value)
{
    nom = value;
}

int TypeAppareil::getId() const
{
    return id;
}

void TypeAppareil::setId(int value)
{
    id = value;
}

