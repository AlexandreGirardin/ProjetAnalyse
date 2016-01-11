#include "Mappeurs/mappeurtypeappareils.h"
#include "Controleurs/controleurbd.h"

#include <QVariant>
#include <QtSql/QSqlQuery>
#include <QDebug>

MappeurTypeAppareils::MappeurTypeAppareils(QSqlDatabase* a_bd, QObject* parent) :
    QObject(parent)
{
    bd = a_bd;
}

TypeAppareil* MappeurTypeAppareils::getTypeAppareil(int idType) {
    TypeAppareil* type = NULL;
    QSqlQuery* commande = new QSqlQuery(QSqlDatabase::database(ControleurBD::nomBd()));
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

TypeAppareil* MappeurTypeAppareils::mapper(QSqlRecord ligne) {
    TypeAppareil* type = new TypeAppareil();
    type->setId(ligne.value("id").toInt());
    type->setNom(ligne.value("nom").toString());
    return type;
}

QList<TypeAppareil*>* MappeurTypeAppareils::getTypesAppareil(void) {
    QList<TypeAppareil*>* liste = new QList<TypeAppareil*>();
    QString requete = "SELECT * FROM types";
    QSqlQuery* commande = new QSqlQuery(requete, QSqlDatabase::database(ControleurBD::nomBd()));
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
