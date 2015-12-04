#include <QApplication>

#include <Vues/vuegestionpiece.h>
#include "Controleurs/controleurapplication.h"
#include "Controleurs/controleurbd.h"
#include "Mappeurs/mappeurpieces.h"
#include "Modeles/piece.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ControleurBD *db = new ControleurBD();
    MappeurPieces *map = new MappeurPieces(db->getBd());
    Piece *modele = map->getPiece(6);
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
