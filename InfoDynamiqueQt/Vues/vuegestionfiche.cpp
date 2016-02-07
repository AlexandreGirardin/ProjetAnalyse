#include "Vues/vuegestionfiche.h"
#include "ui_vuegestionfiche.h"

VueGestionFiche::VueGestionFiche(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::VueGestionFiche)
{
    ui->setupUi(this);
}

VueGestionFiche::~VueGestionFiche()
{
    delete ui;
}

void VueGestionFiche::setDescription(const QString &description)
{
    ui->champDescription->setText(description);
}

QString VueGestionFiche::getDescription() const
{
    return ui->champDescription->toPlainText();
}

void VueGestionFiche::setLectureSeule()
{

}

