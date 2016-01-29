#include "controleurappareils.h"
#include "ui_vueprincipale.h"

#include "Controleurs/controleurbd.h"

#include <QSqlQueryModel>
#include <QDebug>
#include "Controleurs/application.h"

ControleurAppareils::ControleurAppareils(QWidget* vue)
    : QObject(vue)
{
    fragment = new VueFragment(vue);
    fragment->getEtiquette()->deleteLater();
    fragment->getBoutonAjouter()->deleteLater();
    fragment->getCaseCocher()->deleteLater();
    vue->layout()->addWidget(fragment);
    QObject::connect(fragment, SIGNAL(rechercher(QString)), this, SLOT(filtrerAppareils(QString)));
    QObject::connect(fragment, SIGNAL(clicVoir()), this, SLOT(voirAppareil()));
    QObject::connect(fragment, SIGNAL(clicEditer()), this, SLOT(modifierAppareil()));
    QObject::connect(this, SIGNAL(donneesModifiees()), this, SLOT(recharger()));
    QSqlDatabase bd = QSqlDatabase::database(ControleurBD::nomBd());
}

void ControleurAppareils::peuplerAppareils()
{
    QSqlQueryModel* appareils = new QSqlQueryModel(this);
    appareils->setQuery(*RequetesSQL::afficherAppareils, *Application::bd);
    fragment->peuplerTableau(appareils);
    fragment->getTableau()->hideColumn(0);
}

void ControleurAppareils::modifierAppareil()
{
    Appareil* appareil = Application::appareils->getAppareil(fragment->getIdModele());
    if (appareil != NULL) {
        VueGestionAppareil* vue = new VueGestionAppareil(Application::getVuePrincipale());
        vue->setTypes(Application::typesAppareils->getTypesAppareil(), appareil->getNomType());
        vue->setFabricants(Application::fabricants->getFabricants(), appareil->getNomFabricant());
        vue->setMotDePasse(appareil->getMotDePasse());
        vue->setDescription(appareil->getDescription());
        if (vue->exec() == vue->Accepted) {
            appareil->setMotDePasse(vue->getMotDePasse());
            appareil->setType(vue->getType());
            appareil->setFabricant(vue->getFabricant());
            appareil->setDescription(vue->getDescription());
            if (Application::appareils->mettreAJour(appareil)) {
                emit donneesModifiees();
            } else {
                qDebug() << "Pas marché: " << appareil->out();
            }
        }
    }
    appareil->deleteLater();
}

void ControleurAppareils::voirAppareil()
{
    Appareil* appareil = Application::appareils->getAppareil(fragment->getIdModele());
    if (appareil != NULL) {
        VueAppareil* vue = new VueAppareil(Application::getVuePrincipale());
        vue->setType(appareil->getNomType());
        vue->setFabricant(appareil->getNomFabricant());
        vue->setMotDePasse(appareil->getMotDePasse());
        vue->setDescription(appareil->getDescription());
        vue->show();
    }
    appareil->deleteLater();
}

void ControleurAppareils::filtrerAppareils(QString filtre)
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
        fragment->getTableau()->hideColumn(0);
    }
}

void ControleurAppareils::recharger()
{
    filtrerAppareils(fragment->getChamp()->text());
}

