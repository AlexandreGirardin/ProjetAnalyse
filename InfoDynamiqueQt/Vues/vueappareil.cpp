#include "vueappareil.h"
#include "ui_vueappareil.h"

VueAppareil::VueAppareil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VueAppareil)
{
    ui->setupUi(this);
}

VueAppareil::~VueAppareil()
{
    delete ui;
}

QString VueAppareil::getType()
{
    return ui->champType->text();
}

QString VueAppareil::getFabricant()
{
    return ui->champFabricant->text();
}

QString VueAppareil::getMotDePasse()
{
    return ui->champMDP->text();
}

QString VueAppareil::getDescription()
{
    return ui->champDescription->document()->toPlainText();
}

void VueAppareil::setType(QString value)
{
    ui->champType->setText(value);
}

void VueAppareil::setFabricant(QString value)
{
    ui->champFabricant->setText(value);
}

void VueAppareil::setMotDePasse(QString value)
{
    ui->champMDP->setText(value);
}

void VueAppareil::setDescription(QString value)
{
    ui->champDescription->setText(value);
}
