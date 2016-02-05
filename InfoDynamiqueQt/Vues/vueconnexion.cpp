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
    ui->champHote->setText("localhost");
    ui->champPort->setValue(3307);
    ui->champUsager->setText("root");
    QObject::connect(this, SIGNAL(nouvelleSelection(QModelIndex)), this, SLOT(selectionnerModele(QModelIndex)));
}

VueConnexion::~VueConnexion()
{
    delete ui;
}

QString VueConnexion::getNom(const QModelIndex &index)
{
    int rangee = index.row();
    QModelIndex caseId = ui->listeBd->model()->index(rangee, 0);
    return ui->listeBd->model()->data(caseId).toString();
}

QString VueConnexion::getNomBD()
{
    return nomBD;
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
    QObject::connect(ui->listeBd->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(signalerSelection(QModelIndex,QModelIndex)));
}

void VueConnexion::selectionnerModele(const QModelIndex &index)
{
    nomBD = getNom(index);
    emit selectionValide(true);
}

void VueConnexion::signalerSelection(const QModelIndex &nouvelle, const QModelIndex&)
{
    emit nouvelleSelection(nouvelle);
}
