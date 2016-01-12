#include "application.h"
#include "Controleurs/controleurapplication.h"
#include <QDebug>

Application::Application(int &argc, char **argv) :
    QApplication(argc, argv)
{
    m_instance = this;
    controleurBD = new ControleurBD(this);
    controleurBD->connecterDossiers();
    bd = controleurBD->getBd();
    actions = new MappeurActions(bd, this);
    appareils = new MappeurAppareils(bd, this);
    clients = new MappeurClients(bd, this);
    fabricants = new MappeurFabricants(bd,this);
    pieces = new MappeurPieces(bd, this);
    statuts = new MappeurStatuts(bd, this);
    techniciens = new MappeurTechniciens(bd, this);
    typesAppareils = new MappeurTypeAppareils(bd, this);
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

void Application::debug()
{
    QList<Action*>* listeActions = actions->getActions();
    for (int i = 0; i < listeActions->length(); ++i)
    {
        qDebug() << listeActions->at(i)->getId();
        qDebug() << listeActions->at(i)->getNom();
    }
}
