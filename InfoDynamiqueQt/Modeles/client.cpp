#include "Modeles/client.h"


QString Client::getPrenom() const
{
    return prenom;
}

void Client::setPrenom(const QString &value)
{
    prenom = value;
}
Client::Client(QObject* parent) :
    ModeleBD(parent) {
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

void Client::setAppareils(const QList<Appareil*> &value)
{
    *appareils = value;
}

QString Client::out() {
    return ModeleBD::out();
}
