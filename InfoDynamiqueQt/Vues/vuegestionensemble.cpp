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
    delete actionsHorsEnsemble;
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

QList<Action*>* VueGestionEnsemble::getActionsHorsEnsemble()
{
    return actionsHorsEnsemble;
}

QList<Action*>* VueGestionEnsemble::getActionsDansEnsemble()
{
    return actionsDansEnsemble;
}

void VueGestionEnsemble::setActionsHorsEnsemble(QList<Action*>* actions)
{
    qDeleteAll(*actionsHorsEnsemble);
    actionsHorsEnsemble->clear();
    for (QList<Action*>::const_iterator i = actions->constBegin(); i != actions->constEnd(); ++i) {
        actionsHorsEnsemble->append(*i);
    }
    peuplerHorsEnsemble();
}

void VueGestionEnsemble::setActionsDansEnsemble(const QList<Action*>* actions)
{
    qDeleteAll(*actionsDansEnsemble);
    actionsDansEnsemble->clear();
    for (QList<Action*>::const_iterator i = actions->constBegin(); i != actions->constEnd(); ++i) {
        actionsDansEnsemble->append(*i);
    }
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
        horsEnsemble->appendRow(new QStandardItem((*i)->nom()));
    }
    ui->listeExistantes->setModel(horsEnsemble);
    ui->boutonAjouter->setEnabled(false);
}

void VueGestionEnsemble::peuplerDansEnsemble()
{
    dansEnsemble = new QStandardItemModel(ui->listeExistantes);
    for (QList<Action*>::const_iterator i = actionsDansEnsemble->constBegin(); i != actionsDansEnsemble->constEnd(); ++i) {
        dansEnsemble->appendRow(new QStandardItem((*i)->nom()));
    }
    ui->listeSelectionnees->setModel(dansEnsemble);
    ui->boutonRetirer->setEnabled(false);
}

void VueGestionEnsemble::verifierNom()
{
    nom->setValide(!nom->getTexte().isEmpty());
}

void VueGestionEnsemble::verifierOk()
{
    emit champsRequisModifies(nom->estValide());
}
