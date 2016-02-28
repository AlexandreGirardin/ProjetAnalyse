#include "mappeurappareils.h"

#include "Controleurs/application.h"
#include "Mappeurs/aidemappeurs.h"
#include "Mappeurs/mappeurfabricants.h"
#include "Mappeurs/mappeurtypeappareils.h"
#include "Modeles/appareil.h"
#include "Modeles/fabricant.h"
#include "Modeles/typeappareil.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

Appareil* MappeurAppareils::get(const int &id)
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

QList<Appareil*>* MappeurAppareils::pourClient(const int &idClient)
{
    QSqlQuery requete(*Application::bd);
    requete.prepare("SELECT * FROM appareils WHERE idClient=:idClient");
    requete.bindValue(":idClient", idClient);
    requete.exec();
    return mapper(requete);
}

int MappeurAppareils::nombrePourClient(const int &idClient)
{
    int nombre = -1;
    QSqlQuery requete(*Application::bd);
    requete.prepare("SELECT count(*) as 'nb' FROM appareils WHERE idClient=:idClient");
    requete.bindValue(":idClient", idClient);
    requete.exec();
    if (requete.next()) {
        nombre = requete.record().value("nb").toInt();
    }
    return nombre;
}

Appareil* MappeurAppareils::mapper(const QSqlRecord &ligne)
{
    Appareil* appareil = new Appareil();
    appareil->setId(ligne.value("id").toInt());
    appareil->setDescription(ligne.value("description").toString());
    appareil->setMotDePasse(ligne.value("motDePasse").toString());
    appareil->setIdClient(ligne.value("idClient").toInt());
    appareil->setType(MappeurTypeAppareils::get(ligne.value("idType").toInt()));
    appareil->setFabricant(MappeurFabricants::get(ligne.value("idFabricant").toInt()));
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
        appareil->setType(MappeurTypeAppareils::get(ligne.value(colType).toInt()));
        appareil->setFabricant(MappeurFabricants::get(ligne.value(colFab).toInt()));
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

bool MappeurAppareils::inserer(Appareil *appareil)
{
    const QString commande("INSERT INTO appareils\
                                (idType, idFabricant, idClient, description, motDePasse)\
                            VALUES\
                                (:idType, :idFabricant, :idClient, :description, :motDePasse)");
    const bool succes = ecrire(appareil, commande);
    appareil->setId(AideMappeurs::derniereInsertion());
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
        Application::erreurEcriture(requete->lastError().text());
        bd.rollback();
    }
    delete requete;
    return succes;
}
