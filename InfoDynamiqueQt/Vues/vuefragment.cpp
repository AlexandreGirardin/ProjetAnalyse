#include "vuefragment.h"
#include "ui_vuefragment.h"

VueFragment::VueFragment(QWidget *parent) : QWidget(parent), ui(new Ui::VueFragment) {
    ui->setupUi(this);
//    QObject::connect(ui->bouton1, SIGNAL(clicked()), this, SLOT(changerEtiquette()));
}

VueFragment::~VueFragment() {
    delete ui;
}

QLabel *VueFragment::getEtiquette() const
{
    return ui->etiquette;
}

QPushButton *VueFragment::getBouton1() const
{
    return ui->bouton1;
}

QPushButton *VueFragment::getBouton2() const
{
    return ui->bouton2;
}

QPushButton *VueFragment::getBouton3() const
{
    return ui->bouton3;
}

QCheckBox *VueFragment::getCaseCocher() const
{
    return ui->caseCocher;
}

QLineEdit *VueFragment::getChamp() const
{
    return ui->champ;
}

QTableView *VueFragment::getTableau() const
{
    return ui->tableau;
}

void VueFragment::setModele(QAbstractTableModel* modele)
{
    ui->tableau->setModel(modele);
}
