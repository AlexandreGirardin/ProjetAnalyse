#ifndef ENSEMBLETACHES_H
#define ENSEMBLETACHES_H

#include <QObject>
#include "action.h"

class EnsembleTaches : public QObject
{
    Q_OBJECT

public:
    explicit EnsembleTaches(QObject *parent = 0);

    QList<Action*> actions;

    QString out(void);

signals:

public slots:

};

#endif // ENSEMBLETACHES_H
