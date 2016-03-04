#ifndef EDITIONFICHE_H
#define EDITIONFICHE_H

#include <QDialog>

class Action;
class Piece;
class Statut;
class Tache;

class QDoubleSpinBox;
class QComboBox;
class QTableWidgetItem;

namespace Ui {
class VueEditionFiche;
}

class VueEditionFiche : public QDialog
{
    Q_OBJECT

    // Vue permettant d'éditer en détails une fiche déjà créée

public:

    explicit VueEditionFiche(QWidget* parent = 0);
    ~VueEditionFiche();

    /**
     * @brief setIdFiche
     * Assigne l'id de la fiche
     * @param id L'id à assigner
     */
    void setIdFiche(const int &id);

    /**
     * @brief idFiche
     * @return L'id de la fiche
     */
    int idFiche() const;

    /**
     * @brief setCommentaire
     * Assigne un commentaire au champ commentaire
     * @param commentaire Le commentaire à assigner
     */
    void setCommentaire(const QString &commentaire);

    /**
     * @brief commentaire
     * @return La valeur du champ commentaire
     */
    QString commentaire() const;

    /**
     * @brief setDescription
     * Assigne une description au champ description
     * @param description La description à assigner
     */
    void setDescription(const QString &description);

    /**
     * @brief description
     * @return La valeur du champ description
     */
    QString description() const;

    /**
     * @brief setClient
     * Assigne les informations du client dans la fiche
     * @param id L'id du client à assigner
     * @param nom Le nom du client à assigner au champ texte client
     * @param telephone Le numéro de téléphone à assigner au champ texte client
     */
    void setClient(const int &id, const QString &nom, const QString &telephone);

    /**
     * @brief setAppareil
     * Assigne les informations de l'appareil dans la fiche
     * @param id L'id de l'appareil à assigner
     * @param description La description à assigner au champ texte appareil
     */
    void setAppareil(const int &id, const QString &description);

    /**
     * @brief setTaches
     * Assigne les tâches au tableau tâches
     * @param taches La liste des tâches à assigner
     */
    void setTaches(const QList<Tache*>* taches);

    /**
     * @brief getTaches
     * @return La liste des tâches de la fiche
     */
    QList<Tache*>* getTaches() const;

    /**
     * @brief getIdActions
     * @return La liste des ids des actions
     */
    QList<int>* getIdActions() const;

    /**
     * @brief setPieces
     * Assigne les pièces au tableau pièces
     * @param pieces La liste des pièces à assigner
     */
    void setPieces(const QList<Piece*>* pieces);

    /**
     * @brief getPieces
     * @return La liste des pièces de la fiche
     */
    QList<Piece*>* getPieces() const;

    /**
     * @brief getStatutFiche
     * @return Le statut de la fiche
     */
    Statut* getStatutFiche() const;

    /**
     * @brief setStatutsFiche
     * Peuple le combobox statut et assigne le statut actuel
     * @param statuts La liste de tout les statuts
     * @param statutFiche Le statut actuel de la fiche
     */
    void setStatutsFiche(const QList<Statut *> *statuts, const Statut *statutFiche);

    /**
     * @brief setPriorite
     * Assigne la priorité de la fiche au champ priorité
     * @param priorite La priorité de la fiche
     */
    void setPriorite(const int &priorite);

    /**
     * @brief getPriorite
     * @return La valeur du champ priorité
     */
    int getPriorite() const;

private:

    Ui::VueEditionFiche* ui;

    int m_idFiche;

    int m_idClient;

    int m_idAppareil;

    /**
     * @brief configurerTableauTaches
     * Configure le tableau des tâches
     */
    void configurerTableauTaches();

    /**
     * @brief configurerTableauPieces
     * Configure le tableau des pièces
     */
    void configurerTableauPieces();

    /**
     * @brief comboStatutTache
     * Rempli le menu déroulant avec tous les statuts et assigne le status actuel de la tâche
     * @param tache La tâche contenant le statut actuel
     * @param statuts La liste de tous les statuts
     * @return Le menu déroulant rempli avec les statuts
     */
    QComboBox* comboStatutTache(const Tache* tache, const QList<Statut*>* statuts) const;

    /**
     * @brief actionVersItem
     * Converti les actions en élément affichable dans un tableau
     * @param action L'action à convertir
     * @return L'élément affichable dans un tableau
     */
    QTableWidgetItem* actionVersItem(const Action* action) const;

    /**
     * @brief prixVersItem
     * Converti les prix en élément affichable dans un tableau
     * @param prix
     * @return Le champ de sélection nummérique affichable dans un tableau
     */
    QDoubleSpinBox* prixVersItem(const double &prix);

    /**
     * @brief itemVersAction
     * Converti les élément du tableau en onjet Action
     * @param rangee Le numéro de la rangée actuelle
     * @return L'action
     */
    Action* itemVersAction(const int &rangee) const;

    /**
     * @brief itemVersStatut
     * Converti les éléments du tableau en objet Statut
     * @param rangee Le numéro de la rangée actuelle
     * @return Le statut
     */
    Statut* itemVersStatut(const int &rangee) const;

    /**
     * @brief itemVersCommentaire
     * Converti les élement du tableau en Qstring
     * @param rangee Le numéro de la rangée actuelle
     * @return Le commentaire
     */
    QString itemVersCommentaire(const int &rangee) const;

    /**
     * @brief itemVersPrix
     * Converti les élément du tableau en prix
     * @param rangee Le numéro de la rangée actuelle
     * @return Le prix
     */
    double itemVersPrix(const int &rangee) const;

    /**
     * @brief setTache
     * Assigne une tâches au tableau des tâches
     * @param tache La tâche à assigner
     * @param rangee Le numéro de la rangée actuelle
     * @param statuts Le status de la tâche
     */
    void setTache(const Tache* tache, const int &rangee, const QList<Statut*>* statuts);

    /**
     * @brief setPiece
     * Assigne une pièce au tableau des pièces
     * @param piece La pièce à assigner
     * @param rangee Le numéro de la rangée actuelle
     */
    void setPiece(const Piece* piece, const int &rangee);

private slots:

    /**
     * @brief detailsClient
     * Permet de visualiser les informations du client
     */
    void detailsClient();

    /**
     * @brief detailsAppareil
     * Permet de visualiser les informations de l'appareil
     */
    void detailsAppareil();

    /**
     * @brief ajouterTache
     * Permet d'ajouter une tâche
     */
    void ajouterTache();

    /**
     * @brief retirerTache
     * Permet de retirer une tâche
     */
    void retirerTache();

    /**
     * @brief ajouterPiece
     * Permet d'ajouter une pièce
     */
    void ajouterPiece();

    /**
     * @brief retirerPiece
     * Permet de retirer une pièce
     */
    void retirerPiece();

    /**
     * @brief tacheSelectionnee
     * Active le bouton retirer tâche
     */
    void tacheSelectionnee();

    /**
     * @brief pieceSelectionnee
     * Active le bouton retirer pièce
     */
    void pieceSelectionnee();

signals:

    /**
     * @brief voirClient
     * Signal emit lorsque le bouton détail client et cliqué
     * @param idClient
     */
    void voirClient(const int &idClient);

    /**
     * @brief voirAppareil
     * Signal emit lorsque le bouton détail appareil et cliqué
     * @param idFiche
     */
    void voirAppareil(const int &idFiche);

};

#endif // EDITIONFICHE_H
