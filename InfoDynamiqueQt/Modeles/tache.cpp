#include "Modeles/tache.h"

#include <QDebug>

Tache::Tache(QObject* parent) : QObject(parent)
{
    m_action = new Action(this);
    m_statut = new Statut(this);
}

QString Tache::commentaire() const
{
    return m_commentaire;
}

void Tache::setCommentaire(const QString &value)
{
    m_commentaire = value;
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
    return QString::number(m_idFiche) + " " + m_action->nom() + " " + m_statut->nom() + " " + m_commentaire;
}
