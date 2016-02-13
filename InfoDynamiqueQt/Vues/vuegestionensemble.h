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

    /**
     * @brief setActions
     * Assigne les actions à la vue
     * @param horsEnsemble Les actions ne faisant pas partie de l'ensemble initialement
     * @param dansEnsemble Les actions faisant partie de l'ensemble initialement
     */
    void setActions(const QList<Action*>* horsEnsemble, const QList<Action*>* dansEnsemble = 0);

    /**
     * @brief setNom
     * Assigne un nom
     * @param valeur Le nom à afficher
     */
    void setNom(const QString &valeur);

    /**
     * @brief getNom
     * @return Le nom actuellement affiché
     */
    QString getNom() const;

    /**
     * @brief setDescription
     * Assigne une description
     * @param valeur La description à afficher
     */
    void setDescription(const QString &valeur);

    /**
     * @brief getDescription
     * @return La description actuellement affichée
     */
    QString getDescription() const;

    /**
     * @brief getActionsSelectionnees
     * @return Les actions actuellement sélectionnées pour être assignées à l'ensemble
     */
    QList<int>* getActionsSelectionnees() const;

private slots:

    /**
     * @brief horsEnsembleSelectionnee
     * Active le bouton d'ajout d'action
     */
    void horsEnsembleSelectionnee();

    /**
     * @brief dansEnsembleSelectionnee
     * Active le bouton de retrait d'action
     */
    void dansEnsembleSelectionnee();

    /**
     * @brief ajouter
     * Ajoute à l'ensemble l'action actuellement sélectionnée
     */
    void ajouter();

    /**
     * @brief ajouter
     * Retire de l'ensemble l'action actuellement sélectionnée
     */
    void retirer();

    /**
     * @brief verifierNom
     * Vérifie la validité du champ Nom
     * Émet champsRequisModifies() si la validité a changé
     */
    void verifierNom();

    /**
     * @brief verifierOk
     * Active ou désactive le bouton de validation selon la validité des champs requis
     */
    void verifierOk();

    /**
     * @brief creerAction
     * Lance la procédure de création d'une nouvelle action
     * Ajoute la nouvelle action à l'ensemble
     */
    void creerAction();

private:

    Ui::VueGestionEnsemble* ui;

    /**
     * @brief nom
     * Le champ contrôlant l'entrée du nom de l'ensemble
     */
    ChampFormulaire* nom;

    /**
     * @brief boutonOk
     * Le bouton de validation, activé uniquement si les champs requis sont valides
     */
    QPushButton* boutonOk;

    /**
     * @brief modeleDansEnsemble
     * Le modèle servant à présenter la liste des actions ne faisant pas partie de l'ensemble
     */
    QStandardItemModel* modeleHorsEnsemble;

    /**
     * @brief modeleDansEnsemble
     * Le modèle servant à présenter la liste des actions faisant partie de l'ensemble
     */
    QStandardItemModel* modeleDansEnsemble;

    /**
     * @brief configurerBoutonOk
     * Configure le bouton de validation de la vue
     */
    void configurerBoutonOk();

    /**
     * @brief listeEnModele
     * Crée un modèle affichable à partir d'une liste d'action
     * @param actions Les actions à inclure dans le modèle
     * @return Le modèle
     */
    QStandardItemModel* listeEnModele(const QList<Action*>* actions);

    /**
     * @brief actionEnItem
     * Crée un élément affichable à partir d'une action
     * @param action L'action source
     * @return L'élément
     */
    QStandardItem* actionEnItem(const Action* action);

signals:

    /**
     * @brief champsRequisModifies
     * Émis lorsque la validité d'un champ requis vient de changer
     */
    void champsRequisModifies(bool);
};

#endif // GESTIONENSEMBLE_H
