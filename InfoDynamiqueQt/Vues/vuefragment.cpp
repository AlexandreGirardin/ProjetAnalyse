#include "Vues/vuefragment.h"
#include "ui_vuefragment.h"

#include <QSortFilterProxyModel>

VueFragment::VueFragment(QWidget* parent) : QWidget(parent), ui(new Ui::VueFragment)
{
    colonneId = 0;
    idModele = -1;
    ui->setupUi(this);
    ui->tableau->horizontalHeader()->setStretchLastSection(true);
    ui->tableau->horizontalHeader()->setSectionsMovable(true);
    ui->champ->setClearButtonEnabled(true);
    configurerBoutonAjouter();
    configurerBoutonModifier();
    configurerBoutonVoir();
    configurerCase();
    configurerChamp();
    QObject::connect(this, SIGNAL(nouvelleSelection(QModelIndex)), this, SLOT(selectionnerModele(QModelIndex)));
}

VueFragment::~VueFragment()
{
    delete ui;
}

void VueFragment::configurerBoutonAjouter()
{
    QObject::connect(ui->boutonAjouter, SIGNAL(clicked()), this, SIGNAL(clicCreer()));
    QObject::connect(this, SIGNAL(selectionValide(bool)), ui->boutonAjouter, SLOT(setEnabled(bool)));
}

void VueFragment::configurerBoutonModifier()
{
    QObject::connect(ui->boutonModifier, SIGNAL(clicked()), this, SIGNAL(clicEditer()));
    QObject::connect(this, SIGNAL(selectionValide(bool)), ui->boutonModifier, SLOT(setEnabled(bool)));
}

void VueFragment::configurerBoutonVoir()
{
    QObject::connect(ui->boutonVoir, SIGNAL(clicked()), this, SIGNAL(clicVoir()));
    QObject::connect(this, SIGNAL(selectionValide(bool)), ui->boutonVoir, SLOT(setEnabled(bool)));
}

void VueFragment::configurerCase()
{
    QObject::connect(ui->caseCocher, SIGNAL(toggled(bool)), this, SLOT(signalerCase(bool)));
}

void VueFragment::configurerChamp()
{
    QObject::connect(ui->champ, SIGNAL(textChanged(QString)), this, SIGNAL(rechercher(QString)));
}

int VueFragment::getColonneId() const
{
    return colonneId;
}

void VueFragment::setColonneId(int value)
{
    colonneId = value;
}


QLabel* VueFragment::getEtiquette() const
{
    return ui->etiquette;
}

QPushButton* VueFragment::getBoutonAjouter() const
{
    return ui->boutonAjouter;
}

QPushButton* VueFragment::getBoutonModifier() const
{
    return ui->boutonModifier;
}

QPushButton* VueFragment::getBoutonVoir() const
{
    return ui->boutonVoir;
}

QPushButton* VueFragment::ajouterBouton(int index)
{
    QPushButton* bouton = new QPushButton(this);
    ui->horizontalLayout->insertWidget(index, bouton);
    QObject::connect(this, SIGNAL(selectionValide(bool)), bouton, SLOT(setEnabled(bool)));
    return bouton;
}

QCheckBox* VueFragment::getCaseCocher() const
{
    return ui->caseCocher;
}

QLineEdit* VueFragment::getChamp() const
{
    return ui->champ;
}

QTableView* VueFragment::getTableau() const
{
    return ui->tableau;
}

void VueFragment::peuplerTableau(QAbstractTableModel* valeurs)
{
    QSortFilterProxyModel* modeleTriable = new QSortFilterProxyModel(ui->tableau);
    modeleTriable->setSourceModel(valeurs);
    QItemSelectionModel* vieilleSelection = ui->tableau->selectionModel();
    ui->tableau->setModel(modeleTriable);
    delete vieilleSelection;
    QObject::connect(ui->tableau->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(signalerSelection(QModelIndex, QModelIndex)));
    ui->tableau->resizeColumnsToContents();
    ui->tableau->sortByColumn(0, Qt::AscendingOrder);
    relacherModele();
}

int VueFragment::getId(QModelIndex index)
{
    int rangee = index.row();
    QModelIndex caseId = ui->tableau->model()->index(rangee, colonneId);
    return ui->tableau->model()->data(caseId).toInt();
}

int VueFragment::getIdModele() const
{
    return idModele;
}

void VueFragment::setIdModele(int value)
{
    idModele = value;
}

void VueFragment::relacherModele()
{
    ui->tableau->clearSelection();
    idModele = -1;
    emit selectionValide(false);
    emit modeleRelache();
}

void VueFragment::selectionnerModele(QModelIndex index)
{
    idModele = getId(index);
    emit selectionValide(true);
    emit modeleSelectionne(idModele);
}

void VueFragment::signalerCase(bool etat)
{
    if (etat) {
        emit caseCochee();
    } else {
        emit caseDecochee();
    }
}

void VueFragment::signalerSelection(QModelIndex nouvelle, QModelIndex)
{
    emit nouvelleSelection(nouvelle);
}
