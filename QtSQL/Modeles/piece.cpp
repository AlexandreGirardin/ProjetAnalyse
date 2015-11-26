#include "piece.h"


int Piece::getId() const
{
    return id;
}

void Piece::setId(int value)
{
    id = value;
}

QString Piece::getNom() const
{
    return nom;
}

void Piece::setNom(const QString &value)
{
    nom = value;
}

QString Piece::getDescription() const
{
    return description;
}

void Piece::setDescription(const QString &value)
{
    description = value;
}

int Piece::getPrix() const
{
    return prix;
}

void Piece::setPrix(int value)
{
    prix = value;
}

QString Piece::out()
{
    return QString::number(id) + " " + nom + " " + description + " " + QString::number(prix);
}
Piece::Piece(QObject *parent) :
    QObject(parent)
{
}

Piece::Piece(int a_id, QString a_nom, QString a_description, int a_prix, QObject *parent): QObject(parent)
{
    id = a_id;
    nom = a_nom;
    description = a_description;
    prix = a_prix;
}
