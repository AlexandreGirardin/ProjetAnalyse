#include "gestionpiece.h"
#include "ui_gestionpiece.h"

gestionPiece::gestionPiece(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionPiece)
{
    ui->setupUi(this);
}

gestionPiece::~gestionPiece()
{
    delete ui;
}
