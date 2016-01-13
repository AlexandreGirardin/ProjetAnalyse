#include "Modeles/appareil.h"

Appareil::Appareil(QObject* parent) :
    QObject(parent)
{
}

int Appareil::getId() const
{
    return id;
}

void Appareil::setId(int value)
{
    id = value;
}

Fabricant* Appareil::getFabricant() const
{
    return fabricant;
}

void Appareil::setFabricant(Fabricant* value)
{
    fabricant = value;
}

TypeAppareil* Appareil::getType() const
{
    return type;
}

void Appareil::setType(TypeAppareil* value)
{
    type = value;
}

QString Appareil::getNomType() const
{
    if (type != NULL) {
        return type->getNom();
    } else {
        return QString("");
    }
}

QString Appareil::getMotDePasse() const
{
    return motDePasse;
}

void Appareil::setMotDePasse(const QString &value)
{
    motDePasse = value;
}

QString Appareil::getDescription() const
{
    return description;
}

void Appareil::setDescription(const QString &value)
{
    description = value;
}

QString Appareil::out()
{
    return QString::number(id) + " " + fabricant->getNom() + " " + type->getNom();
}
