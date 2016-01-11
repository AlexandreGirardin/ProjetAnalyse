#include "Modeles/appareil.h"


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

QString Appareil::getNomType() const {
    if (type != NULL) {
        return type->getNom();
    } else {
        return QString("");
    }
}

QString Appareil::out()
{
    return QString::number(id) + " " + fabricant->getNom() + " " + type->getNom();
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
Appareil::Appareil(QObject* parent) :
    QObject(parent)
{
}
