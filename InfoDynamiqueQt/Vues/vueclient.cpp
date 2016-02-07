#include "vueclient.h"
#include "ui_vueclient.h"

VueClient::VueClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VueClient)
{
    ui->setupUi(this);
}

VueClient::~VueClient()
{
    delete ui;
}

void VueClient::setPrenom(const QString &prenom)
{
    ui->champPrenom->setText(prenom);
}

void VueClient::setNom(const QString &nom)
{
    ui->champNom->setText(nom);
}

void VueClient::setTelephone(const QString &telephone)
{
    ui->champTelephone->setText(telephone);
}

void VueClient::setAdresse(const QString &adresse)
{
    ui->champAdresse->setText(adresse);
}
