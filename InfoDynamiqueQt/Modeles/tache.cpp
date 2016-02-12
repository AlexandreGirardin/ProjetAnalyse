#include "Modeles/tache.h"

#include <QDebug>

Tache::Tache(QObject* parent) : ModeleBD(parent)
{
    m_action = new Action();
    m_statut = new Statut();
}

int Tache::idFiche() const
{
    return m_idFiche;
}

void Tache::setIdFiche(const int &idFiche)
{
    m_idFiche = idFiche;
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
    if (value != NULL) {
        m_statut = value;
    }
}

QString Tache::out() const
{
    return QString::number(m_id) + " " + m_action->nom() + " " + m_statut->nom();
}
