#include "controleuractions.h"

#include "Controleurs/application.h"
#include "Mappeurs/mappeuractions.h"
#include "Mappeurs/mappeurtaches.h"
#include "Modeles/action.h"
#include "Vues/vueprincipale.h"
#include "Vues/vuegestionaction.h"

#include <QMessageBox>

void ControleurActions::assignerAction(VueGestionAction* vue, const Action* action)
{
    vue->setNom(action->nom());
    vue->setDescription(action->description());
    vue->setEtat(action->etat());
}

void ControleurActions::extraireAction(Action* action, const VueGestionAction* vue)
{
    action->setNom(vue->getNom());
    action->setDescription(vue->getDescription());
    action->setEtat(vue->getEtat());
}

int ControleurActions::creerAction()
{
    Action* action = creerEtRetournerAction();
    int id = -1;
    if (action != NULL) {
        id = action->id();
        delete action;
    }
    return id;
}

Action* ControleurActions::creerEtRetournerAction()
{
    Action* action = NULL;
    VueGestionAction* vue = new VueGestionAction(Application::vuePrincipale());
    vue->setWindowTitle(tr("Créer une nouvelle action"));
    vue->setEtat(true);
    if (vue->exec() == vue->Accepted) {
        action = new Action();
        extraireAction(action, vue);
        if (MappeurActions::inserer(action)) {
            emit Application::getInstance()->nombreActionsChange();
        }
    }
    vue->deleteLater();
    return action;
}

void ControleurActions::modifierAction(const int &idAction)
{
    Action* action = MappeurActions::get(idAction);
    if (action != NULL) {
        VueGestionAction* vue = new VueGestionAction(Application::vuePrincipale());
        vue->setWindowTitle(tr("Modifier une action"));
        assignerAction(vue, action);
        if (vue->exec()) {
            extraireAction(action, vue);
            if (MappeurActions::mettreAJour(action)) {
                emit Application::getInstance()->actionModifiee();
            }
        }
    }
    action->deleteLater();
}

void ControleurActions::effacerAction(const int &idAction)
{
    QList<Tache*>* usages = MappeurTaches::tachesPourAction(idAction);
    if (usages->isEmpty()) {
        Action* action = MappeurActions::get(idAction);
        if (action != NULL) {
            QMessageBox* confirmation = new QMessageBox(QMessageBox::Warning,
                                            tr("Confirmation de la suppression"),
                                            tr("Supprimer l'action «") + action->nom()+"» ?",
                                            QMessageBox::Ok | QMessageBox::Cancel);
            confirmation->setDefaultButton(QMessageBox::Cancel);
            if (confirmation->exec() == confirmation->Ok) {
                if (MappeurActions::supprimer(action)) {
                    emit Application::getInstance()->nombreActionsChange();
                }
            }
            confirmation->deleteLater();
            action->deleteLater();
        }
    }
    qDeleteAll(*usages);
    delete usages;
}

void ControleurActions::changerEtat(const int &idAction)
{
    Action* action = MappeurActions::get(idAction);
    if (action != NULL) {
        action->setEtat(!action->etat());
        if (MappeurActions::mettreAJour(action)) {
            emit Application::getInstance()->actionModifiee();
        }
    }
    action->deleteLater();
}
