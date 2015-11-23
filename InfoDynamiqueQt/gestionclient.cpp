#include "gestionclient.h"
#include "ui_gestionclient.h"

gestionClient::gestionClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionClient)
{
    ui->setupUi(this);
}

gestionClient::~gestionClient()
{
    delete ui;
}
