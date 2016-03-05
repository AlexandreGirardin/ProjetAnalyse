#include "Controleurs/controleurconnexion.h"

#include "Controleurs/application.h"
#include "Controleurs/requetessql.h"
#include "Vues/vueconnexion.h"

#include <QSettings>
#include <QSqlQueryModel>

void ControleurConnexion::sauvegarderChamps()
{
    QSettings parametres;
    parametres.setValue("connexion/hote", m_bd.hostName());
    parametres.setValue("connexion/port", m_bd.port());
    parametres.setValue("connexion/usager", m_bd.userName());
    parametres.setValue("connexion/bd", m_bd.databaseName());
}

ControleurConnexion::ControleurConnexion(const QString &nom, QObject* parent)
    : QObject(parent)
{
    nomBd = nom;
}

QSqlDatabase* ControleurConnexion::bd()
{
    return &m_bd;
}

void ControleurConnexion::connecterDossiers()
{
    vue = new VueConnexion();
    connect(vue, SIGNAL(testerConnexion()), this, SLOT(sonderHote()));
    if (vue->exec() == vue->Accepted) {
        m_bd.setDatabaseName(vue->getNomBD());
        if (!m_bd.open()) {
            emit connexionRatee();
        } else {
            emit connexionEtablie();
            sauvegarderChamps();
        }
    } else {
        emit annule();
    }
    vue->deleteLater();
}
void ControleurConnexion::fermer()
{
    m_bd.close();
    m_bd = QSqlDatabase();
}

void ControleurConnexion::sonderHote()
{
    m_bd = QSqlDatabase();
    QSqlDatabase::removeDatabase(nomBd);
    m_bd = QSqlDatabase::addDatabase(QString("QMYSQL"), nomBd);
    m_bd.setHostName(vue->getHote());
    m_bd.setPort(vue->getPort());
    m_bd.setUserName(vue->getUsager());
    m_bd.setPassword(vue->getMotDePasse());
    if (m_bd.open()) {
        listerBd();
    } else {
        vue->viderListe();
    }
}

void ControleurConnexion::listerBd()
{
    QSqlQueryModel* basesDeDonnees = new QSqlQueryModel(this);
    basesDeDonnees->setQuery("show databases", m_bd);
    vue->peuplerTableau(basesDeDonnees);
}
