#include "Vues/vuegestionensemble.h"
#include "ui_vuegestionensemble.h"

#include "Modeles/ensembleactions.h"

#include <QtGui/QStandardItemModel>
//#include <QList

VueGestionEnsemble::VueGestionEnsemble(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::VueGestionEnsemble)
{
    ui->setupUi(this);
}

VueGestionEnsemble::~VueGestionEnsemble()
{
    delete ui;
}

void VueGestionEnsemble::setActionsExistantes(const QList<Action*>* actions)
{
    QStandardItemModel* modele = new QStandardItemModel(this);
    for (QList<Action*>::const_iterator i = actions->constBegin(); i != actions->constEnd(); ++i) {
        modele->appendRow(new QStandardItem((*i)->getNom()));
    }
    ui->listeExistantes->setModel(modele);
}
