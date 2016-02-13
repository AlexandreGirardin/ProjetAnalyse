#include "controleuractions.h"
#include "ui_vueprincipale.h"

#include "Controleurs/application.h"
#include "Mappeurs/mappeuractions.h"
#include "Vues/vueaction.h"

#include <QMessageBox>
#include <QSqlQueryModel>
#include <QDebug>

void ControleurActions::assignerAction(VueGestionAction* vue, const Action *action)
{
    vue->setNom(action->nom());
    vue->setDescription(action->description());
    vue->setEtat(action->etat());
}

void ControleurActions::creerAction()
{
    Action* action = creerEtRetournerAction();
    if (action != NULL) {
        delete action;
    }
}

Action* ControleurActions::creerEtRetournerAction()
{
    Action* action = NULL;
    VueGestionAction* vue = new VueGestionAction(Application::vuePrincipale());
    vue->setWindowTitle(tr("Créer une nouvelle action"));
    vue->setEtat(true);
    if (vue->exec() == vue->Accepted) {
        action = new Action();
        action->setNom(vue->getNom());
        action->setDescription(vue->getDescription());
        action->setEtat(vue->getEtat());
        if (MappeurActions::inserer(action)) {
            emit Application::getInstance()->actionsModifiees();
        }
    }
    vue->deleteLater();
    return action;
}

void ControleurActions::modifierAction(const int &idAction)
{
    Action* action = MappeurActions::getAction(idAction);
    if (action != NULL) {
        VueGestionAction* vue = new VueGestionAction(Application::vuePrincipale());
        vue->setWindowTitle(tr("Modifier une action"));
        assignerAction(vue, action);
        if (vue->exec()) {
            action->setNom(vue->getNom());
            action->setDescription(vue->getDescription());
            action->setEtat(vue->getEtat());
            if (MappeurActions::mettreAJour(action)) {
                emit Application::getInstance()->actionsModifiees();
            }
        }
    }
    action->deleteLater();
}

void ControleurActions::voirAction(const int &idAction)
{
    Action* action = MappeurActions::getAction(idAction);
    if (action != NULL) {
        VueAction* vue = new VueAction(Application::vuePrincipale());
        vue->setNom(action->nom());
        vue->setDescription(action->description());
        vue->setWindowTitle(tr("Action"));
        QObject::connect(vue, SIGNAL(finished(int)), vue, SLOT(deleteLater()));
        vue->show();
    }
    action->deleteLater();
}

void ControleurActions::changerEtat(const int &idAction)
{
    Action* action = MappeurActions::getAction(idAction);
    if (action != NULL) {
        action->setEtat(!action->etat());
        if (MappeurActions::mettreAJour(action)) {
            emit Application::getInstance()->actionsModifiees();
        }
    }
    action->deleteLater();
}
