#ifndef TACHE_H
#define TACHE_H

#include <QObject>
#include "action.h"
#include "statut.h"

class Tache : public QObject
{
    Q_OBJECT

private:
    int id;
    Action *action;
    Statut *statut;

public:
    explicit Tache(QObject *parent = 0);

    int getId() const;
    void setId(int value);

    Action *getAction() const;
    void setAction(Action *value);

    Statut *getStatut() const;
    void setStatut(Statut *value);

    QString out(void);

signals:

public slots:

};

#endif // TACHE_H
