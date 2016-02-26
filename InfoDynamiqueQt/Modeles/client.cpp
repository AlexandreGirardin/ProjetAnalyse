#include "Modeles/client.h"


QString Client::courriel() const
{
    return m_courriel;
}

void Client::setCourriel(const QString &courriel)
{
    m_courriel = courriel;
}

Client::Client(QObject* parent) : ModeleBD(parent) {}

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

QString Client::out() const
{
    return ModeleBD::out();
}
