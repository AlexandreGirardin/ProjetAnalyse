#include "Mappeurs/mappeurtypeappareils.h"

#include "Controleurs/application.h"

#include <QVariant>
#include <QtSql/QSqlQuery>
#include <QDebug>

MappeurTypeAppareils::MappeurTypeAppareils(QObject* parent) : QObject(parent) {}

TypeAppareil* MappeurTypeAppareils::getTypeAppareil(const int &idType)
{
    TypeAppareil* type = NULL;
    QSqlQuery commande(*Application::bd);
    commande.prepare("SELECT * FROM types WHERE id=:idType");
    commande.bindValue(":idType", idType);
    commande.exec();
    if (commande.next()) {
        type = mapper(commande.record());
    }
    return type;
}

TypeAppareil* MappeurTypeAppareils::mapper(const QSqlRecord &ligne)
{
    TypeAppareil* type = new TypeAppareil();
    type->setId(ligne.value("id").toInt());
    type->setNom(ligne.value("nom").toString());
    return type;
}

QList<TypeAppareil*>* MappeurTypeAppareils::getTypesAppareil()
{
    QSqlQuery requete("SELECT * FROM types", *Application::bd);
    return mapper(requete);
}

QList<TypeAppareil*>* MappeurTypeAppareils::mapper(QSqlQuery &requete)
{
    QList<TypeAppareil*>* liste = new QList<TypeAppareil*>;
    QSqlRecord ligne = requete.record();
    int colId = ligne.indexOf("id");
    int colNom = ligne.indexOf("nom");
    while (requete.next()) {
        ligne = requete.record();
        TypeAppareil* type = new TypeAppareil(this);
        type->setId(ligne.value(colId).toInt());
        type->setNom(ligne.value(colNom).toString());
        liste->append(type);
    }
    return liste;
}
