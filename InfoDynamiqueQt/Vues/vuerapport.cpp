#include "vuerapport.h"
#include "ui_vuerapport.h"

vueRapport::vueRapport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vueRapport)
{
    ui->setupUi(this);
}

vueRapport::~vueRapport()
{
    delete ui;
}
