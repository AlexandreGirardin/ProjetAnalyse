#include "Vues/fragment.h"
#include "ui_fragment.h"

#include <QSortFilterProxyModel>

Fragment::Fragment(QWidget* parent) : QWidget(parent), ui(new Ui::VueFragment)
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
    QObject::connect(ui->tableau, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(doubleClicTableau()));
}

Fragment::~Fragment()
{
    delete ui;
}

void Fragment::retirerEtiquette() const
{
    if (ui->etiquette != NULL) {
        ui->etiquette->deleteLater();
    }
}

void Fragment::setEtiquette(const QString &etiquette) const
{
    if (ui->etiquette != NULL) {
        ui->etiquette->setText(etiquette);
    }
}


int Fragment::getDernierIndexSelectionne() const
{
    return dernierIndexSelectionne;
}

void Fragment::setDernierIndexSelectionne(int value)
{
    dernierIndexSelectionne = value;
}
void Fragment::configurerBoutonAjouter()
{
    QObject::connect(ui->boutonAjouter, SIGNAL(clicked()), this, SIGNAL(clicCreer()));
}

void Fragment::configurerBoutonModifier()
{
    QObject::connect(ui->boutonModifier, SIGNAL(clicked()), this, SIGNAL(clicEditer()));
    QObject::connect(this, SIGNAL(selectionValide(bool)), ui->boutonModifier, SLOT(setEnabled(bool)));
}

void Fragment::configurerBoutonVoir()
{
    QObject::connect(ui->boutonVoir, SIGNAL(clicked()), this, SIGNAL(clicVoir()));
    QObject::connect(this, SIGNAL(selectionValide(bool)), ui->boutonVoir, SLOT(setEnabled(bool)));
}

void Fragment::configurerCase()
{
    QObject::connect(ui->caseCocher, SIGNAL(toggled(bool)), this, SLOT(basculerCase(bool)));
}

void Fragment::configurerChamp()
{
    QObject::connect(ui->champ, SIGNAL(textChanged(QString)), this, SIGNAL(rechercher(QString)));
}

int Fragment::getColonneId() const
{
    return colonneId;
}

void Fragment::setColonneId(const int &value)
{
    colonneId = value;
}

QPushButton* Fragment::boutonAjouter() const
{
    return ui->boutonAjouter;
}

QPushButton* Fragment::boutonModifier() const
{
    return ui->boutonModifier;
}

QPushButton* Fragment::boutonVoir() const
{
    return ui->boutonVoir;
}

QPushButton* Fragment::ajouterBouton(const int &index, const QString &texte, const QIcon &icone)
{
    QPushButton* nouveau = ajouterBoutonNonConnecte(index, texte, icone);
    QObject::connect(this, SIGNAL(selectionValide(bool)), nouveau, SLOT(setEnabled(bool)));
    return nouveau;
}

QPushButton* Fragment::ajouterBoutonNonConnecte(const int &index, const QString& texte, const QIcon icone)
{
    QPushButton* bouton = new QPushButton(icone, texte, this);
    ui->horizontalLayout->insertWidget(index, bouton);
    return bouton;
}

QComboBox* Fragment::ajouterCombobox(const int &index)
{
    QComboBox* bouton = new QComboBox(this);
    ui->horizontalLayout->insertWidget(index, bouton);
    QObject::connect(this, SIGNAL(selectionValide(bool)), bouton, SLOT(setEnabled(bool)));
    return bouton;
}

QPushButton* Fragment::caseCocher() const
{
    return ui->caseCocher;
}

QLineEdit *Fragment::champ() const
{
    return ui->champ;
}

void Fragment::retirerCaseCocher() const
{
    if (ui->caseCocher != NULL) {
        ui->caseCocher->deleteLater();
    }
}

void Fragment::retirerChamp() const
{
    if (ui->caseCocher != NULL) {
        ui->champ->deleteLater();
    }
}

QString Fragment::getFiltre() const
{
    if (ui->champ != NULL) {
        return ui->champ->text();
    } else {
        return QString();
    }
}

QTableView* Fragment::getTableau() const
{
    return ui->tableau;
}

void Fragment::peuplerTableau(QAbstractTableModel* valeurs)
{
    QSortFilterProxyModel* modeleTriable = new QSortFilterProxyModel(ui->tableau);
    modeleTriable->setSourceModel(valeurs);
    delete ui->tableau->selectionModel();
    ui->tableau->setModel(modeleTriable);
    QObject::connect(ui->tableau->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(signalerSelection(QModelIndex, QModelIndex)));
    ui->tableau->resizeColumnsToContents();
    ui->tableau->sortByColumn(0, Qt::AscendingOrder);
    relacherModele();
}

int Fragment::getId(const QModelIndex &index)
{
    int rangee = index.row();
    QModelIndex caseId = ui->tableau->model()->index(rangee, colonneId);
    return ui->tableau->model()->data(caseId).toInt();
}

int Fragment::getIdModele() const
{
    return idModele;
}

void Fragment::setIdModele(const int &value)
{
    idModele = value;
}

void Fragment::relacherModele()
{
    ui->tableau->clearSelection();
    idModele = -1;
    emit selectionValide(false);
    emit modeleRelache();
}

void Fragment::selectionnerModele(const QModelIndex &index)
{
    dernierIndexSelectionne = index.row();
    idModele = getId(index);
    emit selectionValide(true);
    emit modeleSelectionne(idModele);
}

void Fragment::basculerCase(const bool &etat)
{
    if (etat) {
        emit caseCochee();
        ui->caseCocher->setIcon(QIcon(":/Images/visibility"));
    } else {
        emit caseDecochee();
        ui->caseCocher->setIcon(QIcon(":/Images/hint"));
    }
}

void Fragment::signalerSelection(const QModelIndex &nouvelle, const QModelIndex&)
{
    emit nouvelleSelection(nouvelle);
}

void Fragment::doubleClicTableau()
{
    emit doubleClicModele();
}
