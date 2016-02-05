#include "controleuractions.h"
#include "ui_vueprincipale.h"

#include "Controleurs/application.h"
#include "Controleurs/controleurbd.h"
#include "Vues/vueensemble.h"
#include "Vues/vuegestionensemble.h"

#include <QMessageBox>
#include <QSqlQueryModel>
#include <QDebug>

ControleurActions::ControleurActions(QWidget* vue)
    : QObject(vue)
{
}

void ControleurActions::assignerAction(VueGestionAction* vue, const Action *action) const
{
    vue->setNom(action->nom());
    vue->setDescription(action->description());
    vue->setEtat(action->etat());
}

void ControleurActions::modifierAction(const int &idAction)
{
    Action* action = Application::actions->getAction(idAction);
    if (action != NULL) {
        VueGestionAction* vue = new VueGestionAction(Application::vuePrincipale());
        assignerAction(vue, action);
        if (vue->exec()) {
            action->setNom(vue->getNom());
            action->setDescription(vue->getDescription());
            action->setEtat(vue->getEtat());
            if (Application::actions->mettreAJour(action)) {
                emit actionsModifiees();
            }
        }
    }
    action->deleteLater();
}

void ControleurActions::voirAction(const int &idAction) const
{
    Action* action = Application::actions->getAction(idAction);
    if (action != NULL) {
        VueGestionAction* vue = new VueGestionAction(Application::vuePrincipale());
        assignerAction(vue, action);
        vue->setLectureSeule(true);
        QObject::connect(vue, SIGNAL(finished(int)), vue, SLOT(deleteLater()));
        vue->show();
    }
    action->deleteLater();
}

void ControleurActions::changerEtat(const int &idAction)
{
    Action* action = Application::actions->getAction(idAction);
    if (action != NULL) {
        action->setEtat(!action->etat());
        if (Application::actions->mettreAJour(action)) {
            emit actionsModifiees();
        }
    }
    action->deleteLater();
}
