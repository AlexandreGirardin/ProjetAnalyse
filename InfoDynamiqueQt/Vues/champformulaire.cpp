#include "champformulaire.h"
#include "ui_champformulaire.h"

ChampFormulaire::ChampFormulaire(const QString& raison, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChampFormulaire)
{
    ui->setupUi(this);
    QObject::connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SIGNAL(valeurChangee()));
    ui->pushButton->setToolTip(raison);
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

void ChampFormulaire::setValide(bool valeur)
{
    ui->pushButton->setVisible(!valeur);
}

