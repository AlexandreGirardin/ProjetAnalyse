#include "gestiontache.h"
#include "ui_gestiontache.h"

gestionTache::gestionTache(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionTache)
{
    ui->setupUi(this);
}

gestionTache::~gestionTache()
{
    delete ui;
}
