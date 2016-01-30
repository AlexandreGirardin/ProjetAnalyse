#ifndef GESTIONENSEMBLE_H
#define GESTIONENSEMBLE_H

#include "Modeles/ensembleactions.h"

#include <QDialog>

namespace Ui {
class VueGestionEnsemble;
}

class VueGestionEnsemble : public QDialog
{
    Q_OBJECT

    // Vue servant à créer, visualiser et modifier un ensemble de tâches

public:
    explicit VueGestionEnsemble(QWidget* parent = 0);
    ~VueGestionEnsemble();

    void setActionsExistantes(const QList<Action*>* actions);

private:
    Ui::VueGestionEnsemble* ui;
};

#endif // GESTIONENSEMBLE_H
