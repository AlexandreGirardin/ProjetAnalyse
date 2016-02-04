#include "Modeles/appareil.h"

Appareil::Appareil(QObject* parent) :
    ModeleBD(parent)
{
    setFabricant(NULL);
    setType(NULL);
}

int Appareil::idClient() const
{
    return m_idClient;
}

void Appareil::setIdClient(const int &value)
{
    m_idClient = value;
}

int Appareil::id() const
{
    return m_id;
}

void Appareil::setId(const int &value)
{
    m_id = value;
}

Fabricant* Appareil::fabricant() const
{
    return m_fabricant;
}

QString Appareil::nomFabricant() const
{
    if (m_fabricant != NULL) {
        return m_fabricant->nom();
    } else {
        return QString("");
    }
}

void Appareil::setFabricant(Fabricant* value)
{
    if (value != NULL) {
        value->setParent(this);
    }
    m_fabricant = value;
}

TypeAppareil* Appareil::type() const
{
    return m_type;
}

void Appareil::setType(TypeAppareil* value)
{
    if (value != NULL) {
        value->setParent(this);
    }
    m_type = value;
}

QString Appareil::nomType() const
{
    if (m_type != NULL) {
        return m_type->nom();
    } else {
        return QString("");
    }
}

QString Appareil::motDePasse() const
{
    return m_motDePasse;
}

void Appareil::setMotDePasse(const QString &value)
{
    m_motDePasse = value;
}

QString Appareil::description() const
{
    return m_description;
}

void Appareil::setDescription(const QString &value)
{
    m_description = value;
}

QString Appareil::out() const
{
    QString out = QString("#") + QString::number(m_id) + " @"+QString::number(m_idClient) + " ";
    if (m_fabricant != NULL) {
        out.append(m_fabricant->nom() + " ");
    } else {
        out.append("?fabricant? ");
    }
    if (m_type != NULL) {
        out.append(m_type->nom() + " ");
    } else {
        out.append("?type? ");
    }
    out.append(m_motDePasse + " " + m_description);
    return out;
}
