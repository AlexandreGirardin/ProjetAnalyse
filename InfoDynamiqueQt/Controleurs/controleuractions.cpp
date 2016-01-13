#include "controleuractions.h"
#include "ui_vueprincipale.h"

#include "Controleurs/controleurbd.h"

#include <QSqlQueryModel>

ControleurActions::ControleurActions(VuePrincipale* vuePrincipale, QObject* parent)
    : QObject(parent) {
    splitter = new QSplitter(Qt::Vertical, vuePrincipale->getUi()->ongletActions);
    vuePrincipale->getUi()->ongletActions->layout()->addWidget(splitter);

    configurerFragmentActions();
    configurerFragmentEnsembles();

    requeteToutesActions = new QString("SELECT * FROM actions");
    requeteActionsActives = new QString("SELECT * FROM actions WHERE etat = 1");
    requeteActions = requeteActionsActives;
    requeteToutesActionsFiltre = new QString(*requeteToutesActions
                                             + QString(" WHERE id LIKE :filtre\
                                                       OR nom LIKE :filtre\
                                                       OR description LIKE :filtre"));
    requeteActionsActivesFiltre = new QString(*requeteActionsActives
                                             + QString(" HAVING id LIKE :filtre\
                                                       OR nom LIKE :filtre\
                                                       OR description LIKE :filtre"));
    requeteActionsFiltre = requeteToutesActionsFiltre;

    requeteEnsembles = new QString("SELECT * FROM ensembles");

    QObject::connect(fragmentActions, SIGNAL(caseCochee()), this, SLOT(activerCritereActions()));
    QObject::connect(fragmentActions, SIGNAL(caseDecochee()), this, SLOT(desactiverCritereActions()));
            QObject::connect(fragmentActions, SIGNAL(rechercher(QString)), this, SLOT(filtrerActions(QString)));
    fragmentActions->getCaseCocher()->setChecked(true);
}

void ControleurActions::configurerFragmentActions() {
    fragmentActions = new VueFragment(splitter);
    fragmentActions->getEtiquette()->setText(tr("Actions"));
    fragmentActions->getCaseCocher()->setText(tr("Afficher toutes les actions"));
}

void ControleurActions::configurerFragmentEnsembles() {
    fragmentEnsembles = new VueFragment(splitter);
    fragmentEnsembles->getEtiquette()->setText(tr("Ensembles"));
    fragmentEnsembles->getCaseCocher()->setHidden(true);
}

void ControleurActions::peuplerActions() {
    QSqlQueryModel* actions = new QSqlQueryModel(this);
    const QSqlDatabase bd = QSqlDatabase::database(ControleurBD::nomBd());
    actions->setQuery(*requeteActions, bd);
    fragmentActions->peuplerTableau(actions);
}

void ControleurActions::peuplerEnsembles() {
    QSqlQueryModel* ensembles = new QSqlQueryModel(this);
    const QSqlDatabase bd = QSqlDatabase::database(ControleurBD::nomBd());
    ensembles->setQuery(*requeteEnsembles, bd);
    fragmentEnsembles->peuplerTableau(ensembles);
}

void ControleurActions::activerCritereActions() {
    requeteActions = requeteActionsActives;
    requeteActionsFiltre = requeteActionsActivesFiltre;
    filtrerActions(fragmentActions->getChamp()->text());
}

void ControleurActions::desactiverCritereActions() {
    requeteActions = requeteToutesActions;
    requeteActionsFiltre = requeteToutesActionsFiltre;
    filtrerActions(fragmentActions->getChamp()->text());
}

void ControleurActions::filtrerActions(QString filtre) {
    if (filtre.isEmpty()) {
        peuplerActions();
    } else {
        QSqlQuery requete = QSqlQuery(QSqlDatabase::database(ControleurBD::nomBd()));
        requete.prepare(*requeteActionsFiltre);
        const QString* meta = ControleurBD::meta();
        requete.bindValue(":filtre", *meta + filtre + *meta);
        requete.exec();
        QSqlQueryModel* resultats = new QSqlQueryModel(this);
        resultats->setQuery(requete);
        fragmentActions->peuplerTableau(resultats);
    }
}

