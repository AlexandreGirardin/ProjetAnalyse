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
    db->connecterDossiers();
    ControleurApplication* ca = new ControleurApplication();
    ca->executer();

    return a.exec();
}
