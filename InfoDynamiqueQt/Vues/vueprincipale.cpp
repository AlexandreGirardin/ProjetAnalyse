#include "Vues/vueprincipale.h"
#include "ui_vueprincipale.h"

#include <QCloseEvent>
#include <QDebug>

void VuePrincipale::closeEvent (QCloseEvent *event)
{
    event->ignore();
    qDebug() << "intercepté";
    emit deconnexion();
//    QMainWindow::closeEvent(event);
//        event->accept();
}

VuePrincipale::VuePrincipale(QWidget* parent) : QMainWindow(parent), ui(new Ui::VuePrincipale)
{
    ui->setupUi(this);
//    QObject::connect(ui->menuDeconnexion, SIGNAL(triggered()), this, SIGNAL(deconnexion()));
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
