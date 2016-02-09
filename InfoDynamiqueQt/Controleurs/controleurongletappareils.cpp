#include "controleurongletappareils.h"
#include "ui_vueprincipale.h"

#include "Controleurs/controleurbd.h"
#include "Controleurs/requetessql.h"

#include <QSqlQueryModel>
#include <QDebug>
#include "Controleurs/application.h"

ControleurAppareils::ControleurAppareils(QWidget* vue)
    : QObject(vue)
{
    fragment = new Fragment(vue);
    fragment->retirerEtiquette();
    fragment->boutonAjouter()->deleteLater();
    fragment->retirerCaseCocher();
    vue->layout()->addWidget(fragment);

    controleurGestionAppareil = new ControleurGestionAppareil(this);

    QObject::connect(fragment, SIGNAL(rechercher(QString)), this, SLOT(filtrerAppareils(QString)));
    QObject::connect(fragment, SIGNAL(clicVoir()), this, SLOT(voirAppareil()));
    QObject::connect(fragment, SIGNAL(clicEditer()), this, SLOT(modifierAppareil()));
    QObject::connect(controleurGestionAppareil, SIGNAL(donneesModifiees()), this, SLOT(recharger()));
    QObject::connect(fragment, SIGNAL(doubleClicModele()), this, SLOT(voirAppareil()));
    fragment->champ()->setFocus();
}

void ControleurAppareils::peuplerAppareils()
{
    QSqlQueryModel* appareils = new QSqlQueryModel(this);
    appareils->setQuery(*RequetesSQL::afficherAppareils, *Application::bd);
    fragment->peuplerTableau(appareils);
    fragment->getTableau()->hideColumn(fragment->getColonneId());
}

void ControleurAppareils::modifierAppareil() const
{
    if (fragment->getIdModele() != -1) {
        controleurGestionAppareil->modifierAppareil(fragment->getIdModele());
    }
}

void ControleurAppareils::voirAppareil() const
{
    if (fragment->getIdModele() != -1) {
        controleurGestionAppareil->voirAppareil(fragment->getIdModele());
    }
}

void ControleurAppareils::filtrerAppareils(const QString &filtre)
{
    if (filtre.isEmpty()) {
        peuplerAppareils();
    } else {
        QSqlQuery requete = QSqlQuery(*Application::bd);
        requete.prepare(*RequetesSQL::filtrerAppareils);
        const QString meta = *ControleurBD::meta;
        requete.bindValue(":filtre", meta + filtre + meta);
        requete.exec();
        QSqlQueryModel* resultats = new QSqlQueryModel(this);
        resultats->setQuery(requete);
        fragment->peuplerTableau(resultats);
        fragment->getTableau()->hideColumn(fragment->getColonneId());
    }
}

void ControleurAppareils::recharger()
{
    filtrerAppareils(fragment->getFiltre());
}

