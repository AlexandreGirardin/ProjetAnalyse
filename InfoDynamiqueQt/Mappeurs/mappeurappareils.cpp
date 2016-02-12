#include "mappeurappareils.h"

#include "Controleurs/application.h"
#include "Controleurs/controleurbd.h"
#include "mappeurfabricants.h"

#include <QDebug>
#include <QSqlError>

MappeurAppareils::MappeurAppareils(QObject* parent) : QObject(parent) {}

Appareil* MappeurAppareils::getAppareil(const int &id)
{
    Appareil* appareil = NULL;
    QSqlQuery requete(*Application::bd);
    requete.prepare("SELECT * FROM appareils WHERE id=:id");
    requete.bindValue(":id", id);
    requete.exec();
    if (requete.next()) {
        appareil = mapper(requete.record());
    }
    return appareil;
}

QList<Appareil*>* MappeurAppareils::appareilsPourClient(const int &idClient)
{
    QSqlQuery requete(*Application::bd);
    requete.prepare("SELECT * FROM appareils WHERE idClient=:idClient");
    requete.bindValue(":idClient", idClient);
    requete.exec();
    return mapper(requete);
}

Appareil* MappeurAppareils::mapper(const QSqlRecord &ligne)
{
    Appareil* appareil = new Appareil();
    appareil->setId(ligne.value("id").toInt());
    appareil->setDescription(ligne.value("description").toString());
    appareil->setMotDePasse(ligne.value("motDePasse").toString());
    appareil->setIdClient(ligne.value("idClient").toInt());
    appareil->setType(MappeurTypeAppareils::getTypeAppareil(ligne.value("idType").toInt()));
    appareil->setFabricant(MappeurFabricants::getFabricant(ligne.value("idFabricant").toInt()));
    return appareil;
}

QList<Appareil*>* MappeurAppareils::mapper(QSqlQuery &requete)
{
    QList<Appareil*>* liste = new QList<Appareil*>;
    QSqlRecord ligne = requete.record();
    int colId = ligne.indexOf("id");
    int colClient = ligne.indexOf("idClient");
    int colDesc = ligne.indexOf("description");
    int colMDP = ligne.indexOf("motDePasse");
    int colType = ligne.indexOf("type");
    int colFab = ligne.indexOf("idFabricant");
    while (requete.next()) {
        ligne = requete.record();
        Appareil* appareil = new Appareil();
        appareil->setId(ligne.value(colId).toInt());
        appareil->setDescription(ligne.value(colDesc).toString());
        appareil->setMotDePasse(ligne.value(colMDP).toString());
        appareil->setType(MappeurTypeAppareils::getTypeAppareil(ligne.value(colType).toInt()));
        appareil->setFabricant(MappeurFabricants::getFabricant(ligne.value(colFab).toInt()));
        appareil->setIdClient(ligne.value(colClient).toInt());
        liste->append(appareil);
    }
    return liste;
}

bool MappeurAppareils::mettreAJour(const Appareil *appareil)
{
    const QString commande("UPDATE appareils\
                            SET\
                                description=:description,\
                                motDePasse=:motDePasse,\
                                idType=:idType,\
                                idFabricant=:idFabricant\
                            WHERE id=:idAppareil");
    const bool succes = ecrire(appareil, commande);
    return succes;
}

bool MappeurAppareils::inserer(const Appareil *appareil)
{
    const QString commande("INSERT INTO appareils\
                                (idType, idFabricant, idClient, description, motDePasse)\
                            VALUES\
                                (:idType, :idFabricant, :idClient, :description, :motDePasse)");
    const bool succes = ecrire(appareil, commande);
    return succes;
}

bool MappeurAppareils::supprimer(const Appareil *appareil)
{
    const QString commande("DELETE FROM appareils WHERE id=:idAppareil");
    const bool succes = ecrire(appareil, commande);
    return succes;
}

QSqlQuery* MappeurAppareils::preparerRequete(const Appareil* appareil, const QString &commande)
{
    QSqlQuery* requete = new QSqlQuery(*Application::bd);
    requete->prepare(commande);
    requete->bindValue(":idAppareil", appareil->id());
    requete->bindValue(":idClient", appareil->idClient());
    requete->bindValue(":description", appareil->description());
    requete->bindValue(":motDePasse", appareil->motDePasse());
    requete->bindValue(":idType", appareil->type()->id());
    requete->bindValue(":idFabricant", appareil->fabricant()->id());
    return requete;
}

bool MappeurAppareils::ecrire(const Appareil* appareil, const QString &commande)
{
    QSqlDatabase bd = *Application::bd;
    bd.transaction();
    QSqlQuery* requete = preparerRequete(appareil, commande);
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
