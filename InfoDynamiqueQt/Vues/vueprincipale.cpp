#include "vueprincipale.h"
#include "ui_vueprincipale.h"


VuePrincipale::VuePrincipale(QWidget *parent) : QMainWindow(parent), ui(new Ui::VuePrincipale) {
    vueClients = new VueSecondaire();
    vueClientsAppareils = new VueSecondaire();
    vueClientsTaches = new VueSecondaire();
    vueAppareils = new VueSecondaire();
    vueFiches = new VueSecondaire();
    vueActions = new VueSecondaire();

    ui->setupUi(this);
    this->showMaximized();
    ui->ongletClients->layout()->addWidget(vueClients);
    ui->ongletFiches->layout()->addWidget(vueFiches);
    ui->ongletAppareils->layout()->addWidget(vueAppareils);
    ui->ongletActions->layout()->addWidget(vueActions);
}

VuePrincipale::~VuePrincipale() {
    delete ui;
}

Ui::VuePrincipale *VuePrincipale::getUi() const
{
    return ui;
}
