#include "Mappeurs/mappeurensembles.h"

#include "Controleurs/application.h"

#include <QDebug>
#include <QVariant>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

MappeurEnsembles::MappeurEnsembles(QObject* parent) : QObject(parent) {}

EnsembleActions* MappeurEnsembles::getEnsemble(const int &id)
{
    EnsembleActions* ensemble = NULL;
    QSqlQuery requete(*Application::bd);
    requete.prepare("SELECT * FROM ensembles WHERE id=:id");
    requete.bindValue(":id", id);
    requete.exec();
    if (requete.next()) {
        ensemble = mapper(requete.record());
    }
    return ensemble;
}

QList<EnsembleActions*>* MappeurEnsembles::getEnsembles()
{
    QSqlQuery requete("SELECT * FROM ensembles", *Application::bd);
    return mapper(requete);
}

EnsembleActions* MappeurEnsembles::mapper(const QSqlRecord &ligne)
{
    EnsembleActions* ensemble = new EnsembleActions(this);
    ensemble->setId(ligne.value("id").toInt());
    ensemble->setNom(ligne.value("nom").toString());
    ensemble->setDescription(ligne.value("description").toString());
    ensemble->setActions(Application::actions->actionsPourEnsemble(ensemble->getId()));
    return ensemble;
}

QList<EnsembleActions*>* MappeurEnsembles::mapper(QSqlQuery &requete)
{
    QList<EnsembleActions*>* liste = new QList<EnsembleActions*>();
    QSqlRecord ligne = requete.record();
    int colId = ligne.indexOf("id");
    int colNom = ligne.indexOf("nom");
    int colDesc = ligne.indexOf("description");
    while (requete.next()) {
        ligne = requete.record();
        EnsembleActions* ensemble = new EnsembleActions(this);
        ensemble->setId(ligne.value(colId).toInt());
        ensemble->setNom(ligne.value(colNom).toString());
        ensemble->setDescription(ligne.value(colDesc).toString());
        liste->append(ensemble);
    }
    return liste;
}

bool MappeurEnsembles::mettreAJour(const EnsembleActions* ensemble) const
{
    const QString commande("UPDATE actions\
                            SET\
                                nom=:nom,\
                                description=:description,\
                                etat=:etat\
                            WHERE id=:idEnsemble");
    const bool succes = ecrire(ensemble, commande);
    return succes;
}

QSqlQuery* MappeurEnsembles::preparerRequete(const EnsembleActions* ensemble, const QString &commande) const
{
    QSqlQuery* requete = new QSqlQuery(*Application::bd);
    requete->prepare(commande);
    requete->bindValue(":idEnsemble", ensemble->getId());
    requete->bindValue(":nom", ensemble->getNom());
    requete->bindValue(":description", ensemble->getDescription());
    return requete;
}

bool MappeurEnsembles::ecrire(const EnsembleActions* ensemble, const QString &commande) const
{
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    QSqlQuery* requete = preparerRequete(ensemble, commande);
    const bool succes = requete->exec();
    if (succes) {
        bd.commit();
    } else {
        qDebug() << requete->lastError();
        bd.rollback();
    }
    delete requete;
    return succes;
}
