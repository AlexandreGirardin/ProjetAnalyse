#include "vueprincipale.h"
#include "vueauthentification.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VueAuthentification w;
    w.show();

    return a.exec();
}
