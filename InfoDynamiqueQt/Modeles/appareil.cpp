#include "Modeles/appareil.h"

Appareil::Appareil(QObject* parent) :
    ModeleBD(parent)
{
    setFabricant(NULL);
    setType(NULL);
}

int Appareil::getIdClient() const
{
    return idClient;
}

void Appareil::setIdClient(const int &value)
{
    idClient = value;
}

int Appareil::getId() const
{
    return id;
}

void Appareil::setId(const int &value)
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
    if (value != NULL) {
        value->setParent(this);
    }
    fabricant = value;
}

TypeAppareil* Appareil::getType() const
{
    return type;
}

void Appareil::setType(TypeAppareil* value)
{
    if (value != NULL) {
        value->setParent(this);
    }
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
    QString out = QString("#") + QString::number(id) + " @"+QString::number(idClient) + " ";
    if (fabricant != NULL) {
        out.append(fabricant->getNom() + " ");
    } else {
        out.append("?fabricant? ");
    }
    if (type != NULL) {
        out.append(type->getNom() + " ");
    } else {
        out.append("?type? ");
    }
    out.append(motDePasse + " " + description);
    return out;
}
