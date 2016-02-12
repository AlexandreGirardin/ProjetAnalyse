#include "controleurongletappareils.h"
#include "ui_vueprincipale.h"

#include "Controleurs/controleurbd.h"
#include "Controleurs/requetessql.h"

#include <QSqlQueryModel>
#include <QDebug>
#include "Controleurs/application.h"

ControleurOngletAppareils::ControleurOngletAppareils(QWidget* vue)
    : QObject(vue)
{
    fragment = new Fragment(vue);
    fragment->retirerEtiquette();
    fragment->boutonAjouter()->deleteLater();
    fragment->retirerCaseCocher();
    vue->layout()->addWidget(fragment);

    QObject::connect(fragment, SIGNAL(rechercher(QString)), this, SLOT(filtrerAppareils(QString)));
    QObject::connect(fragment, SIGNAL(clicVoir()), this, SLOT(voirAppareil()));
    QObject::connect(fragment, SIGNAL(clicEditer()), this, SLOT(modifierAppareil()));
    QObject::connect(Application::getInstance(), SIGNAL(appareilsModifies()), this, SLOT(recharger()));
    QObject::connect(fragment, SIGNAL(doubleClicModele()), this, SLOT(voirAppareil()));
    fragment->champ()->setFocus();
}

void ControleurOngletAppareils::peuplerAppareils()
{
    QSqlQueryModel* appareils = new QSqlQueryModel(this);
    appareils->setQuery(*RequetesSQL::afficherAppareils, *Application::bd);
    fragment->peuplerTableau(appareils);
    fragment->getTableau()->hideColumn(fragment->getColonneId());
}

void ControleurOngletAppareils::modifierAppareil() const
{
    if (fragment->getIdModele() != -1) {
        ControleurAppareils::modifierAppareil(fragment->getIdModele());
    }
}

void ControleurOngletAppareils::voirAppareil() const
{
    if (fragment->getIdModele() != -1) {
        ControleurAppareils::voirAppareil(fragment->getIdModele());
    }
}

void ControleurOngletAppareils::filtrerAppareils(const QString &filtre)
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

void ControleurOngletAppareils::recharger()
{
    filtrerAppareils(fragment->getFiltre());
}

