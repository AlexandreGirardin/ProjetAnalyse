#include "Controleurs/controleurongletfiches.h"

#include "Controleurs/application.h"
#include "Controleurs/requetessql.h"
#include "Controleurs/controleurfiches.h"
#include "Mappeurs/mappeurensembles.h"
#include "Mappeurs/mappeurfiches.h"
#include "Vues/vueeditionfiche.h"
#include "Vues/vuegestionfiche.h"
#include "Vues/fragment.h"

#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSqlQuery>
#include <QSqlQueryModel>

ControleurOngletFiches::ControleurOngletFiches(QWidget* vue)
    : QObject(vue)
{
    requeteFiches = RequetesSQL::afficherFichesActives;
    fragment = new Fragment();
    fragment->retirerEtiquette();
    fragment->boutonAjouter()->deleteLater();
    fragment->boutonModifier()->deleteLater();
    fragment->boutonVoir()->deleteLater();
    fragment->caseCocher()->setText(tr("Afficher toutes les fiches"));
    boutonTraiter = fragment->ajouterBouton(4);
    boutonTraiter->setText(tr("Traiter"));
    boutonTraiter->setIcon(QIcon(":/Images/document-edit-sign"));
    vue->layout()->addWidget(fragment);

    connect(fragment, SIGNAL(rechercher(QString)), this, SLOT(filtrerFiches(QString)));
    connect(boutonTraiter, SIGNAL(clicked()), this, SLOT(traiterFiche()));
    connect(fragment, SIGNAL(caseCochee()), this, SLOT(desactiverCritereFiches()));
    connect(fragment, SIGNAL(caseDecochee()), this, SLOT(activerCritereFiches()));
    connect(fragment, SIGNAL(doubleClicModele()), this, SLOT(traiterFiche()));
    connect(Application::getInstance(), SIGNAL(ficheModifiee()), this, SLOT(rafraichir()));
    connect(Application::getInstance(), SIGNAL(rafraichirTout()), this, SLOT(recharger()));
    connect(Application::getInstance(), SIGNAL(nombreFichesChange()), this, SLOT(recharger()));
    fragment->champ()->setFocus();
}

void ControleurOngletFiches::peuplerFiches()
{
    QSqlQueryModel* fiches = new QSqlQueryModel(this);
    fiches->setQuery(*requeteFiches, *Application::bd);
    fragment->peuplerTableau(fiches);
}

void ControleurOngletFiches::traiterFiche() const
{
    if (fragment->idModele() != -1) {
        ControleurFiches::traiterFiche(fragment->idModele());
    }
}

void ControleurOngletFiches::filtrerFiches(const QString &filtre)
{
    if (filtre.isEmpty()) {
        peuplerFiches();
    } else {
        QSqlQuery requete = QSqlQuery(*Application::bd);
        requete.prepare(*requeteFichesFiltre);
        const QString* metacaractere = new QString("%");
        requete.bindValue(":filtre", *metacaractere + filtre + *metacaractere);
        requete.exec();
        QSqlQueryModel* resultats = new QSqlQueryModel(this);
        resultats->setQuery(requete);
        fragment->peuplerTableau(resultats);
    }
}

void ControleurOngletFiches::recharger()
{
    filtrerFiches(fragment->filtre());
}

void ControleurOngletFiches::rafraichir()
{
    int selection = fragment->rangeeSelectionnee();
    recharger();
    fragment->selectionnerRangee(selection);
}

void ControleurOngletFiches::activerCritereFiches()
{
    requeteFiches = RequetesSQL::afficherFichesActives;
    requeteFichesFiltre = RequetesSQL::filtrerFichesActives;
    filtrerFiches(fragment->filtre());
}

void ControleurOngletFiches::desactiverCritereFiches()
{
    requeteFiches = RequetesSQL::afficherToutesFiches;
    requeteFichesFiltre = RequetesSQL::filtrerToutesFiches;
    filtrerFiches(fragment->filtre());
}

