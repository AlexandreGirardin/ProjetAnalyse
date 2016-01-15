#include "vuegestionaction.h"
#include "ui_vuegestionaction.h"

vuegestionaction::vuegestionaction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vuegestionaction)
{
    ui->setupUi(this);
}

vuegestionaction::~vuegestionaction()
{
    delete ui;
}
