#include "Controleurs/controleurapplication.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ControleurApplication controleurApplication;

    return a.exec();
}
