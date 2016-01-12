#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

#include "Controleurs/controleurbd.h"
#include "Mappeurs/mappeuractions.h"
#include "Mappeurs/mappeurappareils.h"
#include "Mappeurs/mappeurclients.h"
#include "Mappeurs/mappeurfabricants.h"
#include "Mappeurs/mappeurpieces.h"
#include "Mappeurs/mappeurstatuts.h"
#include "Mappeurs/mappeurtaches.h"
#include "Mappeurs/mappeurtechniciens.h"
#include "Mappeurs/mappeurtypeappareils.h"

class Application : public QApplication
{
    Q_OBJECT

public:

    explicit Application(int &argc, char **argv);
    static Application *getInstance();

    QSqlDatabase* bd;
    ControleurBD* controleurBD;
    MappeurActions* actions;
    MappeurAppareils* appareils;
    MappeurClients* clients;
    MappeurFabricants* fabricants;
    MappeurPieces* pieces;
    MappeurStatuts* statuts;
    MappeurTechniciens* techniciens;
    MappeurTypeAppareils* typesAppareils;

    void demarrer(); 
    void debug();
private:
    static Application *m_instance;

signals:

public slots:

};

#endif // APPLICATION_H
