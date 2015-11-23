#include "editionfiche.h"
#include "ui_editionfiche.h"

editionFiche::editionFiche(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editionFiche)
{
    ui->setupUi(this);
}

editionFiche::~editionFiche()
{
    delete ui;
}
