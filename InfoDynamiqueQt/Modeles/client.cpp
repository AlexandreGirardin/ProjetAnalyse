#include "client.h"


QString Client::getNom() const
{
    return nom;
}

void Client::setNom(const QString &value)
{
    nom = value;
}

QString Client::getTelephone() const
{
    return telephone;
}

void Client::setTelephone(const QString &value)
{
    telephone = value;
}

QString Client::getAdresse() const
{
    return adresse;
}

void Client::setAdresse(const QString &value)
{
    adresse = value;
}

QList<Appareil *> Client::getAppareils() const
{
    return appareils;
}

void Client::setAppareils(const QList<Appareil *> &value)
{
    appareils = value;
}

int Client::getId() const
{
    return id;
}

void Client::setId(int value)
{
    id = value;
}

QString Client::out()
{

}
Client::Client(QObject *parent) :
    QObject(parent)
{
}
