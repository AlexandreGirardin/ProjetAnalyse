#include "controleurgestionensemble.h"

#include "Controleurs/application.h"

#include "Modeles/action.h"

#include "Vues/vuegestionensemble.h"

ControleurGestionEnsemble::ControleurGestionEnsemble(QObject *parent) :
    QObject(parent)
{
}

void ControleurGestionEnsemble::modifierEnsemble()
{
    VueGestionEnsemble* vue = new VueGestionEnsemble(Application::getVuePrincipale());
    vue->setActionsExistantes(Application::actions->getActions());
    vue->exec();
}
