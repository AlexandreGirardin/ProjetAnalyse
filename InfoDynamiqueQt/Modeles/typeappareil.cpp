#include "Modeles/typeappareil.h"

TypeAppareil::TypeAppareil(QObject* parent) : ModeleBD(parent) {}

//TypeAppareil::TypeAppareil(const int &a_id, const QString &a_nom, QObject *parent) :
//    ModeleBD(parent)
//{
//    setId(a_id);
//    setNom(a_nom);
//}

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

