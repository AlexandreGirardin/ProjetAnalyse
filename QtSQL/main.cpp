#include <QApplication>
#include "gestionnaireconnexion.h"
#include "Modeles/action.h"
#include "Mappeurs/mappeuraction.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GestionnaireConnexion gc;
    MappeurAction *fabrique = new MappeurAction(&gc);
    QList<Action*> liste = fabrique->getActions();
    for (int i = 0; i < liste.count(); ++i) {
        Action* modele = liste.at(i);
        if (!(modele == NULL)) {
            qDebug() << modele->out();
        } else {
            qDebug() << i;
        }
    }

    return a.exec();
}
