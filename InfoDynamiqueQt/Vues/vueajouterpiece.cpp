#include "vueajouterpiece.h"
#include "ui_vueajouterpiece.h"

VueAjouterPiece::VueAjouterPiece(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VueAjouterPiece)
{
    ui->setupUi(this);
}

VueAjouterPiece::~VueAjouterPiece()
{
    delete ui;
}
