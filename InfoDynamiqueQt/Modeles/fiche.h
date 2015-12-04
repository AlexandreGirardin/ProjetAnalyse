#ifndef FICHE_H
#define FICHE_H

#include <QObject>
#include "tache.h"
#include "piece.h"
#include "technicien.h"
#include "statut.h"

class Fiche : public QObject
{
    Q_OBJECT

private:
    int id;
    int priorite;
    QString commentaire;
    Statut *statut;

public:
    explicit Fiche(QObject *parent = 0);

    QList<Tache*> taches;
    QList<Piece*> pieces;
    QList<Technicien*> techniciens;

    int getId() const;
    void setId(int value);

    int getPriorite() const;
    void setPriorite(int value);

    QString getCommentaire() const;
    void setCommentaire(const QString &value);

    Statut *getStatut() const;
    void setStatut(Statut *value);

    QString out(void);

signals:

public slots:

};

#endif // FICHE_H
