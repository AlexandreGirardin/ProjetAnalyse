#include "Modeles/action.h"

Action::Action(QObject* parent): ModeleBD(parent) {}

int Action::getId() const
{
    return id;
}

void Action::setId(const int &value)
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

bool Action::getEtat() const
{
    return etat;
}

void Action::setEtat(const bool &value)
{
    etat = value;
}

QString Action::etatOut() const
{
    if (etat) {
        return QString("activée");
    } else {
        return QString("désactivée");
    }
}

QString Action::out() const
{
    return QString::number(id) + " " + nom + " " + description + " " + etatOut();
}
