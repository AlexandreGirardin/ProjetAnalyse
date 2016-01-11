#include "modelebd.h"

ModeleBD::ModeleBD(QObject *parent) :
    QObject(parent) {
}

int ModeleBD::getId() const {
    return id;
}

void ModeleBD::setId(int value) {
    id = value;
}

QString ModeleBD::out() {
    return QString("id: "+QString::number(id));
}
