#ifndef TYPEAPPAREIL_H
#define TYPEAPPAREIL_H

#include <QObject>

class TypeAppareil : public QObject
{
    Q_OBJECT
public:
    explicit TypeAppareil(QObject *parent = 0);

    int id;
    QString nom;

    int getId() const;
    void setId(int value);

    QString getNom() const;
    void setNom(const QString &value);

    QString out(void);

signals:

public slots:

};

#endif // TYPEAPPAREIL_H
