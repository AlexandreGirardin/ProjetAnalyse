#include "mainwindow.h"
#include <QApplication>
#include "gestionnaireconnexion.h"
#include "action.h"
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GestionnaireConnexion gc;
    QSqlQuery commande = gc.requete("SELECT * FROM actions");
    if (commande.next()) {
        Action *action = new Action(commande.value(0).toInt(), commande.value(1).toString(), commande.value(2).toString());
        Dialog *fenetre;
        fenetre = new Dialog();
        fenetre->setId(action->id);
        fenetre->setNom(action->nom);
        fenetre->setDescription(action->description);
        if (fenetre->exec() == QDialog::Accepted) {
            qDebug() << action->description;
            action->setNom(fenetre->getNom());
            action->setDescription(fenetre->getDescription());
            qDebug() << action->description;
        }

    } else {
        qDebug() <<  "aucune donnée";
    }

    return a.exec();
}
