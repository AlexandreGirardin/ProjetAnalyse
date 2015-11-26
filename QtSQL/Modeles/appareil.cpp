#include "appareil.h"


int Appareil::getId() const
{
    return id;
}

void Appareil::setId(int value)
{
    id = value;
}

Fabricant *Appareil::getFabricant() const
{
    return fabricant;
}

void Appareil::setFabricant(Fabricant *value)
{
    fabricant = value;
}

TypeAppareil *Appareil::getType() const
{
    return type;
}

void Appareil::setType(TypeAppareil *value)
{
    type = value;
}
Appareil::Appareil(QObject *parent) :
    QObject(parent)
{
}
