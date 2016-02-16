#include "Controleurs/controleurbd.h"

#include "Vues/vueconnexion.h"

#include "Controleurs/application.h"
#include "Controleurs/requetessql.h"

#include <QDebug>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQueryModel>

ControleurBD::ControleurBD(const QString &nom, QObject* parent)
    : QObject(parent)
{
    nomBd = nom;
}

QSqlDatabase* ControleurBD::bd()
{
    return &m_bd;
}

void ControleurBD::connecterDossiers()
{
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    vue = new VueConnexion(Application::vuePrincipale());
    QObject::connect(vue, SIGNAL(testerConnexion()), this, SLOT(sonderHote()));
    if (vue->exec() == vue->Accepted) {
        m_bd.setDatabaseName(vue->getNomBD());
        if (!m_bd.open()) {
//            qDebug() << "Erreur d'ouverture de la base de données";
            emit connexionRatee();
        } else {
            emit connexionEtablie();
            QSettings parametres;
            parametres.setValue("connexion/hote", m_bd.hostName());
            parametres.setValue("connexion/port", m_bd.port());
            parametres.setValue("connexion/usager", m_bd.userName());
        }
    } else {
        emit annule();
    }
    vue->deleteLater();

// Commenter ce qui précède et décommenter ce qui suit <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//    m_bd = QSqlDatabase::addDatabase(QString("QMYSQL"), nomBd);
//    m_bd.setHostName("localhost");
//    m_bd.setPort(3307);
//    m_bd.setUserName("root");
////    m_bd.setPassword("root");
//    m_bd.setDatabaseName("InfoDynamiqueDossiers");
//    if (!m_bd.open()) {
//        qDebug() << "Erreur d'ouverture de la base de données";
//        }
//    emit connexionEtablie();
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
}
void ControleurBD::fermer()
{
    m_bd.close();
    vue->deleteLater();
}

void ControleurBD::sonderHote()
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

void ControleurBD::listerBd()
{
    QSqlQueryModel* basesDeDonnees = new QSqlQueryModel(this);
    basesDeDonnees->setQuery("show databases", m_bd);
    vue->peuplerTableau(basesDeDonnees);
}
