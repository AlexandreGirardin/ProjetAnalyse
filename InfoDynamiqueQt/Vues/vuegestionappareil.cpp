#include "Vues/vuegestionappareil.h"
#include "ui_vuegestionappareil.h"

VueGestionAppareil::VueGestionAppareil(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::VueGestionAppareil)
{
    ui->setupUi(this);
}

VueGestionAppareil::~VueGestionAppareil()
{
    delete ui;
}

void VueGestionAppareil::setTypes(QList<TypeAppareil*>* a_types)
{
    types = a_types;
    QList<TypeAppareil*>::const_iterator i;
    for (i = types->constBegin(); i != types->constEnd(); ++i) {
        ui->comboType->addItem((*i)->getNom());
    }
    ui->comboType->adjustSize();
}

void VueGestionAppareil::setTypes(QList<TypeAppareil *> *a_types, QString a_type)
{
    setTypes(a_types);
    setType(a_type);
}

void VueGestionAppareil::setType(QString a_type)
{
    ui->comboType->setCurrentText(a_type);
}

TypeAppareil* VueGestionAppareil::getType()
{
    TypeAppareil* type;
    int index = ui->comboType->currentIndex();
    if (index > -1 && index < types->length()) {
        type = types->at(index);
    } else {
        type = NULL;
    }
    return type;
}

void VueGestionAppareil::setFabricants(QList<Fabricant*>* a_fabricants)
{
    fabricants = a_fabricants;
    QList<Fabricant*>::const_iterator i;
    for (i = fabricants->constBegin(); i != fabricants->constEnd(); ++i) {
        ui->comboFabricant->addItem((*i)->getNom());
    }
    ui->comboType->adjustSize();
}

void VueGestionAppareil::setFabricants(QList<Fabricant *> *a_fabricants, QString a_fabricant)
{
    setFabricants(a_fabricants);
    setFabricant(a_fabricant);
}

void VueGestionAppareil::setFabricant(QString a_fabricant)
{
    ui->comboFabricant->setCurrentText(a_fabricant);
}

Fabricant* VueGestionAppareil::getFabricant()
{
    Fabricant* fabricant;
    int index = ui->comboFabricant->currentIndex();
    if (index > -1 && index < fabricants->length()) {
        fabricant = fabricants->at(index);
    } else {
        fabricant = NULL;
    }
    return fabricant;
}

void VueGestionAppareil::setMotDePasse(QString a_motDePasse)
{
    ui->champMDP->setText(a_motDePasse);
}

QString VueGestionAppareil::getMotDePasse()
{
    return ui->champMDP->text();
}

void VueGestionAppareil::setDescription(QString a_description)
{
    ui->champDescription->clear();
    ui->champDescription->appendPlainText(a_description);
}

QString VueGestionAppareil::getDescription()
{
    return ui->champDescription->document()->toPlainText();
}
