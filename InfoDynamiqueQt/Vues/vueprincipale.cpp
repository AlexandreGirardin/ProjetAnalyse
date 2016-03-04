#include "Vues/vueprincipale.h"
#include "ui_vueprincipale.h"

#include <QCloseEvent>
#include <QPushButton>
#include <QResizeEvent>

VuePrincipale::VuePrincipale(QWidget* parent) : QMainWindow(parent), ui(new Ui::VuePrincipale)
{
    ui->setupUi(this);
    configurerBoutonRecharger();
}

VuePrincipale::~VuePrincipale()
{
    delete ui;
}

void VuePrincipale::closeEvent (QCloseEvent* event)
{
    event->ignore();
    emit deconnexion();
}

void VuePrincipale::configurerBoutonRecharger()
{
    boutonRecharger = new QPushButton(QIcon(":Images/refresh"), tr("Rafraîchir"), this);
    boutonRecharger->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    boutonRecharger->setFixedHeight(ui->onglets->tabBar()->tabRect(0).height());
    boutonRecharger->hide();
    repositionnerBoutonRecharger();
}

void VuePrincipale::resizeEvent(QResizeEvent*) {
    repositionnerBoutonRecharger();
}

void VuePrincipale::repositionnerBoutonRecharger()
{
    boutonRecharger->move(width() - boutonRecharger->width(), 1);
}

QPushButton *VuePrincipale::getBoutonRecharger() const
{
    return boutonRecharger;
}

void VuePrincipale::cacherBoutonRecharger() const
{
    boutonRecharger->hide();
}

void VuePrincipale::afficherBoutonRecharger() const
{
    boutonRecharger->show();
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
