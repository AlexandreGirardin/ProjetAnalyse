#include "Modeles/technicien.h"

Technicien::Technicien(QObject* parent) : ModeleBD(parent) {}

Technicien::Technicien(const int &a_id, const QString &a_nom, QObject* parent):
    ModeleBD(parent)
{
    setId(a_id);
    setNom(a_nom);
}

int Technicien::id() const
{
    return m_id;
}

void Technicien::setId(const int &value)
{
    m_id = value;
}

QString Technicien::nom() const
{
    return m_nom;
}

void Technicien::setNom(const QString &value)
{
    m_nom = value;
}

QString Technicien::out() const
{
    return QString::number(m_id) + " " + m_nom;
}
