#include "gestionfiche.h"
#include "ui_gestionfiche.h"

gestionFiche::gestionFiche(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionFiche)
{
    ui->setupUi(this);
}

gestionFiche::~gestionFiche()
{
    delete ui;
}
