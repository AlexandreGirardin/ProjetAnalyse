#include "Modeles/piece.h"

Piece::Piece(QObject* parent) : ModeleBD(parent) {}

Piece::Piece(int a_id, QString a_nom, QString a_description, int a_prix, QObject* parent):
    ModeleBD(parent)
{
    setId(a_id);
    setNom(a_nom);
    setDescription(a_description);
    setPrix(a_prix);
}

int Piece::getId() const
{
    return id;
}

void Piece::setId(const int &value)
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

double Piece::getPrixDouble() const
{
    return ((double) prix) / 100;
}

int Piece::getPrixInt() const
{
    return prix;
}

void Piece::setPrix(const int &value)
{
    prix = value;
}

QString Piece::out()
{
    return QString::number(id) + " " + nom + " " + description + " " + QString::number(prix);
}
