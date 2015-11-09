#include "action.h"

Action::Action(int a_id, QString a_nom, QString a_description)
{
    id = a_id;
    nom = a_nom;
    description = a_description;
}

void Action::setId(const int a_id) {
    id = a_id;
}

void Action::setId(QString *a_idStr) {
    bool ok;
    int a_id = a_idStr->toInt(&ok);
    if (ok) {
        id = a_id;
    }
}

void Action::setNom(QString a_nom) {
    nom = a_nom;
}

void Action::setDescription(QString a_description) {
    description = a_description;
}
