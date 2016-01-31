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
    QObject::connect(nom, SIGNAL(valeurChangee()), this, SLOT(verifierNom()));
    ui->boutonAjouter->setEnabled(false);
    ui->boutonRetirer->setEnabled(false);
    actionsDansEnsemble = new QList<Action*>;
    actionsHorsEnsemble = new QList<Action*>;
    QObject::connect(ui->listeExistantes, SIGNAL(activated(QModelIndex)), this, SLOT(horsEnsembleSelectionnee(QModelIndex)));
    QObject::connect(ui->boutonAjouter, SIGNAL(clicked()), this, SLOT(ajouter()));
    QObject::connect(ui->listeSelectionnees, SIGNAL(activated(QModelIndex)), this, SLOT(dansEnsembleSelectionnee(QModelIndex)));
    QObject::connect(ui->boutonRetirer, SIGNAL(clicked()), this, SLOT(retirer()));
}

VueGestionEnsemble::~VueGestionEnsemble()
{
    delete ui;
}

void VueGestionEnsemble::setActionsHorsEnsemble(QList<Action*>* actions)
{
    qDeleteAll(*actionsHorsEnsemble);
    delete actionsHorsEnsemble;
    actionsHorsEnsemble = actions;
    peuplerHorsEnsemble();
}

QList<Action*>* VueGestionEnsemble::getActionsHorsEnsemble()
{
    return actionsHorsEnsemble;
}

QList<Action*>* VueGestionEnsemble::getActionsDansEnsemble()
{
    return actionsDansEnsemble;
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
    horsEnsemble = new QStandardItemModel(ui->listeExistantes);
    for (QList<Action*>::const_iterator i = actionsHorsEnsemble->constBegin(); i != actionsHorsEnsemble->constEnd(); ++i) {
        horsEnsemble->appendRow(new QStandardItem((*i)->getNom()));
    }
    ui->listeExistantes->setModel(horsEnsemble);
    ui->boutonAjouter->setEnabled(false);
}

void VueGestionEnsemble::peuplerDansEnsemble()
{
    dansEnsemble = new QStandardItemModel(ui->listeExistantes);
    for (QList<Action*>::const_iterator i = actionsDansEnsemble->constBegin(); i != actionsDansEnsemble->constEnd(); ++i) {
        dansEnsemble->appendRow(new QStandardItem((*i)->getNom()));
    }
    ui->listeSelectionnees->setModel(dansEnsemble);
    ui->boutonRetirer->setEnabled(false);
}

void VueGestionEnsemble::verifierNom()
{
    nom->setValide(!nom->getTexte().isEmpty());
}
