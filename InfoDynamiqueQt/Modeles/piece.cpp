#include "Modeles/piece.h"

Piece::Piece(QObject* parent) : ModeleBD(parent) {}

QString Piece::nom() const
{
    return m_nom;
}

void Piece::setNom(const QString &value)
{
    m_nom = value;
}

QString Piece::description() const
{
    return m_description;
}

void Piece::setDescription(const QString &value)
{
    m_description = value;
}

double Piece::prixDouble() const
{
    return ((double) m_prix) / 100;
}

int Piece::prixInt() const
{
    return m_prix;
}

void Piece::setPrix(const int &value)
{
    m_prix = value;
}

QString Piece::out() const
{
    return QString::number(m_id) + " " + m_nom + " " + m_description + " " + QString::number(m_prix);
}
