#include <QApplication>
#include "gestionnaireconnexion.h"
#include "Modeles/fabricant.h"
#include "Fabrique/fabriquefabricant.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    GestionnaireConnexion gc;
//    FabriqueFabricant *fabrique = new FabriqueFabricant(&gc);
//    Fabricant *fabricant = fabrique->getFabricant(16);
//    qDebug() << fabricant->getId() << " " << fabricant->getNom();

    return a.exec();
}
