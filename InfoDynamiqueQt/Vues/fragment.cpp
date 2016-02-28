#include "Vues/fragment.h"
#include "ui_fragment.h"

#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSortFilterProxyModel>
#include <QTableWidget>

Fragment::Fragment(QWidget* parent) : QWidget(parent), ui(new Ui::VueFragment)
{
    m_colonneId = 0;
    m_idModele = -1;
    ui->setupUi(this);
    ui->champ->setClearButtonEnabled(true);
    configurerBoutonAjouter();
    configurerBoutonModifier();
    configurerBoutonVoir();
    configurerCase();
    configurerChamp();
    connect(this, SIGNAL(nouvelleSelection(QModelIndex)), this, SLOT(selectionnerModele(QModelIndex)));
    connect(ui->tableau, SIGNAL(doubleClicked(QModelIndex)), this, SIGNAL(doubleClicModele()));
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

void Fragment::configurerBoutonAjouter()
{
    connect(ui->boutonAjouter, SIGNAL(clicked()), this, SIGNAL(clicCreer()));
}

void Fragment::configurerBoutonModifier()
{
    connect(ui->boutonModifier, SIGNAL(clicked()), this, SIGNAL(clicEditer()));
    connect(this, SIGNAL(selectionValide(bool)), ui->boutonModifier, SLOT(setEnabled(bool)));
}

void Fragment::configurerBoutonVoir()
{
    connect(ui->boutonVoir, SIGNAL(clicked()), this, SIGNAL(clicVoir()));
    connect(this, SIGNAL(selectionValide(bool)), ui->boutonVoir, SLOT(setEnabled(bool)));
}

void Fragment::configurerCase()
{
    connect(ui->caseCocher, SIGNAL(toggled(bool)), this, SLOT(basculerCase(bool)));
}

void Fragment::configurerChamp()
{
    connect(ui->champ, SIGNAL(textChanged(QString)), this, SIGNAL(rechercher(QString)));
}

int Fragment::colonneId() const
{
    return m_colonneId;
}

void Fragment::setColonneId(const int &value)
{
    m_colonneId = value;
}

void Fragment::cacherColonneId() const
{
    ui->tableau->hideColumn(m_colonneId);
}

void Fragment::selectionnerModeleParId(const int &id)
{
    for (int i = ui->tableau->model()->rowCount() - 1; i >= 0; --i) {
        int idTest = ui->tableau->model()->data(ui->tableau->model()->index(i, m_colonneId)).toInt();
        if (id == idTest) {
            ui->tableau->selectRow(i);
        }
        i = 0;
    }
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
    connect(this, SIGNAL(selectionValide(bool)), nouveau, SLOT(setEnabled(bool)));
    return nouveau;
}

QPushButton* Fragment::ajouterBoutonNonConnecte(const int &index, const QString& texte, const QIcon icone)
{
    QPushButton* bouton = new QPushButton(icone, texte, this);
    ui->horizontalLayout->insertWidget(index, bouton);
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

QString Fragment::filtre() const
{
    if (ui->champ != NULL) {
        return ui->champ->text();
    } else {
        return QString();
    }
}

QTableView* Fragment::tableau() const
{
    return ui->tableau;
}

int Fragment::rangeeSelectionnee() const
{
    return ui->tableau->currentIndex().row();
}

void Fragment::selectionnerRangee(const int &rangee) const
{
    ui->tableau->selectRow(rangee);
}

void Fragment::peuplerTableau(QAbstractTableModel* valeurs)
{
    QSortFilterProxyModel* modeleTriable = new QSortFilterProxyModel(ui->tableau);
    modeleTriable->setSourceModel(valeurs);
    delete ui->tableau->selectionModel();
    ui->tableau->setModel(modeleTriable);
    connect(ui->tableau->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(signalerSelection(QModelIndex, QModelIndex)));
    ui->tableau->resizeColumnsToContents();
    ui->tableau->sortByColumn(0, Qt::AscendingOrder);
    relacherModele();
}

int Fragment::getId(const QModelIndex &index)
{
    int rangee = index.row();
    QModelIndex caseId = ui->tableau->model()->index(rangee, m_colonneId);
    return ui->tableau->model()->data(caseId).toInt();
}

int Fragment::idModele() const
{
    return m_idModele;
}

void Fragment::setIdModele(const int &value)
{
    m_idModele = value;
}

void Fragment::relacherModele()
{
    ui->tableau->clearSelection();
    m_idModele = -1;
    emit selectionValide(false);
    emit modeleRelache();
}

void Fragment::selectionnerModele(const QModelIndex &index)
{
    m_idModele = getId(index);
    emit selectionValide(true);
    emit modeleSelectionne(m_idModele);
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
