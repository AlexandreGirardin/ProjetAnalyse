#include "vueauthentification.h"
#include "ui_vueauthentification.h"

VueAuthentification::VueAuthentification(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::VueAuthentification)
{
    ui->setupUi(this);
}

VueAuthentification::~VueAuthentification()
{
    delete ui;
}
