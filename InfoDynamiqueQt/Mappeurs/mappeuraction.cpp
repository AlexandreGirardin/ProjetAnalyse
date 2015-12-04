#include "mappeuraction.h"
#include <QSqlRecord>

MappeurAction::MappeurAction(GestionnaireConnexion* a_gc, QObject *parent) :
    QObject(parent)
{
    gc = a_gc;
}

Action *MappeurAction::getAction(int id)
{
    Action *action = NULL;
    QString requete = "SELECT * FROM actions WHERE id="+QString::number(id);
    QSqlQuery commande = gc->requete(requete);
    int colId = commande.record().indexOf("id");
    int colNom = commande.record().indexOf("nom");
    int colDesc = commande.record().indexOf("description");
    if (commande.next()) {
        action = new Action(commande.value(colId).toInt(), commande.value(colNom).toString(), commande.value(colDesc).toString());
    }
    return action;
}

QList<Action *> MappeurAction::getActions()
{
    QList<Action*> liste;
    QString requete = "SELECT * FROM actions";
    QSqlQuery commande = gc->requete(requete);
    int colId = commande.record().indexOf("id");
    int colNom = commande.record().indexOf("nom");
    int colDesc = commande.record().indexOf("description");
    while (commande.next()) {
        Action *action = new Action(commande.value(colId).toInt(), commande.value(colNom).toString(), commande.value(colDesc).toString());
        liste.append(action);
    }
    return liste;
}
