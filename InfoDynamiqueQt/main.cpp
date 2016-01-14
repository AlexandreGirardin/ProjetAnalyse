#include "Controleurs/application.h"
#include <QDebug>

#include <Vues/vuegestionpiece.h>
#include "Controleurs/controleurbd.h"
#include "Mappeurs/mappeurpieces.h"
#include "Modeles/piece.h"

int main(int argc, char *argv[])
{
    Application application(argc, argv);
    application.demarrer();
//    application.debug();
    return application.exec();
}
