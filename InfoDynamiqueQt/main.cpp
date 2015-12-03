#include <QApplication>
//#include <QDebug>

#include <Vues/vuegestionpiece.h>
#include "Controleurs/controleurapplication.h"
#include "Controleurs/controleurconnexion.h"
#include "Mappeurs/mappeurpieces.h"
#include "Modeles/piece.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    ControleurApplication controleurApplication;
//    VueGestionPiece* vue = new VueGestionPiece();
//    vue->setWindowTitle("slut");
//    vue->setNom((QString) "banana");
//    vue->setPrix(245.02);
//    vue->setDescription((QString) "Soon you will all pay");
//    vue->show();


    ControleurBD *db = new ControleurBD();
    MappeurPieces *map = new MappeurPieces(db);
    Piece *modele = map->getPiece(5);
    if (!(modele == NULL)) {
        VueGestionPiece* vue = new VueGestionPiece();
        vue->setWindowTitle("youpi");
        vue->setNom(modele->getNom());
        vue->setPrix(modele->getPrixDouble());
        vue->setDescription(modele->getDescription());
        vue->show();
    }



    return a.exec();
}
