#include "Modeles/fiche.h"

Fiche::Fiche(QObject* parent) : ModeleBD(parent) {}

int Fiche::getId() const
{
    return id;
}

void Fiche::setId(const int &value)
{
    id = value;
}

int Fiche::getPriorite() const
{
    return priorite;
}

void Fiche::setPriorite(const int &value)
{
    priorite = value;
}

QString Fiche::getCommentaire() const
{
    return commentaire;
}

void Fiche::setCommentaire(const QString &value)
{
    commentaire = value;
}

Statut* Fiche::getStatut() const
{
    return statut;
}

void Fiche::setStatut(Statut* value)
{
    statut = value;
}

QString Fiche::out() const
{
    return QString::number(id) + " " + QString::number(priorite) + " " + commentaire + " " + statut->getNom();
}

QList<Tache*>* Fiche::getTaches() const
{
    return taches;
}

void Fiche::setTaches(QList<Tache*>* value)
{
    taches = value;
}

QList<Piece*>* Fiche::getPieces() const
{
    return pieces;
}

void Fiche::setPieces(QList<Piece*>* value)
{
    pieces = value;
}

QList<Technicien*>* Fiche::getTechniciens() const
{
    return techniciens;
}

void Fiche::setTechniciens(QList<Technicien*>* value)
{
    techniciens = value;
}
