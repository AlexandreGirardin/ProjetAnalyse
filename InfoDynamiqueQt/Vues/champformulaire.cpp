#include "champformulaire.h"
#include "ui_champformulaire.h"

ChampFormulaire::ChampFormulaire(const QString& raison, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChampFormulaire)
{
    valide = false;
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

QLineEdit *ChampFormulaire::getChamp() const
{
    return ui->champ;
}

void ChampFormulaire::setValide(const bool &valeur)
{
    if (valeur != valide) {
        valide = valeur;
        ui->iconeStatut->setVisible(!valeur);
        emit validiteChangee();
    }
}

bool ChampFormulaire::estValide() {
    return valide;
}

