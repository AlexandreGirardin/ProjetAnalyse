#include "Vues/vueeditionfiche.h"
#include "ui_vueeditionfiche.h"

#include "Controleurs/application.h"
#include "Controleurs/controleurappareils.h"
#include "Controleurs/controleurclients.h"
#include "Controleurs/requetessql.h"
#include "Mappeurs/mappeuractions.h"
#include "Mappeurs/mappeurstatuts.h"
#include "Mappeurs/mappeurtaches.h"

#include <QComboBox>
#include <QDebug>
#include <QVariant>

VueEditionFiche::VueEditionFiche(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::VueEditionFiche)
{
    ui->setupUi(this);
    configurerTableauTaches();
    connect(ui->detailsAppareil, SIGNAL(clicked()), this, SLOT(detailsAppareil()));
    connect(ui->detailsClient, SIGNAL(clicked()), this, SLOT(detailsClient()));
}

VueEditionFiche::~VueEditionFiche()
{
    delete ui;
}

void VueEditionFiche::setIdFiche(const int &id)
{
    if (id != m_idFiche) {
        m_idFiche = id;
        ui->groupeInfos->setTitle(tr("Fiche")+" #"+QString::number(id));
    }
}

int VueEditionFiche::idFiche() const
{
    return m_idFiche;
}

void VueEditionFiche::setCommentaire(const QString &commentaire)
{
    ui->champCommentaire->setText(commentaire);
}

QString VueEditionFiche::commentaire() const
{
    return ui->champCommentaire->document()->toPlainText();
}

void VueEditionFiche::setDescription(const QString &commentaire)
{
    ui->champDescription->setText(commentaire);
}

QString VueEditionFiche::description() const
{
    return ui->champDescription->document()->toPlainText();
}

void VueEditionFiche::setClient(const int &id, const QString &nom, const QString &telephone)
{
    m_idClient = id;
    ui->texteClient->setText(nom + " " + telephone);
}

void VueEditionFiche::setAppareil(const int &id, const QString &description)
{
    m_idAppareil = id;
    ui->texteAppareil->setText(description);
}

void VueEditionFiche::configurerTableauTaches()
{

}

void VueEditionFiche::setTaches(const QList<Tache*>* taches)
{
    ui->tableauTaches->setRowCount(taches->count());
    QList<Statut*>* statuts = MappeurStatuts::getStatutsTache();
    int rangee = 0;
    for (QList<Tache*>::const_iterator i = taches->constBegin(); i != taches->constEnd(); ++i) {
        ui->tableauTaches->setItem(rangee, 0, actionVersItem((*i)->action()));
        ui->tableauTaches->setCellWidget(rangee, 1, comboStatut((*i), statuts));
        ui->tableauTaches->setItem(rangee, 2, new QTableWidgetItem((*i)->commentaire()));
        ++rangee;
    }
    ui->tableauTaches->resizeColumnsToContents();
    qDeleteAll(*statuts);
    delete statuts;
}

QList<Tache*>* VueEditionFiche::getTaches() const {
    QList<Tache*>* taches = new QList<Tache*>;
    for (int rangee = 0; rangee < ui->tableauTaches->rowCount(); ++rangee) {
        Tache* tache = new Tache(ui->tableauTaches);
        tache->setIdFiche(m_idFiche);
        tache->setAction(itemVersAction(rangee));
        tache->setStatut(itemVersStatut(rangee));
        tache->setCommentaire(itemVersCommentaire(rangee));
        taches->append(tache);
        qDebug() << tache->out();
    }
    return taches;
}

void VueEditionFiche::setPieces(const QList<Piece*>* pieces)
{
    ui->tableauPieces->setRowCount(pieces->count());
    int rangee = 0;
    QLocale localisation;
    for (QList<Piece*>::const_iterator i = pieces->constBegin(); i != pieces->constEnd(); ++i) {
        QDoubleSpinBox* spin = new QDoubleSpinBox(ui->tableauPieces);
        spin->setMinimum(0);
        spin->setValue((*i)->prixDouble());
        spin->setFrame(false);
        spin->setButtonSymbols(QDoubleSpinBox::NoButtons);
        ui->tableauPieces->setCellWidget(rangee, 0, spin);
//        ui->tableauPieces->setItem(rangee, 0, new QTableWidgetItem(localisation.toString((*i)->prixDouble())));
        ui->tableauPieces->setItem(rangee, 1, new QTableWidgetItem((*i)->nom()));
        ui->tableauPieces->setItem(rangee, 2, new QTableWidgetItem((*i)->description()));
        ++rangee;
    }
    ui->tableauPieces->resizeColumnsToContents();
}

QComboBox* VueEditionFiche::comboStatut(const Tache* tache, const QList<Statut*>* statuts) const
{
    QComboBox* combo = new QComboBox(ui->tableauTaches);
    for (QList<Statut*>::const_iterator i = statuts->constBegin(); i != statuts->constEnd(); ++i) {
        combo->addItem((*i)->nom(), (*i)->id());
    }
    combo->setCurrentText(tache->statut()->nom());
    return combo;
}

QTableWidgetItem* VueEditionFiche::actionVersItem(const Action *action) const
{
    QTableWidgetItem* nom = new QTableWidgetItem(action->nom());
    nom->setData(Qt::UserRole, action->id());
    nom->setToolTip(action->description());
    nom->setFlags(nom->flags() & ~Qt::ItemIsEditable);
    return nom;
}

Action* VueEditionFiche::itemVersAction(const int &rangee) const
{
    return MappeurActions::get(ui->tableauTaches->item(rangee, 0)->data(Qt::UserRole).toInt());
}

Statut* VueEditionFiche::itemVersStatut(const int &rangee) const
{
    QComboBox* combo = qobject_cast<QComboBox*>(ui->tableauTaches->cellWidget(rangee, 1));
    int idStatut = combo->currentData().toInt();
    return MappeurStatuts::getStatutTache(idStatut);
}

QString VueEditionFiche::itemVersCommentaire(const int &rangee) const
{
    return ui->tableauTaches->item(rangee, 2)->data(Qt::DisplayRole).toString();
}

void VueEditionFiche::detailsClient()
{
    ControleurClients::voirClient(m_idClient, true);
}

void VueEditionFiche::detailsAppareil()
{
    ControleurAppareils::voirAppareil(m_idAppareil, true);
}

void VueEditionFiche::peuplerPieces()
{

}
