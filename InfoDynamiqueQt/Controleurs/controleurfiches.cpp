#include "Controleurs/controleurfiches.h"

#include "Controleurs/application.h"

#include <QLayout>
#include <QSqlQueryModel>

ControleurFiches::ControleurFiches(VuePrincipale* vuePrincipale, QObject* parent)
    : QObject(parent)
{
    fragment = new VueFragment();
    fragment->getEtiquette()->setText(tr("Fiches"));
    fragment->getCaseCocher()->setText(tr("Afficher toutes les fiches"));
    vuePrincipale->getOngletFiches()->layout()->addWidget(fragment);
    QObject::connect(fragment, SIGNAL(rechercher(QString)), this, SLOT(filtrerFiches(QString)));
}

void ControleurFiches::peuplerFiches()
{
    QSqlQueryModel* fiches = new QSqlQueryModel(this);
    fiches->setQuery(*RequetesSQL::afficherFiches, *Application::bd);
    fragment->peuplerTableau(fiches);
    fragment->getTableau()->hideColumn(0);
}

void ControleurFiches::modifierFiche()
{

}

void ControleurFiches::voirFiche()
{
}

void ControleurFiches::filtrerFiches(QString filtre)
{
    if (filtre.isEmpty()) {
        peuplerFiches();
    } else {
        QSqlQuery requete = QSqlQuery(*Application::bd);
        requete.prepare(*RequetesSQL::filtrerFiches);
        QString* metacaractere = new QString("%");
        requete.bindValue(":filtre", *metacaractere + filtre + *metacaractere);
        requete.exec();
        QSqlQueryModel* resultats = new QSqlQueryModel(this);
        resultats->setQuery(requete);
        fragment->peuplerTableau(resultats);
        fragment->getTableau()->hideColumn(0);
    }
}

