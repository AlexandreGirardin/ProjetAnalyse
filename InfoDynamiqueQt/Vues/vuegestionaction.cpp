#include "vuegestionaction.h"
#include "ui_vuegestionaction.h"

VueGestionAction::VueGestionAction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VueGestionAction)
{
    ui->setupUi(this);
}

VueGestionAction::~VueGestionAction()
{
    delete ui;
}

void VueGestionAction::setLectureSeule(const bool value)
{
    ui->caseActivee->setCheckable(!value);
    ui->champDesc->setReadOnly(value);
    ui->champNom->setReadOnly(value);
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
    return ui->champNom->text();
}

void VueGestionAction::setNom(const QString &value)
{
    ui->champNom->setText(value);
}

