#include "Vues/vuegestionensemble.h"
#include "ui_vuegestionensemble.h"

VueGestionEnsemble::VueGestionEnsemble(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::VueGestionEnsemble)
{
    ui->setupUi(this);
}

VueGestionEnsemble::~VueGestionEnsemble()
{
    delete ui;
}
