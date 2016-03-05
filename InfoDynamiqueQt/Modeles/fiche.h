#ifndef FICHE_H
#define FICHE_H

#include "Modeles/modelebd.h"

class Piece;
class Statut;
class Tache;

class Fiche : public ModeleBD
{

    // Fiche de maintenance d'un appareil

private:

    // L'id de l'appareil
    int m_idAppareil;

    // La priorité de la fiche
    int m_priorite;

    // Le commentaire facultatif sur la fiche
    QString m_commentaire;

    // La description de l'avancement de la fiche
    QString m_description;

    // Le statut de la fiche
    Statut* m_statut;

    // La liste des tâches de la fiche
    QList<Tache*>* m_taches;

    // La liste des pièces utilisées pour la fiche
    QList<Piece*>* m_pieces;

public:

    /**
     * @brief Fiche
     * Le constructeur de l'objet
     * @param parent L'objet parent
     */
    explicit Fiche(QObject* parent = 0);

    /**
     * @brief getPriorite
     * @return La priorité de la fiche
     */
    int priorite() const;

    /**
     * @brief setPriorite
     * @param value La priorité à assigner à la fiche
     */
    void setPriorite(const int &value);

    /**
     * @brief getCommentaire
     * @return Le commentaire de la fiche
     */
    QString commentaire() const;

    /**
     * @brief setCommentaire
     * @param value Le commentaire à assigner à la fiche
     */
    void setCommentaire(const QString &value);

    /**
     * @brief description
     * @return La description de la fiche
     */
    QString description() const;

    /**
     * @brief setDescription
     * Assigne la description de la fiche
     * @param description La description à assigner
     */
    void setDescription(const QString &description);

    /**
     * @brief getStatut
     * @return Le statut de la fiche
     */
    Statut* statut() const;

    /**
     * @brief setStatut
     * @param value Le statut à assigner à la fiche
     */
    void setStatut(Statut* value);

    /**
     * @brief getTaches
     * @return La liste des tâches de la fiche
     */
    QList<Tache*>* taches() const;

    /**
     * @brief setTaches
     * @param value La liste des tâches à assigner à la fiche
     */
    void setTaches(QList<Tache*>* value);

    /**
     * @brief getPieces
     * @return La liste de pièces de la fiche
     */
    QList<Piece*>* pieces() const;

    /**
     * @brief setPieces
     * @param value La liste de pièces à assigner à la fiche
     */
    void setPieces(QList<Piece*>* value);

    /**
     * @brief idAppareil
     * @return L'id de l'appareil
     */
    int idAppareil() const;

    /**
     * @brief setIdAppareil
     * Assigne l'id de l'appareil auquel est associée la fiche
     * @param idAppareil L'id à assigner
     */
    void setIdAppareil(int idAppareil);

    /**
     * @brief out
     * @return Représentation textuelle de la fiche
     */
    QString out() const;
};

#endif // FICHE_H
