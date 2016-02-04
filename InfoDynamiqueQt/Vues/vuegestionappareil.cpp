#include "Vues/vuegestionappareil.h"
#include "ui_vuegestionappareil.h"

#include <QDebug>

VueGestionAppareil::VueGestionAppareil(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::VueGestionAppareil)
{
    ui->setupUi(this);
}

VueGestionAppareil::~VueGestionAppareil()
{
    delete ui;
    qDeleteAll(*types);
    delete types;
    qDeleteAll(*fabricants);
    delete fabricants;
}

void VueGestionAppareil::setTypes(QList<TypeAppareil*>* a_types)
{
    types = a_types;
    QList<TypeAppareil*>::const_iterator i;
    for (i = types->constBegin(); i != types->constEnd(); ++i) {
        ui->comboType->addItem((*i)->nom());
    }
    ui->comboType->adjustSize();
}

void VueGestionAppareil::setTypes(QList<TypeAppareil*>* a_types, const QString &a_type)
{
    setTypes(a_types);
    setType(a_type);
}

void VueGestionAppareil::setType(const QString &a_type)
{
    ui->comboType->setCurrentText(a_type);
}

TypeAppareil* VueGestionAppareil::getType() const
{
    TypeAppareil* type = NULL;
    int index = ui->comboType->currentIndex();
    if (index > -1 && index < types->length()) {
        type = types->at(index);
    }
    return type;
}

void VueGestionAppareil::setFabricants(QList<Fabricant*>* a_fabricants)
{
    fabricants = a_fabricants;
    for (QList<Fabricant*>::const_iterator i = fabricants->constBegin(); i != fabricants->constEnd(); ++i) {
        ui->comboFabricant->addItem((*i)->nom());
    }
    ui->comboType->adjustSize();
}

void VueGestionAppareil::setFabricants(QList<Fabricant*>* a_fabricants, const QString &a_fabricant)
{
    setFabricants(a_fabricants);
    setFabricant(a_fabricant);
}

void VueGestionAppareil::setFabricant(const QString &a_fabricant)
{
    ui->comboFabricant->setCurrentText(a_fabricant);
}

Fabricant* VueGestionAppareil::getFabricant() const
{
    Fabricant* fabricant = NULL;
    int index = ui->comboFabricant->currentIndex();
    if (index > -1 && index < fabricants->length()) {
        fabricant = fabricants->at(index);
    }
    return fabricant;
}

void VueGestionAppareil::setMotDePasse(const QString &a_motDePasse)
{
    ui->champMDP->setText(a_motDePasse);
}

QString VueGestionAppareil::getMotDePasse() const
{
    return ui->champMDP->text();
}

void VueGestionAppareil::setDescription(const QString &a_description)
{
    ui->champDescription->clear();
    ui->champDescription->appendPlainText(a_description);
}

QString VueGestionAppareil::getDescription() const
{
    return ui->champDescription->document()->toPlainText();
}
