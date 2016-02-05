#include "Vues/vuegestionensemble.h"
#include "ui_vuegestionensemble.h"

#include "Modeles/ensembleactions.h"

#include <QDebug>

VueGestionEnsemble::VueGestionEnsemble(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::VueGestionEnsemble)
{
    ui->setupUi(this);
    nom = new ChampFormulaire(tr("Ce champ est requis"), this);
    nom->setFocus();
    ui->formLayout->setWidget(0,QFormLayout::FieldRole, nom);
    configurerBoutonOk();
    QObject::connect(nom, SIGNAL(valeurChangee()), this, SLOT(verifierNom()));
    ui->boutonAjouter->setEnabled(false);
    ui->boutonRetirer->setEnabled(false);
    actionsHorsEnsemble = new QList<Action*>;
    actionsDansEnsemble = new QList<Action*>;
    QObject::connect(ui->listeExistantes, SIGNAL(activated(QModelIndex)), this, SLOT(horsEnsembleSelectionnee(QModelIndex)));
    QObject::connect(ui->boutonAjouter, SIGNAL(clicked()), this, SLOT(ajouter()));
    QObject::connect(ui->listeSelectionnees, SIGNAL(activated(QModelIndex)), this, SLOT(dansEnsembleSelectionnee(QModelIndex)));
    QObject::connect(ui->boutonRetirer, SIGNAL(clicked()), this, SLOT(retirer()));
}

VueGestionEnsemble::~VueGestionEnsemble()
{
    delete ui;
    qDeleteAll(*actionsHorsEnsemble);
    delete actionsHorsEnsemble;
    qDeleteAll(*actionsDansEnsemble);
    delete actionsDansEnsemble;
}

void VueGestionEnsemble::configurerBoutonOk()
{
    boutonOk = new QPushButton(tr("Ok"), this);
    boutonOk->setEnabled(false);
    ui->buttonBox->addButton(boutonOk, QDialogButtonBox::AcceptRole);
    QObject::connect(nom, SIGNAL(validiteChangee()), this, SLOT(verifierOk()));
    QObject::connect(this, SIGNAL(champsRequisModifies(bool)), boutonOk, SLOT(setEnabled(bool)));
}

void VueGestionEnsemble::setNom(const QString &valeur)
{
    nom->setTexte(valeur);
}

QString VueGestionEnsemble::getNom() const
{
    return nom->getTexte();
}

void VueGestionEnsemble::setDescription(const QString &valeur)
{
    ui->champDescription->setText(valeur);
}

QString VueGestionEnsemble::getDescription() const
{
    return ui->champDescription->text();
}

QList<Action*>* VueGestionEnsemble::getActionsHorsEnsemble() const
{
    return actionsHorsEnsemble;
}

QList<Action*>* VueGestionEnsemble::getActionsDansEnsemble() const
{
    return actionsDansEnsemble;
}

void VueGestionEnsemble::setActionsHorsEnsemble(QList<Action*>* actions)
{
    qDeleteAll(*actionsHorsEnsemble);
    delete actionsHorsEnsemble;
    actionsHorsEnsemble = actions;
    peuplerHorsEnsemble();
}

void VueGestionEnsemble::setActionsDansEnsemble(QList<Action*>* actions)
{
    qDeleteAll(*actionsDansEnsemble);
    delete actionsDansEnsemble;
    actionsDansEnsemble = actions;
    peuplerDansEnsemble();
}

void VueGestionEnsemble::horsEnsembleSelectionnee(const QModelIndex &index)
{
    selectionHorsEnsemble = index.row();
    ui->boutonAjouter->setEnabled(true);
}

void VueGestionEnsemble::dansEnsembleSelectionnee(const QModelIndex &index)
{
    selectionDansEnsemble = index.row();
    ui->boutonRetirer->setEnabled(true);
}

void VueGestionEnsemble::ajouter()
{
    if (selectionHorsEnsemble >= 0 && selectionHorsEnsemble < actionsHorsEnsemble->count()) {
        actionsDansEnsemble->append(actionsHorsEnsemble->takeAt(selectionHorsEnsemble));
        peuplerHorsEnsemble();
        peuplerDansEnsemble();
        selectionHorsEnsemble = -1;
    }
}

void VueGestionEnsemble::retirer()
{
    if (selectionDansEnsemble >= 0 && selectionDansEnsemble < actionsDansEnsemble->count()) {
        actionsHorsEnsemble->append(actionsDansEnsemble->takeAt(selectionDansEnsemble));
        peuplerDansEnsemble();
        peuplerHorsEnsemble();
        selectionDansEnsemble = -1;
    }
}

void VueGestionEnsemble::peuplerHorsEnsemble()
{
    delete ui->listeExistantes->model();
    ui->listeExistantes->setModel(listeVersModele(actionsHorsEnsemble));
    ui->boutonAjouter->setEnabled(false);
}

void VueGestionEnsemble::peuplerDansEnsemble()
{
    delete ui->listeSelectionnees->model();
    ui->listeSelectionnees->setModel(listeVersModele(actionsDansEnsemble));
    ui->boutonRetirer->setEnabled(false);
}

QStandardItemModel *VueGestionEnsemble::listeVersModele(const QList<Action*>* liste)
{
    QStandardItemModel* modele = new QStandardItemModel(this);
    for (QList<Action*>::const_iterator i = liste->constBegin(); i != liste->constEnd(); ++i) {
        QStandardItem* element = new QStandardItem((*i)->nom());
        element->setToolTip((*i)->description());
        modele->appendRow(element);
    }
    return modele;
}

void VueGestionEnsemble::verifierNom()
{
    nom->setValide(!nom->getTexte().isEmpty());
}

void VueGestionEnsemble::verifierOk()
{
    emit champsRequisModifies(nom->estValide());
}
