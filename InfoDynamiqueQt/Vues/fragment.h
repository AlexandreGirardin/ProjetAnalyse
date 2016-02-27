#ifndef FRAGMENT_H
#define FRAGMENT_H

#include <QWidget>

#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>

namespace Ui {
class VueFragment;
}

class Fragment : public QWidget
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
    int m_idModele;

    // L'index de la colonne des id des modèles dans le tableau
    int m_colonneId;

    /**
     * @brief configurerBoutonAjouter
     * Connecte le bouton Ajouter
     */
    void configurerBoutonAjouter();

    /**
     * @brief configurerBoutonModifier
     * Connecte le bouton Modifier
     */
    void configurerBoutonModifier();

    /**
     * @brief configurerBoutonVoir
     * Connecte le bouton Voir
     */
    void configurerBoutonVoir();

    /**
     * @brief configurerCase
     * Connecte la case à cocher
     */
    void configurerCase();

    /**
     * @brief configurerChamp
     * Connecte le champ de recherche
     */
    void configurerChamp();

    /**
     * @brief getId
     * @param index L'entrée du tableau duquel on souhaite connaître l'id du modèle
     * @return L'id du modèle
     */
    int getId(const QModelIndex &index);

public:

    /**
     * @brief VueFragment
     * @param parent
     */
    explicit Fragment(QWidget* parent = 0);

    ~Fragment();

    /**
     * @brief retirerEtiquette
     * Retire l'étiquette de fragment
     */
    void retirerEtiquette() const;

    /**
     * @brief setEtiquette
     * Assigne un texte à l'étiquette de fragment
     * @param etiquette Le texte à placer dans l'étiquette
     */
    void setEtiquette(const QString &etiquette) const;

    /**
     * @brief boutonAjouter
     * @return  Le bouton d'ajout de modèle du fragment
     */
    QPushButton* boutonAjouter() const;

    /**
     * @brief boutonModifier
     * @return Le bouton de modification de modèle du fragment
     */
    QPushButton* boutonModifier() const;

    /**
     * @brief boutonVoir
     * @return Le bouton de visualisation de modèle du fragment
     */
    QPushButton* boutonVoir() const;

    /**
     * @brief ajouterBouton
     * Ajoute un bouton au fragment et le connecte
     * Le bouton sera actif en fonction de la validité de la sélection actuelle dans le tableau
     * @param index La position souhaitée
     * @param texte Le texte du bouton
     * @param icone L'icône du bouton
     * @return Le bouton connecté
     */
    QPushButton* ajouterBouton(const int &index, const QString &texte = 0, const QIcon &icone = QIcon());

    /**
     * @brief ajouterBoutonNonConnecte
     * Ajoute un bouton au fragment
     * @param index La position souhaitée
     * @param texte Le texte du bouton
     * @param icone L'icône du bouton
     * @return Le bouton
     */
    QPushButton* ajouterBoutonNonConnecte(const int &index, const QString &texte = 0, const QIcon icone = QIcon());

    /**
     * @brief caseCocher
     * @return La case à cocher du fragment
     */
    QPushButton* caseCocher() const;

    /**
     * @brief champ
     * @return Le champ de texte servant à la recherche
     */
    QLineEdit* champ() const;

    /**
     * @brief retirerCaseCocher
     * Retire la case à cocher de la vue
     */
    void retirerCaseCocher() const;

    /**
     * @brief retirerChamp
     * Retire le champ de recherche de la vue
     */
    void retirerChamp() const;

    /**
     * @brief getFiltre
     * @return Le filtre de recherche actuel
     */
    QString filtre() const;

    /**
     * @brief getTableau
     * @return Le tableau de modèles du fragment
     */
    QTableView* tableau() const;

    /**
     * @brief rangeeSelection
     * @return La rangée du tableau actuellement sélectionnée
     */
    int rangeeSelectionnee() const;

    /**
     * @brief selectionnerRangee
     * Sélectionne une rangée dans le tableau
     * @param rangee La rangée à sélectionner
     */
    void selectionnerRangee(const int &rangee) const;

    /**
     * @brief getIdModele
     * @return L'id du modèle actuellement sélectionné dans le tableau, ou -1
     */
    int idModele() const;

    /**
     * @brief setIdModele
     * @param value L'id de modèle à assigner au fragment
     */
    void setIdModele(const int &value);

    /**
     * @brief colonneId
     * @return Le numéro de la colonne du tableau contenant les id des modèles
     */
    int colonneId() const;

    /**
     * @brief setColonneId
     * Assigne le numéro de la colonne du tableau contenant les id des modèles
     * @param value Le numéro à assigner
     */
    void setColonneId(const int &value);

    /**
     * @brief cacherColonneId
     * Cache la colonne comprenant les id des modèles
     * L'index de la colonne est contenu dans colonneId()
     */
    void cacherColonneId() const;

    /**
     * @brief selectionnerModeleParId
     * Sélectionne la rangée qui contient un id donné
     * @param id L'id à trouver dans le tableau
     */
    void selectionnerModeleParId(const int &id);

public slots:

    /**
     * @brief peuplerTableau
     * @param valeurs Les valeurs à afficher dans le tableau
     * Peuple le tableau avec les valeurs du modèle donné.
     * S'assure que le modèle est triable et réinitialise le tri.
     */
    void peuplerTableau(QAbstractTableModel* valeurs);

    /**
     * @brief relacherModele
     * Oublie et désélectionne le modèle actuellement sélectionné
     * Assigne -1 à idModele
     * Émet modeleRelache();
     */
    void relacherModele();

private slots:

    /**
     * @brief selectionnerModele
     * Assigne l'id correspondant à l'entrée spécifiée à idModele
     * @param index L'entrée du tableau dont l'id doit être assigné à idModele
     * Émet modeleSelectionne();
     */
    void selectionnerModele(const QModelIndex &index);

    /**
     * @brief signalerCase
     * Indique un changement d'état de la case de filtre
     * @param etat Le nouvel état de la case à cocher
     */
    void basculerCase(const bool &etat);

    /**
     * @brief signalerSelection
     * @param nouveau La nouvelle sélection du tableau
     * @param ancien L'ancienne sélection du tableau
     */
    void signalerSelection(const QModelIndex &nouveau, const QModelIndex &ancien);

signals:

    /**
     * @brief selectionValide
     * Informe d'un changement de modèle sélectionné
     */
    void selectionValide(const bool valide);

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
    void rechercher(const QString filtre);

    /**
     * @brief nouvelleSelection
     * Émis lorsqu'une nouvelle entrée du tableau est sélectionnée
     * @param nouveau La nouvelle sélection
     */
    void nouvelleSelection(const QModelIndex nouveau);

    /**
     * @brief modeleSelectionne
     * Émis lorsqu'un nouveau modèle est sélectionné
     * @param idModele L'id du nouveau modèle sélectionné
     */
    void modeleSelectionne(const int m_idModele);

    /**
     * @brief modeleRelache
     * Émis lorsque le modèle actuel est relaché
     */
    void modeleRelache();

    /**
     * @brief boutonsActives
     * Indique un changement de l'état des boutons (activés ou désactivés)
     */
    void boutonsActives(const bool etat);

    /**
     * @brief doubleClicModele
     * Émis lors d'un double clic sur un modèle du tableau
     * Le premier clic sélectionne le modèle, donc idModele retourne déjà une valeur valide
     */
    void doubleClicModele();

};
#endif // FRAGMENT_H
