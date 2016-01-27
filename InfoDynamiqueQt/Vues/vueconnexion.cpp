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

QString VueConnexion::getHote()
{
    return ui->champHote->text();
}

int VueConnexion::getPort()
{
    return ui->champPort->value();
}

QString VueConnexion::getUsager()
{
    return ui->champUsager->text();
}

QString VueConnexion::getMotDePasse()
{
    return ui->champMDP->text();
}

void VueConnexion::setHote(QString value)
{
    ui->champHote->setText(value);
}

void VueConnexion::setPort(int value)
{
    ui->champPort->setValue(value);
}

void VueConnexion::setUsager(QString value)
{
    ui->champUsager->setText(value);
}

void VueConnexion::setMotDePasse(QString value)
{
    ui->champMDP->setText(value);
}
