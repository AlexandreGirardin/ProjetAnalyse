#include "dialog.h"
#include "ui_dialog.h"
#include "dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setId(int a_id) {
    ui->champId->setText(QString::number(a_id));
}

void Dialog::setNom(QString a_nom) {
    ui->champNom->setText(a_nom);
}

QString Dialog::getNom() {
    return ui->champNom->text();
}

void Dialog::setDescription(QString a_description) {
    ui->champDescription->setText(a_description);
}

QString Dialog::getDescription() {
    return ui->champDescription->text();
}
