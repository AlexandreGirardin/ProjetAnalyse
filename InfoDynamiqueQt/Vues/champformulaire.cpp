#include "champformulaire.h"
#include "ui_champformulaire.h"

ChampFormulaire::ChampFormulaire(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChampFormulaire)
{
    ui->setupUi(this);
}

ChampFormulaire::~ChampFormulaire()
{
    delete ui;
}
QString ChampFormulaire::getTexte() const
{
    return ui->lineEdit->text();
}

void ChampFormulaire::setTexte(const QString &value)
{
    ui->lineEdit->setText(value);
}

void ChampFormulaire::setLectureSeule(bool valeur)
{
    ui->lineEdit->setReadOnly(valeur);
    if (valeur) {
        ui->pushButton->hide();
    }
}

