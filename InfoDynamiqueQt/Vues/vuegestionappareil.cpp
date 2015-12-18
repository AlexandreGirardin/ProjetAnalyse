#include "Vues/vuegestionappareil.h"
#include "ui_vuegestionappareil.h"

VueGestionAppareil::VueGestionAppareil(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::VueGestionAppareil)
{
    ui->setupUi(this);
}

VueGestionAppareil::~VueGestionAppareil()
{
    delete ui;
}
