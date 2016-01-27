#include "Modeles/ensembleactions.h"


QString EnsembleActions::getNom() const
{
    return nom;
}

void EnsembleActions::setNom(const QString &value)
{
    nom = value;
}

QString EnsembleActions::getDescription() const
{
    return description;
}

void EnsembleActions::setDescription(const QString &value)
{
    description = value;
}

int EnsembleActions::getId() const
{
    return id;
}

void EnsembleActions::setId(int value)
{
    id = value;
}
EnsembleActions::EnsembleActions(QObject* parent) :
    QObject(parent)
{
}
QList<Action*>* EnsembleActions::getActions() const
{
    return actions;
}

void EnsembleActions::setActions(QList<Action*>* value)
{
    actions = value;
}


QString EnsembleActions::out()
{

}

