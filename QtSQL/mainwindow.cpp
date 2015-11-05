#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestionnaireconnexion.h"
#include "action.h"
#include "QStringListModel"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringListModel *modele;
    modele = new QStringListModel(this);
    QStringList liste;
    GestionnaireConnexion gc;
    QSqlQuery commande = gc.requete("SELECT * FROM actions");
    while (commande.next()) {
        Action action(commande.value(0).toInt(), commande.value(1).toString(), commande.value(2).toString());
        liste.append(action.nom+" "+action.description);
    }

    modele->setStringList(liste);
    ui->listView->setModel(modele);
}

MainWindow::~MainWindow()
{
    delete ui;
}
