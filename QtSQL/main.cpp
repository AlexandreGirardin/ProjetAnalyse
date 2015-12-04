#include <QApplication>
#include "gestionnaireconnexion.h"
#include "Modeles/technicien.h"
#include "Mappeurs/mappeurtechnicien.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GestionnaireConnexion gc;
    MappeurTechnicien *fabrique = new MappeurTechnicien(&gc);
    QList<Technicien*> liste = fabrique->getTechniciens();
    for (int i = 0; i < liste.count(); ++i) {
        Technicien* modele = liste.at(i);
        if (!(modele == NULL)) {
            qDebug() << modele->out();
        } else {
            qDebug() << i;
        }
    }

    return a.exec();
}
