#include "Modeles/client.h"

Client::Client(QObject* parent) : ModeleBD(parent) {}

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

QString Client::getAdresse() const
{
    return adresse;
}

void Client::setAdresse(const QString &value)
{
    adresse = value;
}

QList<Appareil*>* Client::getAppareils() const
{
    return appareils;
}

void Client::setAppareils(QList<Appareil*>* value)
{
//    if (*appareils != *value) {
//        qDeleteAll(*appareils);
//        delete appareils;
//    }
    appareils = value;
}

QString Client::out() const
{
    return ModeleBD::out();
}
