#include "vueprincipale.h"
#include "ui_vueprincipale.h"
#include "vuefragment.h"

VuePrincipale::VuePrincipale(QWidget *parent) : QMainWindow(parent), ui(new Ui::VuePrincipale) {

    ui->setupUi(this);
    this->showMaximized();
    ui->ongletClients->layout()->addWidget(new VueFragment);
    ui->ongletClients->layout()->addWidget(new VueFragment);
    ui->ongletClients->layout()->addWidget(new VueFragment);
    ui->ongletFiches->layout()->addWidget(new VueFragment);
    ui->ongletAppareils->layout()->addWidget(new VueFragment);
    ui->ongletTechniciens->layout()->addWidget(new VueFragment);
    ui->ongletActions->layout()->addWidget(new VueFragment);
    ui->ongletActions->layout()->addWidget(new VueFragment);
}

VuePrincipale::~VuePrincipale() {
    delete ui;
}
