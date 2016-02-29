#include "Vues/vueprincipale.h"
#include "ui_vueprincipale.h"

#include <QCloseEvent>
#include <QPushButton>
#include <QResizeEvent>
#include <QDebug>

VuePrincipale::VuePrincipale(QWidget* parent) : QMainWindow(parent), ui(new Ui::VuePrincipale)
{
    ui->setupUi(this);
    configurerBoutonRecharger();
}

void VuePrincipale::configurerBoutonRecharger()
{
    boutonRecharger = new QPushButton(QIcon(":Images/refresh"), tr("Rafraîchir"), this);
    boutonRecharger->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    boutonRecharger->setFixedHeight(ui->onglets->tabBar()->tabRect(0).height());
    boutonRecharger->show();
    repositionnerBoutonRecharger();
}

void VuePrincipale::resizeEvent(QResizeEvent*) {
    repositionnerBoutonRecharger();
}

void VuePrincipale::repositionnerBoutonRecharger()
{
    boutonRecharger->move(width() - boutonRecharger->width(), 0);
}

QPushButton *VuePrincipale::getBoutonRecharger() const
{
    return boutonRecharger;
}

void VuePrincipale::closeEvent (QCloseEvent* event)
{
    event->ignore();
    emit deconnexion();
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
