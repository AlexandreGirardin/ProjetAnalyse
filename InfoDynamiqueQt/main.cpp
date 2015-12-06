#include <QApplication>
#include <QDebug>

#include <Vues/vuegestionpiece.h>
#include "Controleurs/controleurapplication.h"
#include "Controleurs/controleurbd.h"
#include "Mappeurs/mappeurpieces.h"
#include "Modeles/piece.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ControleurBD *db = new ControleurBD();
    ControleurApplication* ca = new ControleurApplication();
    ca->executer();

//    MappeurPieces *map = new MappeurPieces(db->getBd());
//    QList<Piece*>* modeles = map->getPieces();
//    for (int i = 0; i < modeles->count(); ++i) {
//        qDebug() << modeles->at(i)->out();
//    }

    return a.exec();
}
