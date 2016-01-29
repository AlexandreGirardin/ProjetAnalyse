#include "Vues/vuegestionclient.h"
#include "ui_vuegestionclient.h"

#include <QPushButton>

VueGestionClient::VueGestionClient(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::VueGestionClient)
{
    ui->setupUi(this);
}

VueGestionClient::~VueGestionClient()
{
    delete ui;
}

QString VueGestionClient::getPrenom() const
{
    return ui->champPrenom->text();
}

void VueGestionClient::setPrenom(QString prenom)
{
    ui->champPrenom->setText(prenom);
}

QString VueGestionClient::getNom() const
{
    return ui->champNom->text();
}

void VueGestionClient::setNom(QString nom)
{
    ui->champNom->setText(nom);
}

QString VueGestionClient::getTelephone() const
{
    return ui->champTelephone->text();
}

void VueGestionClient::setTelephone(QString telephone)
{
    ui->champTelephone->setText(telephone);
}

QString VueGestionClient::getAdresse() const
{
    return ui->champAdresse->text();
}

void VueGestionClient::setAdresse(QString adresse)
{
    ui->champAdresse->setText(adresse);
}

void VueGestionClient::setLectureSeule()
{
    ui->champPrenom->setReadOnly(true);
    ui->champNom->setReadOnly(true);
    ui->champTelephone->setReadOnly(true);
    ui->champAdresse->setReadOnly(true);
}

void VueGestionClient::setEditable()
{
    ui->champPrenom->setReadOnly(false);
    ui->champNom->setReadOnly(false);
    ui->champTelephone->setReadOnly(false);
    ui->champAdresse->setReadOnly(false);
}
