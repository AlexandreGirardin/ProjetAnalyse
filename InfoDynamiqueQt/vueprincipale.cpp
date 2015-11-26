#include "vueprincipale.h"
#include "vuefragment.h"
#include "ui_vueprincipale.h"


VuePrincipale::VuePrincipale(QWidget *parent) : QMainWindow(parent), ui(new Ui::VuePrincipale) {
    VueFragment *fragmentClients = new VueFragment();
    VueFragment *fragmentClientsAppareils = new VueFragment();
    VueFragment *fragmentClientsTaches = new VueFragment();
    VueFragment *fragmentAppareils = new VueFragment();
    VueFragment *fragmentFiches = new VueFragment();
    VueFragment *fragmentActions = new VueFragment();
    VueFragment *fragmentEnsembles = new VueFragment();

    ui->setupUi(this);
    this->showMaximized();
    ui->ongletClients->layout()->addWidget(fragmentClients);
    ui->ongletFiches->layout()->addWidget(fragmentFiches);
    ui->ongletAppareils->layout()->addWidget(fragmentAppareils);
    ui->ongletActions->layout()->addWidget(fragmentActions);
    ui->ongletActions->layout()->addWidget(fragmentEnsembles);
}

VuePrincipale::~VuePrincipale() {
    delete ui;
}
