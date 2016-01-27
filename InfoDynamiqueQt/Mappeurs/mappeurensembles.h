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
    QSqlQuery* preparerRequete(const EnsembleActions* ensemble, const QString* commande);
    bool mettreAJour(const EnsembleActions* ensemble);

private:

    bool ecrire(const EnsembleActions* ensemble, const QString* commande);

    EnsembleActions* mapper(const QSqlRecord ligne);
    QList<EnsembleActions*>* mapper(QSqlQuery *requete);
};

#endif // MAPPEURENSEMBLES_H
