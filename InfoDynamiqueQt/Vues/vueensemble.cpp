#include "vueensemble.h"
#include "ui_vueensemble.h"

VueEnsemble::VueEnsemble(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VueEnsemble)
{
    ui->setupUi(this);
}

VueEnsemble::~VueEnsemble()
{
    delete ui;
}
