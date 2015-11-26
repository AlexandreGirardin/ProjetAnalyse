#include "fiche.h"


int Fiche::getId() const
{
    return id;
}

void Fiche::setId(int value)
{
    id = value;
}

int Fiche::getPriorite() const
{
    return priorite;
}

void Fiche::setPriorite(int value)
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

Statut *Fiche::getStatut() const
{
    return statut;
}

void Fiche::setStatut(Statut *value)
{
    statut = value;
}
Fiche::Fiche(QObject *parent) :
    QObject(parent)
{
}
