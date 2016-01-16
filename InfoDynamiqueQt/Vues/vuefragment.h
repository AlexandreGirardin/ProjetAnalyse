#ifndef FRAGMENT_H
#define FRAGMENT_H

#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QWidget>

namespace Ui {
class VueFragment;
}

class VueFragment : public QWidget
{
    Q_OBJECT

    /**
     * Vue généralisée permettant de sélectionner des objets dans la base de données
     * et de lancer des créations, des visualisations et des mises à jour
     * Permet également d'effectuer des recherches et de filtrer les résultats
     */

private:

    // Interface utilisée pour la vue
    Ui::VueFragment* ui;

    // Id du modèle sélectionné dans le tableau
    // -1 S'il n'y en a aucun
    int idModele;

    // L'index de la colonne des id des modèles dans le tableau
    int colonneId;

public:

    /**
     * @brief VueFragment
     * @param parent
     */
    explicit VueFragment(QWidget* parent = 0);
    ~VueFragment();

    /**
     * @brief getEtiquette
     * @return L'étiquette du fragment
     */
    QLabel* getEtiquette() const;

    /**
     * @brief getBoutonAjouter
     * @return  Le bouton d'ajout de modèle du fragment
     */
    QPushButton* getBoutonAjouter() const;

    /**
     * @brief getBoutonModifier
     * @return Le bouton de modification de modèle du fragment
     */
    QPushButton* getBoutonModifier() const;

    /**
     * @brief getBoutonVoir
     * @return Le bouton de visualisation de modèle du fragment
     */
    QPushButton* getBoutonVoir() const;

    /**
     * @brief ajouterBouton
     * Ajoute un bouton d'action au fragment
     * @param bouton Le bouton à ajouter
     */
    QPushButton *ajouterBouton(int index);

    /**
     * @brief getCaseCocher
     * @return La case à cocher du fragment
     */
    QCheckBox* getCaseCocher() const;

    /**
     * @brief getChamp
     * @return Le champ de recherche du fragment
     */
    QLineEdit* getChamp() const;

    /**
     * @brief getTableau
     * @return Le tableau de modèles du fragment
     */
    QTableView* getTableau() const;

    /**
     * @brief getId
     * @param index L'entrée du tableau duquel on souhaite connaître l'id du modèle
     * @return L'id du modèle
     */
    int getId(QModelIndex index);

    /**
     * @brief getIdModele
     * @return L'id du modèle actuellement sélectionné dans le tableau, ou -1
     */
    int getIdModele() const;

    /**
     * @brief setIdModele
     * @param value L'id de modèle à assigner au fragment
     */
    void setIdModele(int value);

    int getColonneId() const;
    void setColonneId(int value);

public slots:

    /**
     * @brief peuplerTableau
     * @param valeurs Les valeurs à afficher dans le tableau
     * Peuple le tableau avec les valeurs du modèle donné.
     * S'assure que le modèle est triable et réinitialise le tri.
     */
    void peuplerTableau(QAbstractTableModel* valeurs);

    /**
     * @brief activerBoutonsModele
     * Active boutonModifier et boutonVoir
     */
    void activerBoutonsModele();

    /**
     * @brief desactiverBoutonsModele
     * Désactive boutonModifier et boutonVoir
     */
    void desactiverBoutonsModele();

    /**
     * @brief selectionnerModele
     * Assigne l'id correspondant à l'entrée spécifiée à idModele
     * @param index L'entrée du tableau dont l'id doit être assigné à idModele
     * Émet modeleSelectionne();
     */
    void selectionnerModele(QModelIndex index);

    /**
     * @brief relacherModele
     * Oublie et désélectionne le modèle actuellement sélectionné
     * Assigne -1 à idModele
     * Émet modeleRelache();
     */
    void relacherModele();

private slots:

    /**
     * @brief signalerCase
     * Indique un changement d'état de la case de filtre
     * @param etat Le nouvel état de la case à cocher
     */
    void signalerCase(bool etat);

    /**
     * @brief signalerSelection
     * @param nouveau La nouvelle sélection du tableau
     * @param ancien L'ancienne sélection du tableau
     */
    void signalerSelection(QModelIndex nouveau, QModelIndex ancien);

signals:

    /**
     * @brief clicCreer
     * Émis lorsque boutonCreer est appuyé
     */
    void clicCreer();

    /**
     * @brief clicEditer
     * Émis lorsque boutonModifier est appuyé
     */
    void clicEditer();

    /**
     * @brief clicVoir
     * Émis lorsque boutonVoir est appuyé
     */
    void clicVoir();

    /**
     * @brief caseCochee
     * Émis lorsque caseCocher est cochée
     */
    void caseCochee();

    /**
     * @brief caseDecochee
     * Émis lorsque caseCocher est décochée
     */
    void caseDecochee();

    /**
     * @brief rechercher
     * Émis lorsque le champ de recherche est utilisé
     */
    void rechercher(QString);

    /**
     * @brief nouvelleSelection
     * Émis lorsqu'une nouvelle entrée du tableau est sélectionnée
     * @param nouveau La nouvelle sélection
     */
    void nouvelleSelection(QModelIndex nouveau);

    /**
     * @brief modeleSelectionne
     * Émis lorsqu'un nouveau modèle est sélectionné
     * @param idModele L'id du nouveau modèle sélectionné
     */
    void modeleSelectionne(int idModele);

    /**
     * @brief modeleRelache
     * Émis lorsque le modèle actuel est relaché
     */
    void modeleRelache();

    void boutonsActives(bool);

};
#endif // FRAGMENT_H
