#include "Controleurs/application.h"

int main(int argc, char *argv[])
{
    Application application(argc, argv);
    application.connecter();
    int retour = application.exec();
    application.deleteLater();
    return retour;
}
