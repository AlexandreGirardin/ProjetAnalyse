#include "Vues/vuegestionclient.h"
#include "ui_vuegestionclient.h"

VueGestionClient::VueGestionClient(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::VueGestionClient) {
    ui->setupUi(this);
}

VueGestionClient::~VueGestionClient() {
    delete ui;
}

QLineEdit* VueGestionClient::getChampPrenom() const {
    return ui->champPrenom;
}

QLineEdit* VueGestionClient::getChampNom() const {
    return ui->champNom;
}

QLineEdit* VueGestionClient::getChampTelephone() const {
    return ui->champTelephone;
}

QLineEdit* VueGestionClient::getChampCourriel() const {
    return ui->champCourriel;
}

void VueGestionClient::setLectureSeule() {
    ui->champPrenom->setReadOnly(true);
    ui->champNom->setReadOnly(true);
    ui->champTelephone->setReadOnly(true);
    ui->champCourriel->setReadOnly(true);
}

void VueGestionClient::setEditable() {
    ui->champPrenom->setReadOnly(false);
    ui->champNom->setReadOnly(false);
    ui->champTelephone->setReadOnly(false);
    ui->champCourriel->setReadOnly(false);
}
