#include "Modeles/tache.h"

Tache::Tache(QObject* parent) : ModeleBD(parent) {}

int Tache::id() const
{
    return m_id;
}

void Tache::setId(const int &value)
{
    m_id = value;
}

Action* Tache::action() const
{
    return m_action;
}

void Tache::setAction(Action* value)
{
    m_action = value;
}

Statut* Tache::statut() const
{
    return m_statut;
}

void Tache::setStatut(Statut* value)
{
    m_statut = value;
}

QString Tache::out() const
{
    return QString::number(m_id) + " " + m_action->nom() + " " + m_statut->nom();
}
