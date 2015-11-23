#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fragment.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    Fragment *fragmentClients = new Fragment(ui->ongletClients);
    Fragment *fragmentFiches = new Fragment(ui->ongletFiches);
    Fragment *fragmentAppareils = new Fragment(ui->ongletAppareils);
    Fragment *fragmentTechniciens = new Fragment(ui->ongletTechniciens);
    Fragment *fragmentActions = new Fragment(ui->ongletActions);
}

MainWindow::~MainWindow()
{
    delete ui;
}
