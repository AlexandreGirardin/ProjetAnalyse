#include "vueappareil.h"
#include "ui_vueappareil.h"

#include <QLineEdit>
#include <QTextEdit>

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

QString VueAppareil::getType() const
{
    return ui->champType->text();
}

QString VueAppareil::getFabricant() const
{
    return ui->champFabricant->text();
}

QString VueAppareil::getMotDePasse() const
{
    return ui->champMDP->text();
}

QString VueAppareil::getDescription() const
{
    return ui->champDescription->document()->toPlainText();
}

void VueAppareil::setType(const QString &value)
{
    ui->champType->setText(value);
}

void VueAppareil::setFabricant(const QString &value)
{
    ui->champFabricant->setText(value);
}

void VueAppareil::setMotDePasse(const QString &value)
{
    ui->champMDP->setText(value);
}

void VueAppareil::setDescription(const QString &value)
{
    ui->champDescription->setText(value);
}
