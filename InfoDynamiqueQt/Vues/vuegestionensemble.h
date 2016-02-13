#ifndef GESTIONENSEMBLE_H
#define GESTIONENSEMBLE_H

#include <QDialog>

#include "Modeles/ensembleactions.h"
#include "Vues/champformulaire.h"

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

    void setActions(const QList<Action*>* horsEnsemble, const QList<Action*>* dansEnsemble = 0);

    void setNom(const QString &valeur);

    QString getNom() const;

    void setDescription(const QString &valeur);

    QString getDescription() const;

    QList<int>* getActionsSelectionnees() const;

private slots:

    void horsEnsembleSelectionnee();

    void dansEnsembleSelectionnee();

    void ajouter();

    void retirer();

    void verifierNom();

    void verifierOk();

private:

    Ui::VueGestionEnsemble* ui;

    ChampFormulaire* nom;

    QPushButton* boutonOk;

    QStandardItemModel* modeleDansEnsemble;

    QStandardItemModel* modeleHorsEnsemble;

    void configurerBoutonOk();

    QStandardItemModel* listeEnModele(const QList<Action*>* actions);

signals:

    void champsRequisModifies(bool);
};

#endif // GESTIONENSEMBLE_H
