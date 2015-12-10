#include "vuefragment.h"
#include "ui_vuefragment.h"

VueFragment::VueFragment(QWidget *parent) : QWidget(parent), ui(new Ui::VueFragment) {
    ui->setupUi(this);
    QObject::connect(ui->boutonAjouter, SIGNAL(clicked()), this, SIGNAL(clicCreer()));
    QObject::connect(ui->boutonModifier, SIGNAL(clicked()), this, SIGNAL(clicEditer()));
    QObject::connect(ui->boutonVoir, SIGNAL(clicked()), this, SIGNAL(clicVoir()));
    QObject::connect(ui->caseCocher, SIGNAL(toggled(bool)), this, SLOT(signalerCase(bool)));

}

VueFragment::~VueFragment() {
    delete ui;
}

QLabel *VueFragment::getEtiquette() const {
    return ui->etiquette;
}

QPushButton *VueFragment::getBoutonAjouter() const {
    return ui->boutonAjouter;
}

QPushButton *VueFragment::getBoutonModifier() const {
    return ui->boutonModifier;
}

QPushButton *VueFragment::getBoutonVoir() const {
    return ui->boutonVoir;
}

QCheckBox *VueFragment::getCaseCocher() const {
    return ui->caseCocher;
}

QLineEdit *VueFragment::getChamp() const {
    return ui->champ;
}

QTableView *VueFragment::getTableau() const {
    return ui->tableau;
}

void VueFragment::setModele(QAbstractTableModel* modele) {
    QItemSelectionModel* vieilleSelection = ui->tableau->selectionModel();
    ui->tableau->setModel(modele);
    delete vieilleSelection;
    QObject::connect(ui->tableau->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(signalerSelection(QModelIndex, QModelIndex)));
    ui->tableau->resizeColumnsToContents();
}

int VueFragment::getId(QModelIndex index) {
    int colonne = 0;
    int rangee = index.row();
    QModelIndex caseId = ui->tableau->model()->index(rangee, colonne);
    return ui->tableau->model()->data(caseId).toInt();
}

void VueFragment::relacherModele() {
    ui->tableau->clearSelection();
    desactiverBoutonsModele();
}

void VueFragment::activerBoutonsModele() {
    ui->boutonModifier->setEnabled(true);
    ui->boutonVoir->setEnabled(true);
}

void VueFragment::desactiverBoutonsModele() {
    ui->boutonModifier->setEnabled(false);
    ui->boutonVoir->setEnabled(false);
}

void VueFragment::signalerCase(bool etat) {
    if (etat) {
        emit caseCochee();
    } else {
        emit caseDecochee();
    }
}

void VueFragment::signalerSelection(QModelIndex nouvelle, QModelIndex) {
    emit nouvelleSelection(nouvelle);
}
