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

    EnsembleActions* getEnsemble(const int id);
    QList<EnsembleActions*>* getEnsembles();
    bool mettreAJour(const EnsembleActions* ensemble);

private:

    EnsembleActions* mapper(const QSqlRecord ligne);
    QList<EnsembleActions*>* mapper(QSqlQuery *requete);
    bool ecrire(const EnsembleActions* ensemble, const QString* commande);
    QSqlQuery* preparerRequete(const EnsembleActions* ensemble, const QString* commande);
};

#endif // MAPPEURENSEMBLES_H