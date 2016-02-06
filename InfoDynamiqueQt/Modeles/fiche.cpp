#include "Modeles/fiche.h"

Fiche::Fiche(QObject* parent) : ModeleBD(parent) {}

int Fiche::priorite() const
{
    return m_priorite;
}

void Fiche::setPriorite(const int &value)
{
    m_priorite = value;
}

QString Fiche::commentaire() const
{
    return m_commentaire;
}

void Fiche::setCommentaire(const QString &value)
{
    m_commentaire = value;
}

Statut* Fiche::statut() const
{
    return m_statut;
}

void Fiche::setStatut(Statut* value)
{
    m_statut = value;
}

QString Fiche::out() const
{
    return QString::number(m_id) + " " + QString::number(m_priorite) + " " + m_commentaire + " " + m_statut->nom();
}

QList<Tache*>* Fiche::taches() const
{
    return m_taches;
}

void Fiche::setTaches(QList<Tache*>* value)
{
    m_taches = value;
}

QList<Piece*>* Fiche::pieces() const
{
    return m_pieces;
}

void Fiche::setPieces(QList<Piece*>* value)
{
    m_pieces = value;
}

QList<Technicien*>* Fiche::techniciens() const
{
    return m_techniciens;
}

void Fiche::setTechniciens(QList<Technicien*>* value)
{
    m_techniciens = value;
}
