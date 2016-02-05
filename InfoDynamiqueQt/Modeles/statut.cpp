#include "Modeles/statut.h"

Statut::Statut(QObject* parent) : ModeleBD(parent) {}

Statut::Statut(const int &a_id, const QString &a_nom, QObject* parent) :
    ModeleBD(parent)
{
    setId(a_id);
    setNom(a_nom);
}

int Statut::id() const
{
    return m_id;
}

void Statut::setId(const int &value)
{
    m_id = value;
}

QString Statut::nom() const
{
    return m_nom;
}

void Statut::setNom(const QString &value)
{
    m_nom = value;
}

QString Statut::out() const
{
    return QString::number(m_id) + " " + m_nom;
}
