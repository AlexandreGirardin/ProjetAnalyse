#include "fabricant.h"


int Fabricant::getId() const
{
    return id;
}

void Fabricant::setId(int value)
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

QString Fabricant::out()
{
    return QString::number(id) + " " + nom;
}

Fabricant::Fabricant(QObject *parent) :
    QObject(parent)
{
}

Fabricant::Fabricant(int a_id, QString a_nom, QObject *parent):
    QObject(parent)
{
    setId(a_id);
    setNom(a_nom);
}

