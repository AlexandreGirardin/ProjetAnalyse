#include "vueconnexion.h"
#include "ui_vueconnexion.h"

#include <QSortFilterProxyModel>
#include "Controleurs/controleurbd.h"

VueConnexion::VueConnexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VueConnexion)
{
    ui->setupUi(this);
    setWindowTitle(tr("Connexion"));
    ui->champHote->setText("localhost");
    ui->champPort->setValue(3307);
    ui->champUsager->setText("root");
    QObject::connect(ui->boutonConnecter, SIGNAL(clicked()), this, SIGNAL(testerConnexion()));
    boutonOk = new QPushButton(tr("Ok"), this);
    boutonOk->setEnabled(false);
    ui->buttonBox->addButton(boutonOk, QDialogButtonBox::AcceptRole);
    QObject::connect(ui->listeBd, SIGNAL(activated(QModelIndex)), this, SLOT(activerBoutonOk()));
}

VueConnexion::~VueConnexion()
{
    delete ui;
}

QString VueConnexion::getNomBD() const
{
    return ui->listeBd->currentIndex().data().toString();
}

QString VueConnexion::getHote() const
{
    return ui->champHote->text();
}

void VueConnexion::setHote(const QString &hote)
{
    ui->champHote->setText(hote);
}

int VueConnexion::getPort() const
{
    return ui->champPort->value();
}

void VueConnexion::setPort(const int &port)
{
    ui->champPort->setValue(port);
}

QString VueConnexion::getUsager() const
{
    return ui->champUsager->text();
}

void VueConnexion::setUsager(const QString &usager)
{
    ui->champUsager->setText(usager);
}

QString VueConnexion::getMotDePasse() const
{
    return ui->champMDP->text();
}

void VueConnexion::setMotDePasse(const QString &motDePasse)
{
    ui->champMDP->setText(motDePasse);
}

void VueConnexion::activerBoutonOk()
{
    boutonOk->setEnabled(true);
}

void VueConnexion::desactiverBoutonOk()
{
    boutonOk->setEnabled(false);
}

QPushButton* VueConnexion::boutonConnexion() const
{
    return ui->boutonConnecter;
}

void VueConnexion::peuplerTableau(QAbstractTableModel* valeurs)
{
    if (ui->listeBd->model() != NULL) {
        ui->listeBd->model()->deleteLater();
    }
    ui->listeBd->setModel(valeurs);
    desactiverBoutonOk();
}
