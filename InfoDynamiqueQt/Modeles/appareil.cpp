#include "Modeles/appareil.h"

Appareil::Appareil(QObject* parent) :
    QObject(parent)
{
    setFabricant(NULL);
    setType(NULL);
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

QString Appareil::getNomFabricant() const
{
    if (fabricant != NULL) {
        return fabricant->getNom();
    } else {
        return QString("");
    }
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
    QString out = QString::number(id) + " ";
    if (fabricant != NULL) {
        out.append(fabricant->getNom() + " ");
    } else {
        out.append("fabricant indéfini ");
    }
    if (type != NULL) {
        out.append(type->getNom() + " ");
    } else {
        out.append("type indéfini ");
    }
    out.append(description);
    return out;
}
