#include <QApplication>
#include "gestionnaireconnexion.h"
#include "Modeles/action.h"
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
        fenetre->setId(action->getId());
        fenetre->setNom(action->getNom());
        fenetre->setDescription(action->getDescription());
        if (fenetre->exec() == QDialog::Accepted) {
            qDebug() << action->getDescription();
            action->setNom(fenetre->getNom());
            action->setDescription(fenetre->getDescription());
            qDebug() << action->getDescription();
        }

    } else {
        qDebug() <<  "aucune donnée";
    }

    return a.exec();
}
