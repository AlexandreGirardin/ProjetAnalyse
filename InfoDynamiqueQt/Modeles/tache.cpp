#include "Modeles/tache.h"


int Tache::getId() const
{
    return id;
}

void Tache::setId(int value)
{
    id = value;
}

Action* Tache::getAction() const
{
    return action;
}

void Tache::setAction(Action* value)
{
    action = value;
}

Statut* Tache::getStatut() const
{
    return statut;
}

void Tache::setStatut(Statut* value)
{
    statut = value;
}

QString Tache::out()
{
    return QString::number(id) + " " + action->getNom() + " " + statut->getNom();
}
Tache::Tache(QObject* parent) :
    QObject(parent)
{
}
