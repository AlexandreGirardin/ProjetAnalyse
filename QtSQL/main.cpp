#include <QCoreApplication>
#include <QApplication>

#include "gestionnaireconnexion.h"

bool createConnection();

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GestionnaireConnexion *gc = new GestionnaireConnexion();
}
