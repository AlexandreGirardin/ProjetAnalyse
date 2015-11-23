#include "gestionappareil.h"
#include "ui_gestionappareil.h"

gestionAppareil::gestionAppareil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionAppareil)
{
    ui->setupUi(this);
}

gestionAppareil::~gestionAppareil()
{
    delete ui;
}
