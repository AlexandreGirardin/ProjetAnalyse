#include "Modeles/action.h"

Action::Action(QObject* parent): ModeleBD(parent)
{
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

void Action::setNom(const QString value)
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

bool Action::getEtat() const
{
    return etat;
}

void Action::setEtat(bool value)
{
    etat = value;
}

QString Action::etatOut()
{
    if (etat) {
        return QString("activée");
    } else {
        return QString("désactivée");
    }
}

QString Action::out()
{
    return QString::number(id) + " " + nom + " " + description + " " + etatOut();
}
