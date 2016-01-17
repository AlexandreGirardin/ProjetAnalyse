#include "Modeles/client.h"

Client::Client(QObject* parent) :
    ModeleBD(parent)
{
}

QString Client::getPrenom() const
{
    return prenom;
}

void Client::setPrenom(const QString &value)
{
    prenom = value;
}

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

QString Client::getCourriel() const
{
    return adresse;
}

void Client::setCourriel(const QString &value)
{
    adresse = value;
}

QList<Appareil*>* Client::getAppareils() const
{
    return appareils;
}

void Client::setAppareils(const QList<Appareil*> &value)
{
    *appareils = value;
}

QString Client::out()
{
    return ModeleBD::out();
}
