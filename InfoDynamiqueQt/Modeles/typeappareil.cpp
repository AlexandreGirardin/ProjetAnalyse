#include "Modeles/typeappareil.h"

TypeAppareil::TypeAppareil(QObject* parent) : ModeleBD(parent) {}

QString TypeAppareil::nom() const
{
    return m_nom;
}

void TypeAppareil::setNom(const QString &value)
{
    m_nom = value;
}

QString TypeAppareil::out() const
{
    return QString::number(m_id) + " " + m_nom;
}

