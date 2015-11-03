#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestionnaireconnexion.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GestionnaireConnexion gc;
    QSqlTableModel *stm = new QSqlTableModel(this, gc.db);
    stm->setTable("actions");
    stm->setEditStrategy(QSqlTableModel::OnManualSubmit);
    stm->select();
    stm->setHeaderData(0, Qt::Horizontal, tr("id"));
    stm->setHeaderData(1, Qt::Horizontal, tr("nom"));
    stm->setHeaderData(2, Qt::Horizontal, tr("description"));
    ui->tableView->setModel(stm);
//    QSqlQuery commande = gc.requete("SELECT * FROM actions");
//    while (commande.next()) {

//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
