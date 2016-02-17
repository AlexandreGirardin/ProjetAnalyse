#include "Modeles/statut.h"

Statut::Statut(QObject* parent) : ModeleBD(parent)
{
    m_id = -1;
    m_nom = QString();
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
    QString texte = QString::number(m_id) + " " + m_nom;
    return QString("???");
}
