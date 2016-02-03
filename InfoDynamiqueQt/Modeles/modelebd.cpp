#include "modelebd.h"

ModeleBD::ModeleBD(QObject *parent) : QObject(parent) {}

int ModeleBD::getId() const
{
    return id;
}

void ModeleBD::setId(const int &value)
{
    id = value;
}

QString ModeleBD::out() const
{
    return QString("id: "+QString::number(id));
}
