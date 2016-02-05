#include "Controleurs/controleurfiches.h"

#include "Controleurs/application.h"

#include <QLayout>
#include <QSqlQueryModel>

ControleurFiches::ControleurFiches(QWidget* vue)
    : QObject(vue)
{
    fragment = new VueFragment();
    fragment->retirerEtiquette();
    fragment->getCaseCocher()->setText(tr("Afficher toutes les fiches"));
    vue->layout()->addWidget(fragment);
    QObject::connect(fragment, SIGNAL(rechercher(QString)), this, SLOT(filtrerFiches(QString)));
    QObject::connect(fragment, SIGNAL(clicCreer()), this, SLOT(creerFiche()));
    QObject::connect(fragment, SIGNAL(clicEditer()), this, SLOT(modifierFiche()));
    QObject::connect(fragment, SIGNAL(clicVoir()), this, SLOT(voirFiche()));
    QObject::connect(fragment, SIGNAL(doubleClicModele()), this, SLOT(voirFiche()));
}

void ControleurFiches::peuplerFiches()
{
    QSqlQueryModel* fiches = new QSqlQueryModel(this);
    fiches->setQuery(*RequetesSQL::afficherFiches, *Application::bd);
    fragment->peuplerTableau(fiches);
    fragment->getTableau()->hideColumn(0);
}

void ControleurFiches::creerFiche() const
{

}

void ControleurFiches::modifierFiche() const
{

}

void ControleurFiches::voirFiche() const
{
}

void ControleurFiches::filtrerFiches(const QString &filtre)
{
    if (filtre.isEmpty()) {
        peuplerFiches();
    } else {
        QSqlQuery requete = QSqlQuery(*Application::bd);
        requete.prepare(*RequetesSQL::filtrerFiches);
        const QString* metacaractere = new QString("%");
        requete.bindValue(":filtre", *metacaractere + filtre + *metacaractere);
        requete.exec();
        QSqlQueryModel* resultats = new QSqlQueryModel(this);
        resultats->setQuery(requete);
        fragment->peuplerTableau(resultats);
        fragment->getTableau()->hideColumn(0);
    }
}

