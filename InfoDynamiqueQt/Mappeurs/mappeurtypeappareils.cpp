#include "Mappeurs/mappeurtypeappareils.h"

#include "Controleurs/application.h"

#include <QVariant>
#include <QtSql/QSqlQuery>
#include <QDebug>

MappeurTypeAppareils::MappeurTypeAppareils(QObject* parent) :
    QObject(parent)
{
}

TypeAppareil* MappeurTypeAppareils::getTypeAppareil(int idType)
{
    TypeAppareil* type = NULL;
    QSqlQuery* commande = new QSqlQuery(*Application::bd);
    commande->prepare("SELECT * FROM types WHERE id=:idType");
    commande->bindValue(":idType", idType);
    commande->exec();
    if (commande->next()) {
        type = mapper(commande->record());
    } else {
        type = new TypeAppareil(-1, tr("Indéfini"));
    }
    return type;
}

TypeAppareil* MappeurTypeAppareils::mapper(QSqlRecord ligne)
{
    TypeAppareil* type = new TypeAppareil();
    type->setId(ligne.value("id").toInt());
    type->setNom(ligne.value("nom").toString());
    return type;
}

QList<TypeAppareil*>* MappeurTypeAppareils::getTypesAppareil(void)
{
    QList<TypeAppareil*>* liste = new QList<TypeAppareil*>();
    QString requete = "SELECT * FROM types";
    QSqlQuery* commande = new QSqlQuery(requete, *Application::bd);
    QSqlRecord ligne = commande->record();
    int colId = ligne.indexOf("id");
    int colNom = ligne.indexOf("nom");
    while (commande->next()) {
        ligne = commande->record();
        TypeAppareil* type = new TypeAppareil();
        type->setId(ligne.value(colId).toInt());
        type->setNom(ligne.value(colNom).toString());
        liste->append(type);
    }
    return liste;
}
