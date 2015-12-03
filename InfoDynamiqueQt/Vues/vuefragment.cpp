#include "vuefragment.h"
#include "ui_vuefragment.h"

VueFragment::VueFragment(QWidget *parent) : QWidget(parent), ui(new Ui::VueFragment) {
    ui->setupUi(this);
    QObject::connect(ui->bouton1, SIGNAL(clicked()), this, SLOT(changerEtiquette()));
}

VueFragment::~VueFragment() {
    delete ui;
}

void VueFragment::changerEtiquette()
{
    ui->etiquette->setText("Slut!");
}
