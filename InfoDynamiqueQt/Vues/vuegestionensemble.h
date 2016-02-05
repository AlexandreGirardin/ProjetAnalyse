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

    void setActionsDansEnsemble(QList<Action *> *actions);

    QList<Action*>* getActionsDansEnsemble();

    void setNom(const QString& valeur);

    QString getNom() const;

    void setDescription(const QString& valeur);

    QString getDescription() const;

private slots:

    void horsEnsembleSelectionnee(const QModelIndex &index);

    void dansEnsembleSelectionnee(const QModelIndex &index);

    void ajouter();

    void retirer();

    void peuplerHorsEnsemble();

    void peuplerDansEnsemble();

    void verifierNom();

    void verifierOk();

private:

    Ui::VueGestionEnsemble* ui;

    ChampFormulaire* nom;

    QPushButton* boutonOk;

//    QStandardItemModel *horsEnsemble, *dansEnsemble;

    QList<Action*> *actionsHorsEnsemble, *actionsDansEnsemble;

    int selectionHorsEnsemble, selectionDansEnsemble;

    void configurerBoutonOk();

    QStandardItemModel* listeVersModele(QList<Action*>* liste);

signals:

    void champsRequisModifies(bool);
};

#endif // GESTIONENSEMBLE_H
