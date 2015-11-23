#include "fragment.h"
#include "ui_fragment.h"

Fragment::Fragment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fragment)
{
    ui->setupUi(this);
}

Fragment::~Fragment()
{
    delete ui;
}
