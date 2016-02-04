#include "Modeles/typeappareil.h"

TypeAppareil::TypeAppareil(QObject* parent) : ModeleBD(parent) {}

TypeAppareil::TypeAppareil(const int &a_id, const QString &a_nom, QObject *parent) :
    ModeleBD(parent)
{
    setId(a_id);
    setNom(a_nom);
}

int TypeAppareil::getId() const
{
    return id;
}

void TypeAppareil::setId(const int &value)
{
    id = value;
}

QString TypeAppareil::getNom() const
{
    return nom;
}

void TypeAppareil::setNom(const QString &value)
{
    nom = value;
}

QString TypeAppareil::out() const
{
    return QString::number(id) + " " + nom;
}

