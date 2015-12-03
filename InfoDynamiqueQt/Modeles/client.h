#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include "appareil.h"

class Client : public QObject
{
    Q_OBJECT

private:
    int id;
    QString nom;
    QString telephone;
    QString adresse;
    QList<Appareil*> appareils;

public:
    explicit Client(QObject *parent = 0);

    QString getNom() const;
    void setNom(const QString &value);

    QString getTelephone() const;
    void setTelephone(const QString &value);

    QString getAdresse() const;
    void setAdresse(const QString &value);

    QList<Appareil *> getAppareils() const;
    void setAppareils(const QList<Appareil *> &value);

    int getId() const;
    void setId(int value);

    QString out(void);

signals:

public slots:

};

#endif // CLIENT_H
