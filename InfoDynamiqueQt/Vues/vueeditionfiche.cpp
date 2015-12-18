#include "Vues/vueeditionfiche.h"
#include "ui_vueeditionfiche.h"

VueEditionFiche::VueEditionFiche(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::VueEditionFiche)
{
    ui->setupUi(this);
}

VueEditionFiche::~VueEditionFiche()
{
    delete ui;
}
