#include "Modeles/tache.h"

Tache::Tache(QObject* parent) : ModeleBD(parent) {}

int Tache::getId() const
{
    return id;
}

void Tache::setId(const int &value)
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

QString Tache::out() const
{
    return QString::number(id) + " " + action->getNom() + " " + statut->getNom();
}
