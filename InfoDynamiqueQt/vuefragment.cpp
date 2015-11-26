#include "vuefragment.h"
#include "ui_vuefragment.h"

VueFragment::VueFragment(QWidget *parent) : QWidget(parent), ui(new Ui::VueFragment) {
    ui->setupUi(this);
    QObject::connect(ui->bouton1, SIGNAL(clicked()), this, SLOT(changerEtiquette("Slut!")));
}

VueFragment::~VueFragment() {
    delete ui;
}

void VueFragment::changerEtiquette(QString a_etiquette)
{
    ui->etiquette->setText(a_etiquette);
}
