#include "Mappeurs/mappeurstatuts.h"

#include "Controleurs/application.h"

#include <QVariant>
#include <QtSql/QSqlQuery>

MappeurStatuts::MappeurStatuts(QObject* parent)
    : QObject(parent)
{
}

Statut* MappeurStatuts::getStatutFiche(const int idStatut)
{
    Statut* statut = NULL;
    QSqlQuery requete(*Application::bd);
    requete.prepare("SELECT * FROM statutsFiche WHERE id=:idStatut");
    requete.bindValue(":idStatut", idStatut);
    requete.exec();
    if (requete.next()) {
        statut = mapper(requete.record());
    }
    return statut;
}

QList<Statut*>* MappeurStatuts::getStatutsFiche()
{
    QList<Statut*>* liste = new QList<Statut*>();
    QString requete = "SELECT * FROM statutsFiche";
    QSqlQuery* commande = new QSqlQuery(requete, *Application::bd);
    QSqlRecord ligne = commande->record();
    int colId = ligne.indexOf("id");
    int colNom = ligne.indexOf("nom");
    while (commande->next()) {
        ligne = commande->record();
        Statut* statut = new Statut(ligne.value(colId).toInt(),
                                    ligne.value(colNom).toString(), this);
        liste->append(statut);
    }
    return liste;
}

Statut* MappeurStatuts::getStatutAction(const int idStatut)
{
    Statut* statut = NULL;
    QSqlQuery requete(*Application::bd);
    requete.prepare("SELECT * FROM statutsActions WHERE id=:idStatut");
    requete.bindValue(":idStatut", idStatut);
    requete.exec();
    if (requete.next()) {
        statut = mapper(requete.record());
    }
    return statut;
}

QList<Statut*>* MappeurStatuts::getStatutsAction() {
    QSqlQuery requete(QSqlQuery("SELECT * FROM statutsAction", *Application::bd));
    return mapper(&requete);
}

Statut* MappeurStatuts::mapper(const QSqlRecord ligne) {
    Statut* statut = new Statut(this);
    statut->setId(ligne.value("id").toInt());
    statut->setNom(ligne.value("nom").toString());
    return statut;
}

QList<Statut*>* MappeurStatuts::mapper(QSqlQuery* requete)
{
    QList<Statut*>* liste = new QList<Statut*>;
    QSqlRecord ligne = requete->record();
    int colId = ligne.indexOf("id");
    int colNom = ligne.indexOf("nom");
    while (requete->next()) {
        ligne = requete->record();
        Statut* statut = new Statut(this);
        statut->setId(ligne.value(colId).toInt());
        statut->setNom(ligne.value(colNom).toString());
        liste->append(statut);
    }
    return liste;
}
