#include "vueconnexion.h"
#include "ui_vueconnexion.h"

#include <QDebug>
#include <QSortFilterProxyModel>
#include "Controleurs/controleurbd.h"

VueConnexion::VueConnexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VueConnexion)
{
    ui->setupUi(this);
    QObject::connect(this, SIGNAL(nouvelleSelection(QModelIndex)), this, SLOT(selectionnerModele(QModelIndex)));
}

VueConnexion::~VueConnexion()
{
    delete ui;
}

QString VueConnexion::getHote()
{
    return ui->champHote->text();
}

int VueConnexion::getPort()
{
    return ui->champPort->value();
}

QString VueConnexion::getUsager()
{
    return ui->champUsager->text();
}

QString VueConnexion::getMotDePasse()
{
    return ui->champMDP->text();
}

QDialogButtonBox* VueConnexion::getButtonBox()
{
    return ui->buttonBox;
}

void VueConnexion::setHote(QString value)
{
    ui->champHote->setText(value);
}

void VueConnexion::setPort(int value)
{
    ui->champPort->setValue(value);
}

void VueConnexion::setUsager(QString value)
{
    ui->champUsager->setText(value);
}

void VueConnexion::setMotDePasse(QString value)
{
    ui->champMDP->setText(value);
}

void VueConnexion::peuplerTableau(QAbstractTableModel* valeurs)
{
    QSortFilterProxyModel* modeleTriable = new QSortFilterProxyModel(ui->listeBd);
    modeleTriable->setSourceModel(valeurs);
    ui->listeBd->setModel(modeleTriable);
}

void VueConnexion::signalerSelection(QModelIndex nouveau, QModelIndex ancien)
{
    emit nouvelleSelection(nouveau);
}
