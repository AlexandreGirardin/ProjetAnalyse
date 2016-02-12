#include "Mappeurs/mappeurstatuts.h"

#include "Controleurs/application.h"

#include <QVariant>
#include <QtSql/QSqlQuery>

Statut* MappeurStatuts::getStatutFiche(const int &idStatut)
{
    return getStatut(idStatut, QString("SELECT * FROM statutsFiche WHERE id=:idStatut"));
}

QList<Statut*>* MappeurStatuts::getStatutsFiche()
{
    QSqlQuery requete(QSqlQuery("SELECT * FROM statutsFiche", *Application::bd));
    return mapper(requete);
}

Statut* MappeurStatuts::getStatutTache(const int &idStatut)
{
    return getStatut(idStatut, QString("SELECT * FROM statutsTache WHERE id=:idStatut"));
}

Statut* MappeurStatuts::getStatut(const int &idStatut, const QString &commande)
{
    Statut* statut = NULL;
    QSqlQuery requete(*Application::bd);
    requete.prepare(commande);
    requete.bindValue(":idStatut", idStatut);
    requete.exec();
    if (requete.next()) {
        statut = mapper(requete.record());
    }
    return statut;
}

QList<Statut*>* MappeurStatuts::getStatutsTache() {
    QSqlQuery requete(QSqlQuery("SELECT * FROM statutsTache", *Application::bd));
    return mapper(requete);
}

Statut* MappeurStatuts::mapper(const QSqlRecord &ligne) {
    Statut* statut = new Statut();
    statut->setId(ligne.value("id").toInt());
    statut->setNom(ligne.value("nom").toString());
    return statut;
}

QList<Statut*>* MappeurStatuts::mapper(QSqlQuery &requete)
{
    QList<Statut*>* liste = new QList<Statut*>;
    QSqlRecord ligne = requete.record();
    int colId = ligne.indexOf("id");
    int colNom = ligne.indexOf("nom");
    while (requete.next()) {
        ligne = requete.record();
        Statut* statut = new Statut();
        statut->setId(ligne.value(colId).toInt());
        statut->setNom(ligne.value(colNom).toString());
        liste->append(statut);
    }
    return liste;
}
