#ifndef MAPPEURENSEMBLES_H
#define MAPPEURENSEMBLES_H

#include <QObject>

#include "Modeles/ensembleactions.h"

#include <QSqlQuery>

class MappeurEnsembles : public QObject
{
    Q_OBJECT

public:

    explicit MappeurEnsembles(QObject *parent = 0);

    EnsembleActions* getEnsemble(const int &id);
    QList<EnsembleActions*>* getEnsembles();

    bool inserer(EnsembleActions* ensemble) const;
    bool mettreAJour(const EnsembleActions* ensemble) const;
    bool supprimer(EnsembleActions* ensemble) const;

private:

    EnsembleActions* mapper(const QSqlRecord &ligne);
    QList<EnsembleActions*>* mapper(QSqlQuery &requete);
    bool ecrire(const EnsembleActions* ensemble, const QString &commande) const;
    bool ecrireActions(const EnsembleActions* ensemble, const QString &commande) const;
    QSqlQuery* preparerRequete(const EnsembleActions* ensemble, const QString &commande) const;
    int derniereInsertion() const;
};

#endif // MAPPEURENSEMBLES_H
