#include "Vues/vuegestionfiche.h"
#include "ui_vuegestionfiche.h"

#include "Mappeurs/mappeurensembles.h"

#include <QStandardItemModel>
#include <QDebug>

VueGestionFiche::VueGestionFiche(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::VueGestionFiche)
{
    ui->setupUi(this);
    ui->tableTaches->horizontalHeader()->setStretchLastSection(true);
    ui->tableTaches->verticalHeader()->hide();
    QObject::connect(ui->comboEnsemble, SIGNAL(currentIndexChanged(int)), this, SLOT(peuplerTaches()));
}

VueGestionFiche::~VueGestionFiche()
{
    delete ui;
}

void VueGestionFiche::setTaches(const QList<Action*>* actions)
{
    delete ui->tableTaches->model();
    QStandardItemModel* modele = new QStandardItemModel(ui->tableTaches);
    QStringList entetes;
    entetes << tr("Tâches");
    modele->setHorizontalHeaderLabels(entetes);
    for (QList<Action*>::const_iterator i = actions->constBegin(); i != actions->constEnd(); ++i) {
        QList<QStandardItem*> rangee;
        Action* action = (*i);
        rangee.append(new QStandardItem(action->nom()));
        modele->appendRow(rangee);
    }
    ui->tableTaches->setModel(modele);
    ui->tableTaches->resizeColumnsToContents();
}

int VueGestionFiche::getIdEnsemble()
{
    return ui->comboEnsemble->currentData().toInt();
}

void VueGestionFiche::peuplerTaches()
{
    if (ui->tableTaches->model() != NULL) {
        ui->tableTaches->model()->deleteLater();
    }
    EnsembleActions* ensemble = MappeurEnsembles::get(getIdEnsemble());
    if (ensemble != NULL) {
        QStandardItemModel* modele = new QStandardItemModel(ui->tableTaches);
        QList<Action*>* actions = ensemble->actions();
        modele->setHorizontalHeaderLabels(QStringList(tr("Tâches")));
        for (QList<Action*>::const_iterator i = actions->constBegin(); i != actions->constEnd(); ++i) {
            modele->appendRow(new QStandardItem((*i)->nom()));
        }
        ui->tableTaches->setModel(modele);
    }
}

void VueGestionFiche::setPriorite(const int &priorite)
{
    ui->champPriorite->setValue(priorite);
}

int VueGestionFiche::getPriorite() const
{
    return ui->champPriorite->value();
}

void VueGestionFiche::setEnsembles(const QList<EnsembleActions*>* ensembles)
{
    ui->comboEnsemble->addItem(tr("Sélectionner un ensemble"), -1);
    for (QList<EnsembleActions*>::const_iterator i = ensembles->constBegin(); i != ensembles->constEnd(); ++i) {
        ui->comboEnsemble->addItem((*i)->nom(), (*i)->id());
    }
}

void VueGestionFiche::setCommentaire(const QString &commentaire)
{
    ui->champCommentaire->setPlainText(commentaire);
}

QString VueGestionFiche::getCommentaire() const
{
    return ui->champCommentaire->toPlainText();
}

