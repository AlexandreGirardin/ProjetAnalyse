#include "Modeles/fabricant.h"

Fabricant::Fabricant(QObject* parent) : ModeleBD(parent) {}

Fabricant::Fabricant(const int &a_id, const QString &a_nom, QObject* parent): ModeleBD(parent)
{
    id = a_id;
    nom = a_nom;
}

int Fabricant::getId() const
{
    return id;
}

void Fabricant::setId(const int &value)
{
    id = value;
}

QString Fabricant::getNom() const
{
    return nom;
}

void Fabricant::setNom(const QString &value)
{
    nom = value;
}

QString Fabricant::out() const
{
    return QString::number(id) + " " + nom;
}

