#include "controleuractions.h"
#include "ui_vueprincipale.h"

#include "Controleurs/application.h"
#include "Mappeurs/mappeuractions.h"
#include "Vues/vueaction.h"

#include <QMessageBox>
#include <QSqlQueryModel>
#include <QDebug>

ControleurActions::ControleurActions(QWidget* vue) : QObject(vue) {}

void ControleurActions::assignerAction(VueGestionAction* vue, const Action *action) const
{
    vue->setNom(action->nom());
    vue->setDescription(action->description());
    vue->setEtat(action->etat());
}

void ControleurActions::creerAction()
{
    VueGestionAction* vue = new VueGestionAction(Application::vuePrincipale());
    vue->setWindowTitle(tr("Créer une nouvelle action"));
    vue->setEtat(true);
    if (vue->exec() == vue->Accepted) {
        Action* action = new Action(vue);
        action->setNom(vue->getNom());
        action->setDescription(vue->getDescription());
        action->setEtat(vue->getEtat());
        if (MappeurActions::inserer(action)) {
            emit actionsModifiees();
        }
    }
    vue->deleteLater();
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
                emit actionsModifiees();
            }
        }
    }
    action->deleteLater();
}

void ControleurActions::voirAction(const int &idAction) const
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
            emit actionsModifiees();
        }
    }
    action->deleteLater();
}
