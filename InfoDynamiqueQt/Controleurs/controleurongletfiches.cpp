#include "Controleurs/controleurongletfiches.h"

#include "Controleurs/application.h"
#include "Controleurs/requetessql.h"
#include "Vues/vueeditionfiche.h"
#include "Vues/vuegestionfiche.h"

#include <QLayout>
#include <QSqlQueryModel>

ControleurOngletFiches::ControleurOngletFiches(QWidget* vue)
    : QObject(vue)
{
    fragment = new Fragment();
    fragment->retirerEtiquette();
    fragment->caseCocher()->setText(tr("Afficher toutes les fiches"));
    boutonTraiter = fragment->ajouterBouton(4);
    boutonTraiter->setText(tr("Traiter"));
    boutonTraiter->setIcon(QIcon(":/Images/document-edit-sign"));
    vue->layout()->addWidget(fragment);
    QObject::connect(fragment, SIGNAL(rechercher(QString)), this, SLOT(filtrerFiches(QString)));
    QObject::connect(fragment, SIGNAL(clicCreer()), this, SLOT(creerFiche()));
    QObject::connect(fragment, SIGNAL(clicEditer()), this, SLOT(modifierFiche()));
    QObject::connect(boutonTraiter, SIGNAL(clicked()), this, SLOT(traiterFiche()));
    QObject::connect(fragment, SIGNAL(clicVoir()), this, SLOT(voirFiche()));
    QObject::connect(fragment, SIGNAL(doubleClicModele()), this, SLOT(voirFiche()));
    fragment->champ()->setFocus();
}

void ControleurOngletFiches::peuplerFiches()
{
    QSqlQueryModel* fiches = new QSqlQueryModel(this);
    fiches->setQuery(*RequetesSQL::afficherFiches, *Application::bd);
    fragment->peuplerTableau(fiches);
    fragment->getTableau()->hideColumn(0);
}

void ControleurOngletFiches::creerFiche() const
{

}

void ControleurOngletFiches::modifierFiche() const
{
    Fiche* fiche = MappeurFiches::getFiche(fragment->getIdModele());
    if (fiche != NULL) {
        VueGestionFiche* vue = new VueGestionFiche(Application::vuePrincipale());
        vue->setDescription(fiche->commentaire());
        vue->exec();
        vue->deleteLater();
    }
}

void ControleurOngletFiches::traiterFiche() const
{
    Fiche* fiche = MappeurFiches::getFiche(fragment->getIdModele());
    if (fiche != NULL) {
        VueEditionFiche* vue = new VueEditionFiche(Application::vuePrincipale());
        vue->setIdFiche(fiche->id());
        vue->setCommentaire(fiche->commentaire());
        vue->exec();
        vue->deleteLater();
    }
}

void ControleurOngletFiches::voirFiche() const
{
}

void ControleurOngletFiches::filtrerFiches(const QString &filtre)
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

