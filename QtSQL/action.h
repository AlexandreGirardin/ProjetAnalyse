#ifndef ACTION_H
#define ACTION_H

#include <QObject>

class Action
{
public:
    Action(int id, QString nom, QString description);
    QString id;
    QString nom;
    QString description;
};

#endif // ACTION_H
