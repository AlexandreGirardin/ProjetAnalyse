#include "statut.h"


int Statut::getId() const
{
    return id;
}

void Statut::setId(int value)
{
    id = value;
}

QString Statut::getNom() const
{
    return nom;
}

void Statut::setNom(const QString &value)
{
    nom = value;
}
Statut::Statut(QObject *parent) :
    QObject(parent)
{
}