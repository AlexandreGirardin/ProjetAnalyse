#include "Mappeurs/mappeurfabricants.h"

#include "Controleurs/application.h"

#include <QSqlError>

Fabricant* MappeurFabricants::getFabricant(const int &id)
{
    Fabricant* fabricant = NULL;
    QString commande("SELECT * FROM fabricants WHERE id=:id");
    QSqlQuery requete(QSqlQuery(*Application::bd));
    requete.prepare(commande);
    requete.bindValue(":id", id);
    requete.exec();
    if (requete.next()) {
        fabricant = mapper(requete.record());
    }
    return fabricant;
}

QList<Fabricant*>* MappeurFabricants::getFabricants()
{
    QSqlQuery requete(QSqlQuery("SELECT * FROM fabricants",*Application::bd));
    return mapper(requete);
}

Fabricant* MappeurFabricants::mapper(const QSqlRecord &ligne)
{
    Fabricant* fabricant = new Fabricant();
    fabricant->setId(ligne.value("id").toInt());
    fabricant->setNom(ligne.value("nom").toString());
    return fabricant;
}

QList<Fabricant*>* MappeurFabricants::mapper(QSqlQuery &requete)
{
    QList<Fabricant*>* liste = new QList<Fabricant*>;
    QSqlRecord ligne = requete.record();
    int colId = ligne.indexOf("id");
    int colNom = ligne.indexOf("nom");
    while (requete.next()) {
        ligne = requete.record();
        Fabricant* fabricant = new Fabricant();
        fabricant->setId(ligne.value(colId).toInt());
        fabricant->setNom(ligne.value(colNom).toString());
        liste->append(fabricant);
    }
    return liste;
}
