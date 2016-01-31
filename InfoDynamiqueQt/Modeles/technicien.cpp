#include "Modeles/technicien.h"

Technicien::Technicien(QObject* parent) : ModeleBD(parent) {}

Technicien::Technicien(int a_id, QString a_nom, QObject* parent):
    ModeleBD(parent)
{
    setId(a_id);
    setNom(a_nom);
}

int Technicien::getId() const
{
    return id;
}

void Technicien::setId(const int &value)
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

QString Technicien::out()
{
    return QString::number(id) + " " + nom;
}
