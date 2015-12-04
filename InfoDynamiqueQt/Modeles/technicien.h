#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include <QObject>

class Technicien : public QObject
{
    Q_OBJECT

private:

    int id;
    QString nom;

public:
    explicit Technicien(QObject *parent = 0);

    int getId() const;
    void setId(int value);

    QString getNom() const;
    void setNom(const QString &value);

    QString out(void);

signals:

public slots:

};

#endif // TECHNICIEN_H
