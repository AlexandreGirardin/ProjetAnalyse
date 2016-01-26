#include "controleurgestionensemble.h"

#include "Controleurs/application.h"

#include "Vues/vuegestionensemble.h"

ControleurGestionEnsemble::ControleurGestionEnsemble(QObject *parent) :
    QObject(parent)
{
}

void ControleurGestionEnsemble::modifierEnsemble()
{
    VueGestionEnsemble* vue = new VueGestionEnsemble(Application::getVuePrincipale());
    vue->exec();
}
