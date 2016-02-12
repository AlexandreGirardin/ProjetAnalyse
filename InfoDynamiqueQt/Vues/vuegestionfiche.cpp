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

void VueGestionFiche::setTaches(const QList<Tache*>* taches)
{
    delete ui->tableTaches->model();
    QStandardItemModel* modele = new QStandardItemModel(ui->tableTaches);
    QStringList entetes;
    entetes << tr("Tâches");
    modele->setHorizontalHeaderLabels(entetes);
    for (QList<Tache*>::const_iterator i = taches->constBegin(); i != taches->constEnd(); ++i) {
        QStandardItem* item = new QStandardItem((*i)->action()->out());
        modele->appendRow(item);
    }
    ui->tableTaches->setModel(modele);
    ui->tableTaches->resizeColumnsToContents();
}

void VueGestionFiche::setDescription(const QString &description)
{
    ui->champDescription->setText(description);
}

QString VueGestionFiche::getDescription() const
{
    return ui->champDescription->toPlainText();
}

void VueGestionFiche::setLectureSeule()
{

}

