#ifndef ACTION_H
#define ACTION_H

#include <QObject>

class Action
{

private:
    int id;
    QString nom;
    QString description;

public:
    explicit Action(QObject *parent = 0);
    Action(int, QString, QString);

    int getId() const;
    void setId(int value);
    void setId(const QString *a_idStr);

    QString getNom() const;
    void setNom(const QString &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    QString out(void);

public slots:
};

#endif // ACTION_H
