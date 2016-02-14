#include "controleurongletappareils.h"

#include "Controleurs/application.h"
#include "Controleurs/controleurappareils.h"
#include "Controleurs/requetessql.h"
#include "Mappeurs/mappeurappareils.h"
#include "Mappeurs/mappeurfiches.h"

#include <QLayout>
#include <QSqlQueryModel>

ControleurOngletAppareils::ControleurOngletAppareils(QWidget* vue)
    : QObject(vue)
{
    fragment = new Fragment(vue);
    fragment->retirerEtiquette();
    fragment->boutonAjouter()->deleteLater();
    fragment->retirerCaseCocher();
    vue->layout()->addWidget(fragment);

    configurerBoutonSupprimer();

    QObject::connect(fragment, SIGNAL(rechercher(QString)), this, SLOT(filtrerAppareils(QString)));
    QObject::connect(fragment, SIGNAL(clicVoir()), this, SLOT(voirAppareil()));
    QObject::connect(fragment, SIGNAL(clicEditer()), this, SLOT(modifierAppareil()));
    QObject::connect(Application::getInstance(), SIGNAL(appareilsModifies()), this, SLOT(rafraichir()));
    QObject::connect(Application::getInstance(), SIGNAL(nombreAppareilsChange()), this, SLOT(recharger()));
    QObject::connect(fragment, SIGNAL(doubleClicModele()), this, SLOT(voirAppareil()));
    fragment->champ()->setFocus();
}

void ControleurOngletAppareils::configurerBoutonSupprimer()
{
    boutonSupprimer = fragment->ajouterBoutonNonConnecte(4, tr("Supprimer"), QIcon(":/Images/edit-delete"));
    boutonSupprimer->setEnabled(false);
    QObject::connect(fragment, SIGNAL(selectionValide(bool)), this, SLOT(activerBoutonSupprimer(bool)));
    QObject::connect(boutonSupprimer, SIGNAL(clicked()), this, SLOT(supprimer()));
}

void ControleurOngletAppareils::activerBoutonSupprimer(const bool actif)
{
    if (!actif) {
        boutonSupprimer->setEnabled(false);
    } else {
        if (MappeurFiches::nombreFiches(fragment->getIdModele()) == 0) {
            boutonSupprimer->setEnabled(true);
            boutonSupprimer->setToolTip("");
        } else {
            boutonSupprimer->setEnabled(false);
            boutonSupprimer->setToolTip(tr("Cet appareil ne peut pas être supprimé."));
        }
    }
}

void ControleurOngletAppareils::supprimer() const
{
    if (fragment->getIdModele() != -1) {
        ControleurAppareils::effacerAppareil(fragment->getIdModele());
    }
}

void ControleurOngletAppareils::peuplerAppareils()
{
    QSqlQueryModel* appareils = new QSqlQueryModel(this);
    appareils->setQuery(*RequetesSQL::afficherAppareils, *Application::bd);
    fragment->peuplerTableau(appareils);
    fragment->getTableau()->hideColumn(fragment->getColonneId());
}

void ControleurOngletAppareils::modifierAppareil()
{
    if (fragment->getIdModele() != -1) {
        ControleurAppareils::modifierAppareil(fragment->getIdModele());
    }
}

void ControleurOngletAppareils::voirAppareil()
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

void ControleurOngletAppareils::rafraichir()
{
    int selection = fragment->getTableau()->currentIndex().row();
    recharger();
    fragment->getTableau()->selectRow(selection);
}

