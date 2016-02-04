#include "modelebd.h"

ModeleBD::ModeleBD(QObject *parent) : QObject(parent) {}

int ModeleBD::id() const
{
    return m_id;
}

void ModeleBD::setId(const int &value)
{
    m_id = value;
}

QString ModeleBD::out() const
{
    return QString("id: "+QString::number(m_id));
}
