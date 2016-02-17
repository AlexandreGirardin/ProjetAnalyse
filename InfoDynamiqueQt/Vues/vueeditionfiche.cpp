#include "Vues/vueeditionfiche.h"
#include "ui_vueeditionfiche.h"

#include "Controleurs/application.h"
#include "Controleurs/controleurappareils.h"
#include "Controleurs/controleurclients.h"
#include "Controleurs/requetessql.h"

#include <QComboBox>
#include <QDebug>
#include <QStandardItemModel>
//#include <QSqlQueryModel>
//#include <QSqlQuery>

VueEditionFiche::VueEditionFiche(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::VueEditionFiche)
{
    ui->setupUi(this);
    configurerFragmentTaches();
    configurerFragmentPieces();
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

void VueEditionFiche::setTaches(const QList<Tache*>* taches)
{
//    QAbstractItemModel* modele = fragmentTaches->tableau()->model();
//    for (QList<Tache*>::const_iterator i = taches->constBegin(); i != taches->constEnd(); ++i) {
//        QStandardItem* item = new QStandardItem((*i)->action()->nom());
//        modele->insertRow(item);
//    }
//    fragmentTaches->peuplerTableau(modele);
}

void VueEditionFiche::configurerFragmentTaches()
{
    fragmentTaches = new Fragment(this);
    fragmentTaches->setEtiquette(tr("Tâches"));
    delete fragmentTaches->caseCocher();
    delete fragmentTaches->champ();
    ui->cadreFragmentTaches->addWidget(fragmentTaches);
//    QComboBox* combo = fragmentTaches->ajouterCombobox(4);
}

void VueEditionFiche::configurerFragmentPieces()
{
    fragmentPieces = new Fragment(this);
    delete fragmentPieces->caseCocher();
    delete fragmentPieces->champ();
    fragmentPieces->setEtiquette(tr("Pièces"));
    ui->cadreFragmentPieces->addWidget(fragmentPieces);
    QObject::connect(this, SIGNAL(nouvelId()), this, SLOT(peuplerPieces()));
}

void VueEditionFiche::detailsClient()
{
    ControleurClients::voirClient(m_idClient, true);
}

void VueEditionFiche::detailsAppareil()
{
    ControleurAppareils::voirAppareil(m_idAppareil, true);
}

void VueEditionFiche::peuplerTaches()
{
//    QSqlQueryModel* modele = new QSqlQueryModel(this);
//    QSqlQuery requete(*Application::bd);
//    QString commande(*RequetesSQL::tachesPourFiche);
//    modele->setQuery(QSqlQuery(*Application::bd));
//    requete.prepare(commande);
//    requete.bindValue(":idFiche", m_idFiche);
//    requete.exec();
//    modele->setQuery(requete);
//    fragmentTaches->peuplerTableau(modele);
}

void VueEditionFiche::peuplerPieces()
{

}
