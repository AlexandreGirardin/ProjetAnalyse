#include "Modeles/statut.h"

Statut::Statut(QObject* parent) : ModeleBD(parent) {}

Statut::Statut(const int &a_id, const QString &a_nom, QObject* parent) :
    ModeleBD(parent)
{
    setId(a_id);
    setNom(a_nom);
}

int Statut::getId() const
{
    return id;
}

void Statut::setId(const int &value)
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

QString Statut::out() const
{
    return QString::number(id) + " " + nom;
}
