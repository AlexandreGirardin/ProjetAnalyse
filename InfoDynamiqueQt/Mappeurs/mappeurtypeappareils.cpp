#include "Mappeurs/mappeurtypeappareils.h"

#include <QVariant>
#include <QtSql/QSqlQuery>

MappeurTypeAppareils::MappeurTypeAppareils(QSqlDatabase* a_bd, QObject* parent) :
    QObject(parent)
{
    bd = a_bd;
}

TypeAppareil* MappeurTypeAppareils::getTypeAppareil(int id) {
    TypeAppareil* typeAppareil = NULL;
    QString requete = "SELECT * FROM types WHERE id="+QString::number(id);
    QSqlQuery* commande = new QSqlQuery(requete, *bd);
    if (commande->next()) {
        typeAppareil = mapper(commande->record());
    }
    return typeAppareil;
}

TypeAppareil* MappeurTypeAppareils::mapper(QSqlRecord ligne) {
    return new TypeAppareil(ligne.value("id").toInt(),
                     ligne.value("nom").toString(), this);
}

QList<TypeAppareil*>* MappeurTypeAppareils::getTypesAppareil(void) {
    QList<TypeAppareil*>* liste = new QList<TypeAppareil*>();
    QString requete = "SELECT * FROM types";
    QSqlQuery* commande = new QSqlQuery(requete, *bd);
    QSqlRecord ligne = commande->record();
    int colId = ligne.indexOf("id");
    int colNom = ligne.indexOf("nom");
    while (commande->next()) {
        ligne = commande->record();
        TypeAppareil* typeAppareil = new TypeAppareil(ligne.value(colId).toInt(),
                                 ligne.value(colNom).toString(), this);
        liste->append(typeAppareil);
    }
    return liste;
}
