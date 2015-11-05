#include "dialog.h"
#include "ui_dialog.h"
#include "dialog.h"

Dialog::Dialog(QWidget *parent, Action *a_action) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lineEdit->setText(a_action->id);
    ui->lineEdit_2->setText(a_action->nom);
    ui->lineEdit_3->setText(a_action->description);
}

Dialog::~Dialog()
{
    delete ui;
}
