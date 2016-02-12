#include "Modeles/statut.h"

Statut::Statut(QObject* parent) : ModeleBD(parent)
{
    m_id = -1;
    m_nom = QString("");
}

Statut::Statut(const int &a_id, const QString &a_nom, QObject* parent) :
    ModeleBD(parent)
{
    setId(a_id);
    setNom(a_nom);
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
