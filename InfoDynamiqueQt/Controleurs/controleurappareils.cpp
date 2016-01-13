#include "controleurappareils.h"
#include "ui_vueprincipale.h"

#include "Controleurs/controleurbd.h"

#include <QSqlQueryModel>
#include <QDebug>
#include "Controleurs/application.h"

ControleurAppareils::ControleurAppareils(VuePrincipale* vuePrincipale, QObject* parent)
    : QObject(parent)
{
    fragment = new VueFragment();
    fragment->getEtiquette()->setText(tr("Appareils"));
    fragment->getCaseCocher()->hide();
    vuePrincipale->getUi()->ongletAppareils->layout()->addWidget(fragment);
    definirCommandes();
    QObject::connect(fragment, SIGNAL(rechercher(QString)), this, SLOT(filtrerAppareils(QString)));
    QObject::connect(fragment, SIGNAL(clicVoir()), this, SLOT(voirAppareil()));
    QObject::connect(fragment, SIGNAL(clicEditer()), this, SLOT(modifierAppareil()));
    QObject::connect(fragment, SIGNAL(clicCreer()), this, SLOT(nouvelAppareil()));
    QSqlDatabase bd = QSqlDatabase::database(ControleurBD::nomBd());
    mappeur = Application::appareils;
}

void ControleurAppareils::definirCommandes()
{
    commandeAppareils = new QString(
            "SELECT\
                a.id AS '#',\
                f.nom AS 'Fabricant',\
                COALESCE(fi.nbO, 0) as 'Fiches',\
                a.description AS 'Description'\
            FROM\
                appareils a\
            LEFT OUTER JOIN\
                (select id, nom from fabricants) f\
            ON\
                a.idFabricant = f.id\
            LEFT OUTER JOIN\
                (select idAppareil, count(id) as 'nbO' from fiches group by idAppareil) fi\
            ON\
                a.id = fi.idAppareil");
    commandeFiltrerAppareils = new QString(*commandeAppareils +
                                           QString(" WHERE a.id LIKE :filtre\
                                                   OR f.nom LIKE :filtre\
                                                   OR a.description LIKE :filtre"));
}

void ControleurAppareils::peuplerAppareils()
{
    QSqlQueryModel* appareils = new QSqlQueryModel(this);
    const QSqlDatabase bd = QSqlDatabase::database(ControleurBD::nomBd());
    appareils->setQuery(*commandeAppareils, bd);
    fragment->peuplerTableau(appareils);
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
        vue->exec();
        appareil->setMotDePasse(vue->getMotDePasse());
        appareil->setType(vue->getType());
        appareil->setFabricant(vue->getFabricant());
        appareil->setDescription(vue->getDescription());
        qDebug() << appareil->out() << " " << appareil->getMotDePasse();
    }
}

void ControleurAppareils::nouvelAppareil()
{
    VueGestionAppareil* vue = new VueGestionAppareil(Application::getVuePrincipale());
    vue->setTypes(Application::typesAppareils->getTypesAppareil());
    vue->setFabricants(Application::fabricants->getFabricants());
    vue->exec();
    Appareil* nouveau = new Appareil(fragment);
    nouveau->setMotDePasse(vue->getMotDePasse());
    nouveau->setType(vue->getType());
    nouveau->setFabricant(vue->getFabricant());
    nouveau->setDescription(vue->getDescription());
    qDebug() << nouveau->out() << " " << nouveau->getMotDePasse();
}

void ControleurAppareils::voirAppareil()
{
    if (fragment->getIdModele() != -1) {
        VueAppareil* vue = new VueAppareil(Application::getVuePrincipale());
        Appareil* appareil = mappeur->getAppareil(fragment->getIdModele());
        vue->getChampFabricant()->setText(appareil->getNomFabricant());
        vue->getChampType()->setText(appareil->getNomType());
        vue->getChampDescription()->setText(appareil->getDescription());
        vue->getChampMotDePasse()->setText(appareil->getMotDePasse());
        vue->show();
    }
}

void ControleurAppareils::filtrerAppareils(QString filtre)
{
    if (filtre.isEmpty()) {
        peuplerAppareils();
    } else {
        QSqlQuery requete = QSqlQuery(QSqlDatabase::database(ControleurBD::nomBd()));
        requete.prepare(*commandeFiltrerAppareils);
        const QString* meta = ControleurBD::meta();
        requete.bindValue(":filtre", *meta + filtre + *meta);
        requete.exec();
        QSqlQueryModel* resultats = new QSqlQueryModel(this);
        resultats->setQuery(requete);
        fragment->peuplerTableau(resultats);
    }
}

