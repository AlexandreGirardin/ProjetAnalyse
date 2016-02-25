#include "Vues/vueeditionfiche.h"
#include "ui_vueeditionfiche.h"

#include "Controleurs/application.h"
#include "Controleurs/controleurappareils.h"
#include "Controleurs/controleurclients.h"
#include "Controleurs/requetessql.h"
#include "Mappeurs/mappeuractions.h"
#include "Mappeurs/mappeurstatuts.h"
#include "Mappeurs/mappeurtaches.h"
#include "Vues/vueajoutertache.h"

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
    ui->boutonRetirerTache->setEnabled(false);
    connect(ui->tableauTaches, SIGNAL(clicked(QModelIndex)), this, SLOT(tacheSelectionnee()));
    connect(ui->boutonAjouterTache, SIGNAL(clicked()), this, SLOT(ajouterTache()));
    connect(ui->boutonRetirerTache, SIGNAL(clicked()), this, SLOT(retirerTache()));
}

void VueEditionFiche::setTaches(const QList<Tache*>* taches)
{
    ui->tableauTaches->setRowCount(taches->count());
    QList<Statut*>* statuts = MappeurStatuts::getStatutsTache();
    int rangee = 0;
    for (QList<Tache*>::const_iterator i = taches->constBegin(); i != taches->constEnd(); ++i) {
        setTache(*i, rangee, statuts);
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
    }
    return taches;
}

QList<int>* VueEditionFiche::getIdActions() const
{
    QList<int>* liste = new QList<int>;
    for (int rangee = 0; rangee < ui->tableauTaches->rowCount(); ++rangee) {
        liste->append(ui->tableauTaches->item(rangee, 0)->data(Qt::UserRole).toInt());
    }
    return liste;
}

void VueEditionFiche::setPieces(const QList<Piece*>* pieces)
{
    ui->tableauPieces->setRowCount(pieces->count());
    int rangee = 0;
    QLocale localisation;
    for (QList<Piece*>::const_iterator i = pieces->constBegin(); i != pieces->constEnd(); ++i) {
        ui->tableauPieces->setCellWidget(rangee, 0, prixVersItem((*i)->prixDouble()));
        ui->tableauPieces->setItem(rangee, 1, new QTableWidgetItem((*i)->nom()));
        ui->tableauPieces->setItem(rangee, 2, new QTableWidgetItem((*i)->description()));
        ++rangee;
    }
    ui->tableauPieces->resizeColumnsToContents();
}

QList<Piece *> *VueEditionFiche::getPieces() const
{
    QList<Piece*>* pieces = new QList<Piece*>;
    for (int rangee = 0; rangee < ui->tableauPieces->rowCount(); ++rangee) {
        Piece* piece = new Piece(ui->tableauPieces);
        piece->setPrix(itemVersPrix(rangee));
        piece->setId(ui->tableauPieces->item(rangee, 1)->data(Qt::UserRole).toInt());
        piece->setNom(ui->tableauPieces->item(rangee, 1)->data(Qt::DisplayRole).toString());
        piece->setDescription(ui->tableauPieces->item(rangee, 2)->data(Qt::DisplayRole).toString());
        pieces->append(piece);
        qDebug() << piece->out();
    }
    return pieces;
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

QDoubleSpinBox *VueEditionFiche::prixVersItem(const double &prix)
{
    QDoubleSpinBox* spin = new QDoubleSpinBox(ui->tableauPieces);
    spin->setMinimum(0);
    spin->setMaximum(10000000);
    spin->setValue(prix);
    spin->setFrame(false);
    spin->setButtonSymbols(QDoubleSpinBox::NoButtons);
    return spin;
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

double VueEditionFiche::itemVersPrix(const int &rangee) const
{
    QDoubleSpinBox* spin = qobject_cast<QDoubleSpinBox*>(ui->tableauPieces->cellWidget(rangee, 0));
    double prix = spin->value();
    return prix;
}

void VueEditionFiche::setTache(const Tache *tache, const int &rangee, const QList<Statut*>* statuts)
{
    ui->tableauTaches->setItem(rangee, 0, actionVersItem(tache->action()));
    ui->tableauTaches->setCellWidget(rangee, 1, comboStatut(tache, statuts));
    ui->tableauTaches->setItem(rangee, 2, new QTableWidgetItem(tache->commentaire()));
}

void VueEditionFiche::detailsClient()
{
    ControleurClients::voirClient(m_idClient, true);
}

void VueEditionFiche::detailsAppareil()
{
    ControleurAppareils::voirAppareil(m_idAppareil, true);
}

void VueEditionFiche::ajouterTache()
{
    QList<Action*>* actionsRestantes = MappeurActions::getSauf(getIdActions());
    if (!actionsRestantes->isEmpty()) {
        VueAjouterTache* vue = new VueAjouterTache(this);
        vue->setActions(actionsRestantes);
        vue->setStatuts(MappeurStatuts::getStatutsTache());
        if (vue->exec() == vue->Accepted) {
            Tache* tache = new Tache(this);
            tache->setIdFiche(m_idFiche);
            tache->setAction(MappeurActions::get(vue->getAction()));
            tache->setStatut(MappeurStatuts::getStatutTache(vue->getStatut()));
            tache->setCommentaire(vue->getCommentaire());
            ui->tableauTaches->setRowCount(ui->tableauTaches->rowCount()+1);
            setTache(tache, ui->tableauTaches->rowCount()-1);
            delete tache;
        }
    }
    qDeleteAll(*actionsRestantes);
    delete actionsRestantes;
}

void VueEditionFiche::retirerTache()
{
    int rangeeSelectionnee = ui->tableauTaches->currentRow();
    if (rangeeSelectionnee >= 0 && rangeeSelectionnee < ui->tableauTaches->rowCount()) {
        ui->tableauTaches->removeRow(rangeeSelectionnee);
        if (ui->tableauTaches->rowCount() == 0) {
            ui->boutonRetirerTache->setEnabled(false);
        }
    }
}

void VueEditionFiche::tacheSelectionnee()
{
    ui->boutonRetirerTache->setEnabled(true);
}
