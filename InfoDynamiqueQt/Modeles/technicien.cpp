#include "Modeles/technicien.h"

Technicien::Technicien(QObject* parent) :
    QObject(parent)
{
}

Technicien::Technicien(int a_id, QString a_nom, QObject* parent):
    QObject(parent)
{
    setId(a_id);
    setNom(a_nom);
}

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

QString Technicien::out()
{
    return QString::number(id) + " " + nom;
}
