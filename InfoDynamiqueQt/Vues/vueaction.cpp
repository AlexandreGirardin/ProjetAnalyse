#include "vueaction.h"
#include "ui_vueaction.h"

VueAction::VueAction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VueAction)
{
    ui->setupUi(this);
}

VueAction::~VueAction()
{
    delete ui;
}

void VueAction::setNom(const QString &nom)
{
    ui->etiquetteNom->setText(nom);
}

void VueAction::setDescription(const QString &description)
{
    ui->etiquetteDescription->setText(description);
}
