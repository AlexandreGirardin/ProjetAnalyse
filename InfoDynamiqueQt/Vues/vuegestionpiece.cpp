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

QString VueGestionPiece::getNom() const
{
    return ui->champNom->text();
}

void VueGestionPiece::setNom(const QString &valeur)
{
    ui->champNom->setText(valeur);
}

QString VueGestionPiece::getDescription() const
{
    return ui->champDescription->toPlainText();
}

void VueGestionPiece::setDescription(const QString &valeur)
{
    ui->champDescription->setPlainText(valeur);
}

double VueGestionPiece::getPrix() const
{
    return ui->champPrix->value();
}

void VueGestionPiece::setPrix(double valeur)
{
    ui->champPrix->setValue(valeur);
}
