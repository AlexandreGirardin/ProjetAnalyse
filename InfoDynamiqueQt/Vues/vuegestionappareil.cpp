#include "Vues/vuegestionappareil.h"
#include "ui_vuegestionappareil.h"

#include "Modeles/typeappareil.h"
#include "Modeles/fabricant.h"

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
//    qDeleteAll(*types);
//    delete types;
    ui->comboType->clear();
    for (QList<TypeAppareil*>::const_iterator i = a_types->constBegin(); i != a_types->constEnd(); ++i) {
        ui->comboType->addItem((*i)->nom(), (*i)->id());
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

int VueGestionAppareil::getType() const
{
    return ui->comboType->currentData().toInt();;
}

void VueGestionAppareil::setFabricants(QList<Fabricant*>* a_fabricants)
{
    for (QList<Fabricant*>::const_iterator i = a_fabricants->constBegin(); i != a_fabricants->constEnd(); ++i) {
        ui->comboFabricant->addItem((*i)->nom(), (*i)->id());
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

int VueGestionAppareil::getFabricant() const
{
    return ui->comboFabricant->currentData().toInt();
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
    ui->champDescription->setPlainText(a_description);
}

QString VueGestionAppareil::getDescription() const
{
    return ui->champDescription->document()->toPlainText();
}
