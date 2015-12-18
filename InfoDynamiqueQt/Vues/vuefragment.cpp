#include "Vues/vuefragment.h"
#include "ui_vuefragment.h"

VueFragment::VueFragment(QWidget* parent) : QWidget(parent), ui(new Ui::VueFragment) {
    ui->setupUi(this);
    QObject::connect(ui->boutonAjouter, SIGNAL(clicked()), this, SIGNAL(clicCreer()));
    QObject::connect(ui->boutonModifier, SIGNAL(clicked()), this, SIGNAL(clicEditer()));
    QObject::connect(ui->boutonVoir, SIGNAL(clicked()), this, SIGNAL(clicVoir()));
    QObject::connect(ui->caseCocher, SIGNAL(toggled(bool)), this, SLOT(signalerCase(bool)));
    QObject::connect(this, SIGNAL(nouvelleSelection(QModelIndex)), this, SLOT(selectionnerModele(QModelIndex)));
}

VueFragment::~VueFragment() {
    delete ui;
}

QLabel* VueFragment::getEtiquette() const {
    return ui->etiquette;
}

QPushButton* VueFragment::getBoutonAjouter() const {
    return ui->boutonAjouter;
}

QPushButton* VueFragment::getBoutonModifier() const {
    return ui->boutonModifier;
}

QPushButton* VueFragment::getBoutonVoir() const {
    return ui->boutonVoir;
}

QCheckBox* VueFragment::getCaseCocher() const {
    return ui->caseCocher;
}

QLineEdit* VueFragment::getChamp() const {
    return ui->champ;
}

QTableView* VueFragment::getTableau() const {
    return ui->tableau;
}

void VueFragment::peuplerTableau(QAbstractTableModel* valeurs) {
    QItemSelectionModel* vieilleSelection = ui->tableau->selectionModel();
    ui->tableau->setModel(valeurs);
    delete vieilleSelection;
    QObject::connect(ui->tableau->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(signalerSelection(QModelIndex, QModelIndex)));
    ui->tableau->resizeColumnsToContents();
    relacherModele();
}

int VueFragment::getId(QModelIndex index) {
    int colonne = 0;
    int rangee = index.row();
    QModelIndex caseId = ui->tableau->model()->index(rangee, colonne);
    return ui->tableau->model()->data(caseId).toInt();
}
int VueFragment::getIdModele() const {
    return idModele;
}

void VueFragment::setIdModele(int value) {
    idModele = value;
}

void VueFragment::relacherModele() {
    ui->tableau->clearSelection();
    desactiverBoutonsModele();
    idModele = -1;
    emit modeleRelache();
}

void VueFragment::activerBoutonsModele() {
    ui->boutonModifier->setEnabled(true);
    ui->boutonVoir->setEnabled(true);
}

void VueFragment::desactiverBoutonsModele() {
    ui->boutonModifier->setEnabled(false);
    ui->boutonVoir->setEnabled(false);
}

void VueFragment::selectionnerModele(QModelIndex index) {
    activerBoutonsModele();
    idModele = getId(index);
    emit modeleSelectionne(idModele);
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
