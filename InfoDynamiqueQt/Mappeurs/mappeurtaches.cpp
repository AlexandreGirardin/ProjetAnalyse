#include "mappeurtaches.h"

#include "Controleurs/application.h"
#include "Mappeurs/mappeuractions.h"
#include "Mappeurs/mappeurstatuts.h"

#include <QSqlQuery>
#include <QSqlError>

Tache *MappeurTaches::getTache(const int &id)
{
    Tache* tache = NULL;
    QSqlQuery requete(*Application::bd);
    requete.prepare("SELECT * FROM taches WHERE id=:idTache");
    requete.bindValue(":idTache", id);
    requete.exec();
    if (requete.next()) {
        tache = mapper(requete.record());
    }
    return tache;
}

QList<Tache*>* MappeurTaches::getTaches()
{
    QSqlQuery requete("SELECT * FROM taches ORDER BY idFiche ASC", *Application::bd);
    return mapper(requete);
}

QList<Tache*>* MappeurTaches::tachesPourFiche(const int &idFiche)
{
    QString commande("SELECT * FROM taches WHERE idFiche=:idFiche");
    QSqlQuery requete(*Application::bd);
    requete.prepare(commande);
    requete.bindValue(":idFiche", idFiche);
    requete.exec();
    return mapper(requete);
}

QList<Tache*>* MappeurTaches::tachesPourAction(const int &idAction)
{
    QString commande("SELECT * FROM taches WHERE idAction=:idAction");
    QSqlQuery requete(*Application::bd);
    requete.prepare(commande);
    requete.bindValue(":idAction", idAction);
    requete.exec();
    return mapper(requete);
}

Tache* MappeurTaches::mapper(const QSqlRecord &ligne)
{
    Tache* tache = new Tache();
    tache->setIdFiche(ligne.value("idFiche").toInt());
    tache->setAction(MappeurActions::getAction(ligne.value("idAction").toInt()));
    tache->setStatut(MappeurStatuts::getStatutTache(ligne.value("idStatut").toInt()));
    return tache;
}

QList<Tache*>* MappeurTaches::mapper(QSqlQuery &requete)
{
    QList<Tache*>* liste = new QList<Tache*>;
    QSqlRecord ligne = requete.record();
    int colIdFiche = ligne.indexOf("idFiche");
    int colIdAction = ligne.indexOf("idAction");
    int colIdStatut = ligne.indexOf("idStatut");
    while (requete.next()) {
        ligne = requete.record();
        Tache* tache = new Tache();
        tache->setIdFiche(ligne.value(colIdFiche).toInt());
        tache->setAction(MappeurActions::getAction(ligne.value(colIdAction).toInt()));
        tache->setStatut(MappeurStatuts::getStatutTache(ligne.value(colIdStatut).toInt()));
        liste->append(tache);
    }
    return liste;
}
