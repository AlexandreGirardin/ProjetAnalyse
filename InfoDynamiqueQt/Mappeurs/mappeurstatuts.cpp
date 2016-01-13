#include "Mappeurs/mappeurstatuts.h"

#include <QVariant>
#include <QtSql/QSqlQuery>

MappeurStatuts::MappeurStatuts(QSqlDatabase* a_bd, QObject* parent)
    : QObject(parent)
{
    bd = a_bd;
}

Statut* MappeurStatuts::getStatutFiche(int id)
{
    Statut* statut = NULL;
    QString requete = "SELECT * FROM statutsFiche WHERE id="+QString::number(id);
    QSqlQuery* commande = new QSqlQuery(requete, *bd);
    if (commande->next()) {
        statut = mapper(commande->record());
    }
    return statut;
}

QList<Statut*>* MappeurStatuts::getStatutsFiche(void)
{
    QList<Statut*>* liste = new QList<Statut*>();
    QString requete = "SELECT * FROM statutsFiche";
    QSqlQuery* commande = new QSqlQuery(requete, *bd);
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

Statut* MappeurStatuts::getStatutAction(int id)
{
    Statut* statut = NULL;
    QString requete = "SELECT * FROM statutsAction WHERE id="+QString::number(id);
    QSqlQuery* commande = new QSqlQuery(requete, *bd);
    if (commande->next()) {
        statut = mapper(commande->record());
    }
    return statut;
}

QList<Statut*>* MappeurStatuts::getStatutsAction(void) {
    QList<Statut*>* liste = new QList<Statut*>();
    QString requete = "SELECT * FROM statutsAction";
    QSqlQuery* commande = new QSqlQuery(requete, *bd);
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

Statut* MappeurStatuts::mapper(QSqlRecord ligne) {
    return new Statut(ligne.value("id").toInt(),
                     ligne.value("nom").toString(), this);
}
