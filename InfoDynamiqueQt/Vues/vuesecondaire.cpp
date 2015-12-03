#include "vuesecondaire.h"
#include "ui_vuesecondaire.h"

VueSecondaire::VueSecondaire(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueSecondaire)
{
    ui->setupUi(this);
}

VueSecondaire::~VueSecondaire()
{
    delete ui;
}

Ui::VueSecondaire *VueSecondaire::getUi() const
{
    return ui;
}
