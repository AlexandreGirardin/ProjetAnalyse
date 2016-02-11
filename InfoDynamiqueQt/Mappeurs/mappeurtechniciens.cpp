#include "Mappeurs/mappeurtechniciens.h"

#include "Controleurs/application.h"

#include <QVariant>
#include <QtSql/QSqlQuery>

MappeurTechniciens::MappeurTechniciens(QObject* parent) : QObject(parent) {}

Technicien* MappeurTechniciens::getTechnicien(const int &id)
{
    Technicien* technicien = NULL;
    QSqlQuery commande(QSqlQuery(*Application::bd));
    commande.prepare("SELECT * FROM techniciens WHERE id=:id");
    commande.bindValue(":id", id);
    commande.exec();
    if (commande.next()) {
        technicien = mapper(commande.record());
    }
    return technicien;
}

Technicien* MappeurTechniciens::mapper(const QSqlRecord &ligne)
{
    Technicien* technicien = new Technicien();
    technicien->setId(ligne.value("id").toInt());
    technicien->setNom(ligne.value("nom").toString());
    return technicien;
}

QList<Technicien*>* MappeurTechniciens::getTechniciens()
{
    QSqlQuery requete(QSqlQuery("SELECT * FROM techniciens",*Application::bd));
    return mapper(requete);
}

QList<Technicien*>* MappeurTechniciens::technicienPourFiche(const int &idFiche)
{

}

QList<Technicien*>* MappeurTechniciens::mapper(QSqlQuery &requete)
{
    QList<Technicien*>* liste = new QList<Technicien*>;
    QSqlRecord ligne = requete.record();
    int colId = ligne.indexOf("id");
    int colNom = ligne.indexOf("nom");
    while (requete.next()) {
        ligne = requete.record();
        Technicien* technicien = new Technicien();
        technicien->setId(ligne.value(colId).toInt());
        technicien->setNom(ligne.value(colNom).toString());
        liste->append(technicien);
    }
    return liste;
}


