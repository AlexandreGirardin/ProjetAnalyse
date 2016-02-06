#include "controleurensembles.h"

#include "Controleurs/application.h"
#include "Modeles/action.h"
#include "Vues/vueensemble.h"
#include "Vues/vuegestionensemble.h"

#include <QDebug>
#include <QMessageBox>
#include <QSqlQueryModel>

ControleurGestionEnsemble::ControleurGestionEnsemble(QObject *parent) : QObject(parent) {}

void ControleurGestionEnsemble::creerEnsemble()
{
    VueGestionEnsemble* vue = new VueGestionEnsemble(Application::vuePrincipale());
    vue->setWindowTitle(tr("Créer un nouvel ensemble de tâches"));
    vue->setActionsHorsEnsemble(Application::actions->getActions());
    if (vue->exec() == vue->Accepted) {
        EnsembleActions* ensemble = new EnsembleActions(vue);
        ensemble->setNom(vue->getNom());
        ensemble->setDescription(vue->getDescription());
        ensemble->setActions(vue->getActionsDansEnsemble());
        if (Application::ensembles->inserer(ensemble)) {
            emit ensemblesModifies();
        } else {
            qDebug() << "Pas marché :(";
        }
        vue->deleteLater();
    }
}

void ControleurGestionEnsemble::modifierEnsemble(const int &idEnsemble)
{
    EnsembleActions* ensemble = Application::ensembles->getEnsemble(idEnsemble);
    VueGestionEnsemble* vue = new VueGestionEnsemble(Application::vuePrincipale());
    vue->setWindowTitle(tr("Modifier un ensemble de tâches"));
    QList<Action*>* actionsHorsEnsemble = Application::actions->actionsHorsEnsemble(ensemble->id());
    vue->setActionsHorsEnsemble(actionsHorsEnsemble);
    vue->setActionsDansEnsemble(Application::actions->actionsDansEnsemble(ensemble->id()));
    vue->setNom(ensemble->nom());
    vue->setDescription(ensemble->description());
    if (vue->exec() == vue->Accepted) {
        ensemble->setNom(vue->getNom());
        ensemble->setDescription(vue->getDescription());
        ensemble->setActions(vue->getActionsDansEnsemble());
        if (Application::ensembles->mettreAJour(ensemble)) {
            emit ensemblesModifies();
        } else {
            qDebug() << "Pas marché :(";
        }
        vue->deleteLater();
    }
}

void ControleurGestionEnsemble::voirEnsemble(const int &idEnsemble) const
{
    VueEnsemble* vue = new VueEnsemble(Application::vuePrincipale());
    vue->setWindowTitle(tr("Ensemble de tâches"));
    EnsembleActions* ensemble = Application::ensembles->getEnsemble(idEnsemble);
    QObject::connect(vue, SIGNAL(finished(int)), vue, SLOT(deleteLater()));
    vue->setNom(ensemble->nom());
    vue->setDescription(ensemble->description());
    vue->setActions(ensemble->actions());
    vue->show();
    ensemble->deleteLater();
}

void ControleurGestionEnsemble::supprimerEnsemble(const int &idEnsemble)
{
    EnsembleActions* ensemble = Application::ensembles->getEnsemble(idEnsemble);
    QMessageBox* confirmation = new QMessageBox(QMessageBox::Warning,
                    tr("Confirmation de la suppression"),
                    tr("Supprimer l'ensemble «") + ensemble->nom()+"» ?",
                    QMessageBox::Apply | QMessageBox::Cancel);
    if (confirmation->exec() == confirmation->Apply) {
        if (Application::ensembles->supprimer(ensemble)) {
            emit ensemblesModifies();
        }
    }
    confirmation->deleteLater();
    ensemble->deleteLater();
}
