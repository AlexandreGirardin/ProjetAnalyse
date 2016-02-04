#include "Modeles/ensembleactions.h"

EnsembleActions::EnsembleActions(QObject* parent) : ModeleBD(parent) {}

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

void EnsembleActions::setId(const int &value)
{
    id = value;
}
QList<Action*>* EnsembleActions::getActions() const
{
    return actions;
}

void EnsembleActions::setActions(QList<Action*>* value)
{
    actions = value;
}


QString EnsembleActions::out() const
{
    return QString::number(id) + " : " + description;
}

