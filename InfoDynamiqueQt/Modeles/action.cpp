#include "Modeles/action.h"

Action::Action(QObject* parent): QObject(parent) {
}


int Action::getId() const
{
    return id;
}

void Action::setId(int value)
{
    id = value;
}

QString Action::getNom() const
{
    return nom;
}

void Action::setNom(const QString &value)
{
    nom = value;
}

QString Action::getDescription() const
{
    return description;
}

void Action::setDescription(const QString &value)
{
    description = value;
}

QString Action::out()
{
    return QString::number(id) + " " + nom + " " + description;
}
