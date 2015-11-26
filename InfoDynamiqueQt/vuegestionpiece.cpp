#include "vuegestionpiece.h"
#include "ui_vuegestionpiece.h"

VueGestionPiece::VueGestionPiece(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VueGestionPiece)
{
    ui->setupUi(this);
}

VueGestionPiece::~VueGestionPiece()
{
    delete ui;
}
