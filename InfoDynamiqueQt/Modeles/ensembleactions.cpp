#include "Modeles/ensembleactions.h"

EnsembleActions::EnsembleActions(QObject* parent) : ModeleBD(parent)
{
    m_actions = new QList<Action*>;
}

QString EnsembleActions::nom() const
{
    return m_nom;
}

void EnsembleActions::setNom(const QString &value)
{
    m_nom = value;
}

QString EnsembleActions::description() const
{
    return m_description;
}

void EnsembleActions::setDescription(const QString &value)
{
    m_description = value;
}

int EnsembleActions::id() const
{
    return m_id;
}

void EnsembleActions::setId(const int &value)
{
    m_id = value;
}
QList<Action*>* EnsembleActions::actions() const
{
    return m_actions;
}

void EnsembleActions::setActions(QList<Action*>* value)
{
    m_actions = value;
}

QString EnsembleActions::out() const
{
    return QString::number(m_id) + " : " + m_description;
}

