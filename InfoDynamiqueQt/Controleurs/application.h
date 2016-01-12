#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

#include "Controleurs/controleurbd.h"
#include "Mappeurs/mappeurtypeappareils.h"
#include "Mappeurs/mappeurappareils.h"
#include "Mappeurs/mappeurclients.h"

class Application : public QApplication
{
    Q_OBJECT

public:

    explicit Application(int &argc, char **argv);
    static Application *getInstance();

    QSqlDatabase* bd;
    ControleurBD* controleurBD;
    MappeurTypeAppareils* typesAppareils;
    MappeurAppareils* appareils;
    MappeurClients* clients;

    void demarrer();

private:
    static Application *m_instance;

signals:

public slots:

};

#endif // APPLICATION_H
