#include "Modeles/piece.h"

Piece::Piece(QObject* parent) : ModeleBD(parent) {}

//Piece::Piece(const int &a_id, const QString &a_nom, const QString &a_description, const int &a_prix, QObject* parent):
//    ModeleBD(parent)
//{
//    setId(a_id);
//    setNom(a_nom);
//    setDescription(a_description);
//    setPrix(a_prix);
//}

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
