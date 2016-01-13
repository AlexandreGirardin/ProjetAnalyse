#include "Vues/vueprincipale.h"
#include "ui_vueprincipale.h"


VuePrincipale::VuePrincipale(QWidget* parent) : QMainWindow(parent), ui(new Ui::VuePrincipale)
{
    ui->setupUi(this);
}

VuePrincipale::~VuePrincipale()
{
    delete ui;
}

Ui::VuePrincipale* VuePrincipale::getUi() const
{
    return ui;
}

QTabWidget* VuePrincipale::getOnglets() const
{
    return ui->onglets;
}

QWidget* VuePrincipale::getOngletActions() const
{
    return ui->ongletActions;
}

QWidget* VuePrincipale::getOngletAppareils() const
{
    return ui->ongletAppareils;
}

QWidget* VuePrincipale::getOngletClients() const
{
    return ui->ongletClients;
}

QWidget* VuePrincipale::getOngletFiches() const
{
    return ui->ongletFiches;
}
