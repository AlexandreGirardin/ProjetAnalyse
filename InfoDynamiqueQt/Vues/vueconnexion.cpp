#include "vueconnexion.h"
#include "ui_vueconnexion.h"

#include "Controleurs/controleurconnexion.h"

#include <QDialogButtonBox>
#include <QLineEdit>
#include <QSettings>
#include <QStringListModel>
#include <QTextEdit>
#include <QTableWidget>

VueConnexion::VueConnexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VueConnexion)
{
    ui->setupUi(this);
    setWindowTitle(tr("Connexion"));
    QSettings parametres;
    ui->champHote->setText(parametres.value("connexion/hote","localhost").toString());
    ui->champPort->setValue(parametres.value("connexion/port", 3307).toInt());
    ui->champUsager->setText(parametres.value("connexion/usager","root").toString());
    ui->boutonConnecter->setDefault(true);
    connect(ui->boutonConnecter, SIGNAL(clicked()), this, SIGNAL(testerConnexion()));
    configurerBoutonOk();
}

VueConnexion::~VueConnexion()
{
    delete ui;
}

void VueConnexion::configurerBoutonOk()
{
    QPushButton* boutonOk = ui->buttonBox->button(QDialogButtonBox::Ok);
    boutonOk->setEnabled(false);
    connect(ui->listeBd, SIGNAL(clicked(QModelIndex)), this, SLOT(activerBoutonOk()));
    connect(ui->listeBd, SIGNAL(activated(QModelIndex)), this, SLOT(activerBoutonOk()));
    connect(ui->champHote, SIGNAL(textChanged(QString)), this, SLOT(boutonConnecterParDefaut()));
    connect(ui->champPort, SIGNAL(valueChanged(int)), this, SLOT(boutonConnecterParDefaut()));
    connect(ui->champUsager, SIGNAL(textChanged(QString)), this, SLOT(boutonConnecterParDefaut()));
    connect(ui->champMDP, SIGNAL(textChanged(QString)), this, SLOT(boutonConnecterParDefaut()));
    connect(ui->listeBd, SIGNAL(doubleClicked(QModelIndex)), boutonOk, SIGNAL(clicked()));
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
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setDefault(true);
}

void VueConnexion::desactiverBoutonOk()
{
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    boutonConnecterParDefaut();
}

void VueConnexion::boutonConnecterParDefaut()
{
    ui->boutonConnecter->setDefault(true);
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
    if (valeurs->rowCount() > 0) {
        QSettings parametres;
        QString derniereBD = parametres.value("connexion/bd","InfoDynamiqueDossiers").toString();
        ui->listeBd->setFocus();
        int derniereDansListe = -1;
        for (int i = 0; i < valeurs->rowCount() && derniereDansListe < 0; ++i) {
            if (valeurs->index(i, 0).data().toString() == derniereBD) {
                derniereDansListe = i;
            }
        }
        ui->listeBd->setModel(valeurs);
        if (derniereDansListe > 0) {
            ui->listeBd->setCurrentIndex(valeurs->index(derniereDansListe, 0));
        } else {
            ui->listeBd->setCurrentIndex(valeurs->index(0,0));
        }
        activerBoutonOk();
    } else {
        desactiverBoutonOk();
    }
}

void VueConnexion::viderListe()
{
    if (ui->listeBd->model() != NULL) {
        ui->listeBd->model()->deleteLater();
    }
    ui->listeBd->setModel(new QStringListModel(this));
    desactiverBoutonOk();
}
