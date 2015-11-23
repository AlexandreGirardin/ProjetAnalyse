#include "gestionensemble.h"
#include "ui_gestionensemble.h"

gestionEnsemble::gestionEnsemble(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionEnsemble)
{
    ui->setupUi(this);
}

gestionEnsemble::~gestionEnsemble()
{
    delete ui;
}
