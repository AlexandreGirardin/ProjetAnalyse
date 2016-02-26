#include "Vues/vuegestionpiece.h"
#include "ui_vuegestionpiece.h"

VueGestionPiece::VueGestionPiece(QWidget* parent) :
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

void VueGestionPiece::setNom(const QString &nom)
{
    ui->champNom->setText(nom);
}

QString VueGestionPiece::getDescription() const
{
    return ui->champDescription->toPlainText();
}

void VueGestionPiece::setDescription(const QString &description)
{
    ui->champDescription->setPlainText(description);
}

double VueGestionPiece::getPrix() const
{
    return ui->champPrix->value();
}

int VueGestionPiece::getPrixInt() const
{
    return getPrix()*100;
}

void VueGestionPiece::setPrix(const double &prix)
{
    ui->champPrix->setValue(prix);
}
