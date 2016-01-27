#include "Vues/vuefragmentconnexion.h"
#include "ui_vuefragmentconnexion.h"

#include <QSortFilterProxyModel>

VueFragmentConnexion::VueFragmentConnexion(QWidget* parent) : QWidget(parent), ui(new Ui::VueFragmentConnexion)
{
    colonneId = 0;
    idModele = -1;
    ui->setupUi(this);
    ui->tableau->horizontalHeader()->setStretchLastSection(true);
    ui->tableau->horizontalHeader()->setSectionsMovable(true);
    ui->champ->setClearButtonEnabled(true);
    configurerBoutonAjouter();
    configurerCase();
    configurerChamp();
    QObject::connect(this, SIGNAL(nouvelleSelection(QModelIndex)), this, SLOT(selectionnerModele(QModelIndex)));
}

VueFragmentConnexion::~VueFragmentConnexion()
{
    delete ui;
}

void VueFragmentConnexion::configurerBoutonAjouter()
{
    QObject::connect(ui->boutonAjouter, SIGNAL(clicked()), this, SIGNAL(clicCreer()));
    QObject::connect(this, SIGNAL(selectionValide(bool)), ui->boutonAjouter, SLOT(setEnabled(bool)));
}

void VueFragmentConnexion::configurerCase()
{
    QObject::connect(ui->caseCocher, SIGNAL(toggled(bool)), this, SLOT(signalerCase(bool)));
}

void VueFragmentConnexion::configurerChamp()
{
    QObject::connect(ui->champ, SIGNAL(textChanged(QString)), this, SIGNAL(rechercher(QString)));
}

int VueFragmentConnexion::getColonneId() const
{
    return colonneId;
}

void VueFragmentConnexion::setColonneId(int value)
{
    colonneId = value;
}

QLabel* VueFragmentConnexion::getEtiquette() const
{
    return ui->etiquette;
}

QPushButton* VueFragmentConnexion::getBoutonAjouter() const
{
    return ui->boutonAjouter;
}

QPushButton* VueFragmentConnexion::ajouterBouton(int index)
{
    QPushButton* bouton = new QPushButton(this);
    ui->horizontalLayout->insertWidget(index, bouton);
    QObject::connect(this, SIGNAL(selectionValide(bool)), bouton, SLOT(setEnabled(bool)));
    return bouton;
}

QCheckBox* VueFragmentConnexion::getCaseCocher() const
{
    return ui->caseCocher;
}

QLineEdit* VueFragmentConnexion::getChamp() const
{
    return ui->champ;
}

QTableView* VueFragmentConnexion::getTableau() const
{
    return ui->tableau;
}

void VueFragmentConnexion::peuplerTableau(QAbstractTableModel* valeurs)
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

int VueFragmentConnexion::getId(QModelIndex index)
{
    int rangee = index.row();
    QModelIndex caseId = ui->tableau->model()->index(rangee, colonneId);
    return ui->tableau->model()->data(caseId).toInt();
}

int VueFragmentConnexion::getIdModele() const
{
    return idModele;
}

void VueFragmentConnexion::setIdModele(int value)
{
    idModele = value;
}

void VueFragmentConnexion::relacherModele()
{
    ui->tableau->clearSelection();
    idModele = -1;
    emit selectionValide(false);
    emit modeleRelache();
}

void VueFragmentConnexion::selectionnerModele(QModelIndex index)
{
    idModele = getId(index);
    emit selectionValide(true);
    emit modeleSelectionne(idModele);
}

void VueFragmentConnexion::signalerSelection(QModelIndex nouvelle, QModelIndex)
{
    emit nouvelleSelection(nouvelle);
}
