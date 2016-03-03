#include "vuegestionaction.h"
#include "ui_vuegestionaction.h"

#include "Vues/champformulaire.h"

#include <QLineEdit>
#include <QPushButton>

VueGestionAction::VueGestionAction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VueGestionAction)
{
    ui->setupUi(this);
    nom = new ChampFormulaire(tr("Ce champ est requis."), this);
    ui->formLayout->setWidget(1, QFormLayout::FieldRole, nom);
    connect(nom, SIGNAL(valeurChangee()), this, SLOT(verifierNom()));
    connect(nom, SIGNAL(validiteChangee()), this, SLOT(verifierOk()));
    verifierOk();
}

VueGestionAction::~VueGestionAction()
{
    delete ui;
}

bool VueGestionAction::getEtat() const
{
    return ui->caseActivee->isChecked();
}

void VueGestionAction::setEtat(const bool &value)
{
    ui->caseActivee->setChecked(value);
}

QString VueGestionAction::getDescription() const
{
    return ui->champDesc->document()->toPlainText();
}

void VueGestionAction::setDescription(const QString &value)
{
    ui->champDesc->setPlainText(value);
}

QString VueGestionAction::getNom() const
{
    return nom->getTexte();
}

void VueGestionAction::setNom(const QString &value)
{
    nom->setTexte(value);
}

void VueGestionAction::verifierNom()
{
    nom->setValide(!nom->getTexte().isEmpty());
}

void VueGestionAction::verifierOk()
{
    ui->buttonBox->button(QDialogButtonBox::Save)->setEnabled(nom->estValide());
}

