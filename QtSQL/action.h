#ifndef ACTION_H
#define ACTION_H

#include <QObject>

class Action
{
public:
    Action(int id, QString nom, QString description);
    int id;
    QString nom;
    QString description;
    void setId(const int a_id);
    void setId(QString *a_idStr);

public slots:
    void setNom(QString a_nom);
    void setDescription(QString a_description);
};

#endif // ACTION_H
