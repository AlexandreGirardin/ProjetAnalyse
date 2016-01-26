#include "vueconnexion.h"
#include "ui_vueconnexion.h"

VueConnexion::VueConnexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VueConnexion)
{
    ui->setupUi(this);
}

VueConnexion::~VueConnexion()
{
    delete ui;
}
