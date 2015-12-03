#ifndef ACTION_H
#define ACTION_H

#include <QObject>

class Action : public QObject
{
    Q_OBJECT

private:
    int id;
    QString nom;
    QString description;

public:
    explicit Action(QObject *parent = 0);
    explicit Action(int a_id, QString a_nom, QString a_description, QObject *parent = 0);

    int getId() const;
    void setId(int value);

    QString getNom() const;
    void setNom(const QString &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    QString out(void);

public slots:
};

#endif // ACTION_H
