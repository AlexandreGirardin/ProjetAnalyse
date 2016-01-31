#ifndef GESTIONENSEMBLE_H
#define GESTIONENSEMBLE_H

#include "Modeles/ensembleactions.h"
#include "Vues/champformulaire.h"

#include <QDialog>
#include <QStandardItemModel>

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

    void setActionsHorsEnsemble(QList<Action*>* actions);

    QList<Action*>* getActionsHorsEnsemble();

    void setActionsDansEnsemble(QList<Action*>* actions);

    QList<Action*>* getActionsDansEnsemble();

private slots:

    void horsEnsembleSelectionnee(const QModelIndex &index);

    void dansEnsembleSelectionnee(const QModelIndex &index);

    void ajouter();

    void retirer();

    void peuplerHorsEnsemble();

    void peuplerDansEnsemble();

    void verifierNom();

private:
    Ui::VueGestionEnsemble* ui;

    ChampFormulaire* nom;

    QStandardItemModel *horsEnsemble, *dansEnsemble;

    QList<Action*> *actionsHorsEnsemble, *actionsDansEnsemble;

    int selectionHorsEnsemble, selectionDansEnsemble;

};

#endif // GESTIONENSEMBLE_H
