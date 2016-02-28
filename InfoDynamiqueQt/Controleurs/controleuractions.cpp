#include "controleuractions.h"

#include "Controleurs/application.h"
#include "Mappeurs/mappeuractions.h"
#include "Mappeurs/mappeurtaches.h"
#include "Modeles/action.h"
#include "Vues/vueprincipale.h"
#include "Vues/vuegestionaction.h"

#include <QMessageBox>

int ControleurActions::creerAction()
{
    int id = -1;
    VueGestionAction* vue = new VueGestionAction(Application::vuePrincipale());
    vue->setWindowTitle(tr("Créer une nouvelle action"));
    vue->setEtat(true);
    if (vue->exec() == vue->Accepted) {
        Action* action = new Action();
        extraireAction(action, vue);
        if (MappeurActions::inserer(action)) {
            id = action->id();
            emit Application::get()->nombreActionsChange();
        }
        action->deleteLater();
    }
    vue->deleteLater();
    return id;
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
                emit Application::get()->actionModifiee();
            }
        }
        vue->deleteLater();
        action->deleteLater();
    }
}

void ControleurActions::effacerAction(const int &idAction)
{
    int usages = MappeurTaches::tachesPourAction(idAction);
    if (usages == 0) {
        Action* action = MappeurActions::get(idAction);
        if (action != NULL) {
            QMessageBox* confirmation = new QMessageBox(QMessageBox::Warning,
                                            tr("Confirmation de la suppression"),
                                            tr("Supprimer l'action «") + action->nom()+"» ?",
                                            QMessageBox::Ok | QMessageBox::Cancel);
            confirmation->setDefaultButton(QMessageBox::Cancel);
            if (confirmation->exec() == confirmation->Ok) {
                if (MappeurActions::supprimer(action)) {
                    emit Application::get()->nombreActionsChange();
                }
            }
            confirmation->deleteLater();
            action->deleteLater();
        }
    }
}

void ControleurActions::changerEtat(const int &idAction)
{
    Action* action = MappeurActions::get(idAction);
    if (action != NULL) {
        action->setEtat(!action->etat());
        if (MappeurActions::mettreAJour(action)) {
            emit Application::get()->actionModifiee();
        }
        action->deleteLater();
    }
}

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
