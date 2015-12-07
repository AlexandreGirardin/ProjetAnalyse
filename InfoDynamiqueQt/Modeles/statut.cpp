#include "statut.h"


int Statut::getId() const {
    return id;
}

void Statut::setId(int value) {
    id = value;
}

QString Statut::getNom() const {
    return nom;
}

void Statut::setNom(const QString &value) {
    nom = value;
}

QString Statut::out() {
    return QString::number(id) + " " + nom;
}

Statut::Statut(QObject *parent) :
    QObject(parent) {
}

Statut::Statut(int a_id, QString a_nom, QObject *parent) :
    QObject(parent) {
    setId(a_id);
    setNom(a_nom);
}
