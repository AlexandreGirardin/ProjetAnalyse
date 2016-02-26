#include "Tests/tests.h"
#include <QApplication>

int mainTests(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tests w;
    w.show();

    return a.exec();
}
