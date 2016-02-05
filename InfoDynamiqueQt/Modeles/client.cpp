#include "Modeles/client.h"

Client::Client(QObject* parent) : ModeleBD(parent)
{
    m_appareils = new QList<Appareil*>();
}

Client::~Client()
{
    qDeleteAll(*m_appareils);
    delete m_appareils;
}

QString Client::prenom() const
{
    return m_prenom;
}

void Client::setPrenom(const QString &value)
{
    m_prenom = value;
}

QString Client::nom() const
{
    return m_nom;
}

void Client::setNom(const QString &value)
{
    m_nom = value;
}

QString Client::telephone() const
{
    return m_telephone;
}

void Client::setTelephone(const QString &value)
{
    m_telephone = value;
}

QString Client::adresse() const
{
    return m_adresse;
}

void Client::setAdresse(const QString &value)
{
    m_adresse = value;
}

QList<Appareil*>* Client::appareils() const
{
    return m_appareils;
}

void Client::setAppareils(QList<Appareil*>* value)
{
    m_appareils = value;
}

QString Client::out() const
{
    return ModeleBD::out();
}
