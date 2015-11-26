#include "vueprincipale.h"
#include "vueauthentification.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VuePrincipale w;
    w.show();

    return a.exec();
}
