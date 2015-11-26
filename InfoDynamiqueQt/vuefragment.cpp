#include "vuefragment.h"
#include "ui_vuefragment.h"

VueFragment::VueFragment(QWidget *parent) : QWidget(parent), ui(new Ui::VueFragment) {
    ui->setupUi(this);
}

VueFragment::~VueFragment() {
    delete ui;
}
