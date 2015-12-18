#include "Vues/vuegestiontache.h"
#include "ui_vuegestiontache.h"

VueGestionTache::VueGestionTache(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::VueGestionTache)
{
    ui->setupUi(this);
}

VueGestionTache::~VueGestionTache()
{
    delete ui;
}
