#include "vuegestionfiche.h"
#include "ui_vuegestionfiche.h"

VueGestionFiche::VueGestionFiche(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VueGestionFiche)
{
    ui->setupUi(this);
}

VueGestionFiche::~VueGestionFiche()
{
    delete ui;
}
