#include "champformulaire.h"
#include "ui_champformulaire.h"

ChampFormulaire::ChampFormulaire(const QString& raison, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChampFormulaire)
{
    ui->setupUi(this);
    QObject::connect(ui->champ, SIGNAL(textChanged(QString)), this, SIGNAL(valeurChangee()));
    ui->iconeStatut->setToolTip(raison);
}

ChampFormulaire::~ChampFormulaire()
{
    delete ui;
}
QString ChampFormulaire::getTexte() const
{
    return ui->champ->text();
}

void ChampFormulaire::setTexte(const QString &valeur)
{
    ui->champ->setText(valeur);
}

void ChampFormulaire::setLectureSeule(const bool &valeur)
{
    ui->champ->setReadOnly(valeur);
    if (valeur) {
        ui->iconeStatut->hide();
    }
}

void ChampFormulaire::setTexteDefaut(const QString &valeur)
{
    ui->champ->setPlaceholderText(valeur);
}

void ChampFormulaire::setValide(const bool &valeur)
{
    ui->iconeStatut->setVisible(!valeur);
}

