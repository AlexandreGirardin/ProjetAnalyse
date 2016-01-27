#ifndef FRAGMENTCONNEXION_H
#define FRAGMENTCONNEXION_H

#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QWidget>

namespace Ui {
class VueFragmentConnexion;
}

class VueFragmentConnexion : public QWidget
{
    Q_OBJECT

    /**
     * Vue généralisée permettant de sélectionner des objets dans la base de données
     * et de lancer des créations, des visualisations et des mises à jour
     * Permet également d'effectuer des recherches et de filtrer les résultats
     */

private:

    // Interface utilisée pour la vue
    Ui::VueFragmentConnexion* ui;

    // Id du modèle sélectionné dans le tableau
    // -1 S'il n'y en a aucun
    int idModele;

    // L'index de la colonne des id des modèles dans le tableau
    int colonneId;

    /**
     * @brief configurerBoutonAjouter
     * Connecte le bouton Ajouter
     */
    void configurerBoutonAjouter();

public:

    /**
     * @brief VueFragment
     * @param parent
     */
    explicit VueFragmentConnexion(QWidget* parent = 0);
    ~VueFragmentConnexion();

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
     * @brief ajouterBouton
     * Ajoute un bouton d'action au fragment
     * @param bouton Le bouton à ajouter
     */
    QPushButton *ajouterBouton(int index);

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
     * @brief getColonneId
     * @return Le numéro de la colonne du tableau contenant les id des modèles
     */
    int getColonneId() const;

    /**
     * @brief setColonneId
     * Assigne le numéro de la colonne du tableau contenant les id des modèles
     * @param value Le numéro à assigner
     */
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
     * @brief signalerSelection
     * @param nouveau La nouvelle sélection du tableau
     * @param ancien L'ancienne sélection du tableau
     */
    void signalerSelection(QModelIndex nouveau, QModelIndex ancien);

signals:

    /**
     * @brief clicConnecter
     * Émis lorsque boutonConnexion est appuyé
     */
    void clicConnexion();

    /**
     * @brief nouvelleSelection
     * Émis lorsqu'une nouvelle entrée du tableau est sélectionnée
     * @param nouveau La nouvelle sélection
     */
    void nouvelleSelection(QModelIndex nouveau);

    /**
     * @brief boutonsActives
     * Indique un changement de l'état des boutons (activés ou désactivés)
     */
    void boutonsActives(bool);

};
#endif // VUEFRAGMENTCONNEXION_H
