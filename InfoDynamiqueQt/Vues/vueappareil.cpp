#include "vueappareil.h"
#include "ui_vueappareil.h"

VueAppareil::VueAppareil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VueAppareil)
{
    ui->setupUi(this);
}

VueAppareil::~VueAppareil() {
    delete ui;
}

QLineEdit *VueAppareil::getChampType() const {
    return ui->champType;
}

QLineEdit *VueAppareil::getChampFabricant() const {
    return ui->champFabricant;
}

QLineEdit *VueAppareil::getChampMotDePasse() const {
    return ui->champMDP;
}

QTextEdit *VueAppareil::getChampDescription() const {
    return ui->champDescription;
}
