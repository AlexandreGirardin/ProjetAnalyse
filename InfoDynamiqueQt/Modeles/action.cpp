#include "Modeles/action.h"

Action::Action(QObject* parent): ModeleBD(parent) {}

int Action::id() const
{
    return m_id;
}

void Action::setId(const int &value)
{
    m_id = value;
}

QString Action::nom() const
{
    return m_nom;
}

void Action::setNom(const QString &value)
{
    m_nom = value;
}

QString Action::description() const
{
    return m_description;
}

void Action::setDescription(const QString &value)
{
    m_description = value;
}

bool Action::etat() const
{
    return m_etat;
}

void Action::setEtat(const bool &value)
{
    m_etat = value;
}

QString Action::etatOut() const
{
    if (m_etat) {
        return QString("activée");
    } else {
        return QString("désactivée");
    }
}

QString Action::out() const
{
    return QString::number(m_id) + " " + m_nom + " " + m_description + " " + etatOut();
}
