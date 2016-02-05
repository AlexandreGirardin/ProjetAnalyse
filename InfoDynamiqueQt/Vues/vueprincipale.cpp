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

QTabWidget* VuePrincipale::onglets() const
{
    return ui->onglets;
}

QWidget* VuePrincipale::ongletActions() const
{
    return ui->ongletActions;
}

QWidget* VuePrincipale::ongletAppareils() const
{
    return ui->ongletAppareils;
}

QWidget* VuePrincipale::ongletClients() const
{
    return ui->ongletClients;
}

QWidget* VuePrincipale::ongletFiches() const
{
    return ui->ongletFiches;
}
