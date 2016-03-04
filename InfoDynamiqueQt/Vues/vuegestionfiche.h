#ifndef GESTIONFICHE_H
#define GESTIONFICHE_H

#include <QDialog>

class Action;
class EnsembleActions;
class Tache;
class ChampFormulaire;

#include <QStandardItemModel>

namespace Ui {
class VueGestionFiche;
}

class VueGestionFiche : public QDialog
{
    Q_OBJECT

    // Vue servant à modifier les informations générales d'une fiche

public:

    /**
     * @brief VueGestionFiche
     * Constructeur de la vue
     * @param parent Le widget parent de la vue
     */
    explicit VueGestionFiche(QWidget* parent = 0);

    ~VueGestionFiche();

    /**
     * @brief setDescription
     * @param description Assigne une valeur au champ description
     */
    void setDescription(const QString &description);


    /**
     * @brief getDescription
     * @return La valeur du champ description
     */
    QString getDescription() const;


    /**
     * @brief setPriorite
     * @param priorite Assigne une valeur au champ priorité
     */
    void setPriorite(const int &priorite);


    /**
     * @brief getPriorite
     * @return La valeur du champ priorité
     */
    int getPriorite() const;

    /**
     * @brief setEnsembles
     * @param ensembles Assigne les valeurs au champ ensemble
     */
    void setEnsembles(const QList<EnsembleActions*>* ensembles);


    /**
     * @brief getTaches
     * @return Les valeurs du champ tache
     */
    QList<int>* getTaches() const;

    /**
     * @brief getIdEnsemble
     * @return l'id de l'ensemble
     */
    int getIdEnsemble() const;

private:

    // Interface utilisée pour la vue
    Ui::VueGestionFiche* ui;

    /**
     * @brief listeEnModele
     * Converti la liste d'actions en modèle affichable dans un tableau
     * @param actions
     * @return l'ensemble des élément du tableau
     */
    QStandardItemModel* listeEnModele(const QList<Action*>* actions);

    /**
     * @brief actionEnItem
     * Converti une action en modèle affichable dans un tableau
     * @param action
     * @return Un élément du tableau
     */
    QStandardItem* actionEnItem(const Action* action);

private slots:

    /**
     * @brief peuplerTaches
     * Rempli le tableau avec les actions de l'ensemble actuellement selectionné
     */
    void peuplerTaches();

};

#endif // GESTIONFICHE_H
