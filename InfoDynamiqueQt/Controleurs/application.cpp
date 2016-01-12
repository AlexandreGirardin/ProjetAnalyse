#include "application.h"
#include "Controleurs/controleurapplication.h"

Application::Application(int &argc, char **argv) :
    QApplication(argc, argv)
{
    m_instance = this;
    controleurBD = new ControleurBD(this);
    controleurBD->connecterDossiers();
    bd = controleurBD->getBd();
    typesAppareils = new MappeurTypeAppareils(bd, this);
    appareils = new MappeurAppareils(bd, this);
    clients = new MappeurClients(bd, this);
}

Application* Application::m_instance = NULL;

Application* Application::getInstance()
{
    return m_instance;
}

void Application::demarrer()
{
    ControleurApplication* ca = new ControleurApplication();
    ca->executer();
}
