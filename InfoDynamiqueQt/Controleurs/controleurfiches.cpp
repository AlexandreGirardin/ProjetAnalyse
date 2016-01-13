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
    definirCommandes();
    QObject::connect(fragment, SIGNAL(rechercher(QString)), this, SLOT(filtrerFiches(QString)));
}

void ControleurFiches::definirCommandes()
{
    commandeFiches = new QString("SELECT * FROM fiches");
    commandeFiltrerFiches = new QString(*commandeFiches +
                                        QString(" WHERE id LIKE :filtre\
                                                OR idAppareil LIKE :filtre\
                                                OR priorite LIKE :filtre\
                                                OR idTechnicien LIKE :filtre\
                                                OR idStatut LIKE :filtre\
                                                OR commentaire LIKE :filtre"));
}

void ControleurFiches::peuplerFiches()
{
    QSqlQueryModel* fiches = new QSqlQueryModel(this);
    fiches->setQuery(*commandeFiches, *Application::bd);
    fragment->peuplerTableau(fiches);
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
        requete.prepare(*commandeFiltrerFiches);
        QString* metacaractere = new QString("%");
        requete.bindValue(":filtre", *metacaractere + filtre + *metacaractere);
        requete.exec();
        QSqlQueryModel* resultats = new QSqlQueryModel(this);
        resultats->setQuery(requete);
        fragment->peuplerTableau(resultats);
    }
}

