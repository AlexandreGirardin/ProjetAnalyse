#include "vuegestionclient.h"
#include "ui_vuegestionclient.h"

VueGestionClient::VueGestionClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VueGestionClient)
{
    ui->setupUi(this);
}

VueGestionClient::~VueGestionClient()
{
    delete ui;
}
