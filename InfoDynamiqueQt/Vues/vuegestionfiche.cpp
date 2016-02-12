#include "Vues/vuegestionfiche.h"
#include "ui_vuegestionfiche.h"

#include <QStandardItemModel>
#include <QDebug>

VueGestionFiche::VueGestionFiche(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::VueGestionFiche)
{
    ui->setupUi(this);
    ui->tableTaches->horizontalHeader()->setStretchLastSection(true);
    ui->tableTaches->verticalHeader()->hide();
}

VueGestionFiche::~VueGestionFiche()
{
    delete ui;
}

void VueGestionFiche::cacherGestionEnsemble()
{
    if (ui->etiquetteEnsemble != NULL) {
        ui->etiquetteEnsemble->hide();
    }
    if (ui->comboEnsemble != NULL) {
        ui->comboEnsemble->hide();
    }
}

void VueGestionFiche::setTaches(const QList<Tache*>* taches)
{
    delete ui->tableTaches->model();
    QStandardItemModel* modele = new QStandardItemModel(ui->tableTaches);
    QStringList entetes;
    entetes << tr("Tâches") << tr("Statut");
    modele->setHorizontalHeaderLabels(entetes);
    for (QList<Tache*>::const_iterator i = taches->constBegin(); i != taches->constEnd(); ++i) {
        QList<QStandardItem*> rangee;
        Tache* tache = (*i);
        rangee.append(new QStandardItem(tache->action()->nom()));
        rangee.append(new QStandardItem(tache->statut()->nom()));
        modele->appendRow(rangee);
    }
    ui->tableTaches->setModel(modele);
    ui->tableTaches->resizeColumnsToContents();
}

void VueGestionFiche::setPriorite(const int &priorite)
{
    ui->champPriorite->setValue(priorite);
}

int VueGestionFiche::getPriorite() const
{
    ui->champPriorite->value();
}

void VueGestionFiche::setEnsembles(const QList<EnsembleActions *> *ensembles)
{
    //TODO ui->comboEnsemble;
}

void VueGestionFiche::setCommentaire(const QString &commentaire)
{
    ui->champCommentaire->setPlainText(commentaire);
}

QString VueGestionFiche::getCommentaire() const
{
    return ui->champCommentaire->toPlainText();
}

void VueGestionFiche::setLectureSeule()
{

}

