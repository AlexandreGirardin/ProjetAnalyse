#include "Controleurs/controleurapplication.h"
#include <QApplication>
#include <Vues/vuegestionpiece.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    ControleurApplication controleurApplication;
    VueGestionPiece* vue = new VueGestionPiece();
    vue->setWindowTitle("slut");
    vue->setNom((QString) "banana");
    vue->setPrix(245.02);
    vue->setDescription((QString) "Soon you will all pay");
    vue->show();

    return a.exec();
}
