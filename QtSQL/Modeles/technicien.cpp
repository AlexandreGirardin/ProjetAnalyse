#include "technicien.h"


int Technicien::getId() const
{
    return id;
}

void Technicien::setId(int value)
{
    id = value;
}

QString Technicien::getNom() const
{
    return nom;
}

void Technicien::setNom(const QString &value)
{
    nom = value;
}
Technicien::Technicien(QObject *parent) :
    QObject(parent)
{
}
