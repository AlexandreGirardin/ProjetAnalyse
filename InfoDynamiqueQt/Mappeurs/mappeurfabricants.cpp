#include "Mappeurs/mappeurfabricants.h"

#include "Controleurs/application.h"

#include <QVariant>
#include <QtSql/QSqlQuery>

MappeurFabricants::MappeurFabricants(QObject* parent) :
    QObject(parent)
{
}

Fabricant* MappeurFabricants::getFabricant(const int id)
{
    Fabricant* fabricant = NULL;
    QString requete = "SELECT * FROM fabricants WHERE id="+QString::number(id);
    QSqlQuery* commande = new QSqlQuery(requete,*Application::bd);
    if (commande->next()) {
        fabricant = mapper(commande->record());
    }
    return fabricant;
}

Fabricant* MappeurFabricants::mapper(const QSqlRecord ligne)
{
    Fabricant* fabricant = new Fabricant(this);
    fabricant->setId(ligne.value("id").toInt());
    fabricant->setNom(ligne.value("nom").toString());
    return fabricant;
}

QList<Fabricant*>* MappeurFabricants::getFabricants()
{
    QList<Fabricant*>* liste = new QList<Fabricant*>();
    QString requete = "SELECT * FROM fabricants";
    QSqlQuery* commande = new QSqlQuery(requete,*Application::bd);
    QSqlRecord ligne = commande->record();
    int colId = ligne.indexOf("id");
    int colNom = ligne.indexOf("nom");
    while (commande->next()) {
        ligne = commande->record();
        Fabricant* fabricant = new Fabricant(this);
        fabricant->setId(ligne.value(colId).toInt());
        fabricant->setNom(ligne.value(colNom).toString());
        liste->append(fabricant);
    }
    return liste;
}
