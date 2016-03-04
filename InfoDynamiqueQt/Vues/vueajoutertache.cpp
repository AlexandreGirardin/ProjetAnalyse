#include "vueajoutertache.h"
#include "ui_vueajoutertache.h"

#include "Controleurs/controleuractions.h"
#include "Mappeurs/mappeuractions.h"
#include "Modeles/action.h"
#include "Modeles/statut.h"

VueAjouterTache::VueAjouterTache(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VueAjouterTache)
{
    ui->setupUi(this);
    connect(ui->boutonAjouter, SIGNAL(clicked()), this, SLOT(ajouterAction()));
}

VueAjouterTache::~VueAjouterTache()
{
    delete ui;
}

void VueAjouterTache::setActions(const QList<Action*>* actions)
{
    ui->comboAction->clear();
    for (QList<Action*>::const_iterator i = actions->constBegin(); i != actions->constEnd(); ++i) {
        setAction(*i);
    }
}

void VueAjouterTache::setAction(const Action* action) {
    ui->comboAction->addItem(action->nom(), action->id());
}

int VueAjouterTache::getAction() const
{
    return ui->comboAction->currentData(Qt::UserRole).toInt();
}

void VueAjouterTache::setStatuts(const QList<Statut*>* statuts)
{
    ui->comboStatut->clear();
    for (QList<Statut*>::const_iterator i = statuts->constBegin(); i != statuts->constEnd(); ++i) {
        ui->comboStatut->addItem((*i)->nom(), (*i)->id());
    }
}

int VueAjouterTache::getStatut() const
{
    return ui->comboStatut->currentData(Qt::UserRole).toInt();
}

void VueAjouterTache::setCommentaire(const QString commentaire)
{
    ui->champCommentaire->setText(commentaire);
}

QString VueAjouterTache::getCommentaire() const
{
    return ui->champCommentaire->text();
}

void VueAjouterTache::ajouterAction()
{
    int id = ControleurActions::creerAction(this);
    if (id != -1) {
        Action* action = MappeurActions::get(id);
        if (action != NULL) {
            setAction(action);
            ui->comboAction->setCurrentText(action->nom());
        }
        action->deleteLater();
    }
}
