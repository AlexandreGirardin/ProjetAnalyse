#include "Controleurs/application.h"

int main(int argc, char *argv[])
{
    Application application(argc, argv);
    application.demarrer();
    int retour = application.exec();
    application.fermer();
    return retour;
}
