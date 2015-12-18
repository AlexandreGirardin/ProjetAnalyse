#include "vueprincipale.h"
#include "ui_vueprincipale.h"


VuePrincipale::VuePrincipale(QWidget* parent) : QMainWindow(parent), ui(new Ui::VuePrincipale) {
    ui->setupUi(this);
}

VuePrincipale::~VuePrincipale() {
    delete ui;
}

Ui::VuePrincipale* VuePrincipale::getUi() const
{
    return ui;
}
