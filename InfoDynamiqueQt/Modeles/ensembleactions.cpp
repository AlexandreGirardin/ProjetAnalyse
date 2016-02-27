#include "Modeles/ensembleactions.h"

#include "Modeles/action.h"

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

QList<Action*>* EnsembleActions::actions() const
{
    return m_actions;
}

void EnsembleActions::setActions(QList<Action*>* value)
{
    qDeleteAll(*m_actions);
    delete m_actions;
    m_actions = value;
}

QString EnsembleActions::out() const
{
    return QString::number(m_id) + " : " + m_description;
}

