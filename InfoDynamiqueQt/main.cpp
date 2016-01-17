#include "Controleurs/application.h"

int main(int argc, char *argv[])
{
    Application application(argc, argv);
    application.demarrer();
//    application.debug();
    return application.exec();
}
