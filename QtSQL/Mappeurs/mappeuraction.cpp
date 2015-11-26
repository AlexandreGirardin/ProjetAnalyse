#include "mappeuraction.h"

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
    if (commande.next()) {
        action = new Action(commande.value(0).toInt(), commande.value(1).toString(), commande.value(2).toString());
    }
    return action;
}

QList<Action *> MappeurAction::getActions()
{
    QList<Action*> liste;
    QString requete = "SELECT * FROM actions";
    QSqlQuery commande = gc->requete(requete);
    while (commande.next()) {
        Action *action = new Action(commande.value(0).toInt(), commande.value(1).toString(), commande.value(2).toString());
        liste.append(action);
    }
    return liste;
}
