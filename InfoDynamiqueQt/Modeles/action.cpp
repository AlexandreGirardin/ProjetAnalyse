#include "action.h"


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
Action::Action(int a_id, QString a_nom, QString a_description)
{
    id = a_id;
    nom = a_nom;
    description = a_description;
}

void Action::setId(const QString *a_idStr) {
    bool ok;
    int a_id = a_idStr->toInt(&ok);
    if (ok) {
        id = a_id;
    }
}
