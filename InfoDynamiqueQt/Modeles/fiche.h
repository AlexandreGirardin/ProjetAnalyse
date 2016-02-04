#ifndef FICHE_H
#define FICHE_H

#include "Modeles/modelebd.h"

#include "Modeles/piece.h"
#include "Modeles/statut.h"
#include "Modeles/tache.h"
#include "Modeles/technicien.h"

class Fiche : public ModeleBD
{
    Q_OBJECT

    // Fiche de maintenance d'un appareil

private:

    // L'id de la fiche
    int m_id;

    // La priorité de la fiche
    int m_priorite;

    // Le commentaire facultatif sur la fiche
    QString m_commentaire;

    // Le statut de la fiche
    Statut* m_statut;

    // La liste des tâches de la fiche
    QList<Tache*>* m_taches;

    // La liste des pièces utilisées pour la fiche
    QList<Piece*>* m_pieces;

    // La liste des techniciens ayant travaillé sur la fiche
    QList<Technicien*>* m_techniciens;

public:

    /**
     * @brief Fiche
     * @param parent
     */
    explicit Fiche(QObject* parent = 0);

    /**
     * @brief getId
     * @return L'id de la fiche
     */
    int id() const;

    /**
     * @brief setId
     * @param value L'id à assigner à la fiche
     */
    void setId(const int &value);

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
     * @brief getTechniciens
     * @return La liste des techniciens associés à la fiche
     */
    QList<Technicien*>* techniciens() const;

    /**
     * @brief setTechniciens
     * @param value La liste de techniciens à assigner à la fiche
     */
    void setTechniciens(QList<Technicien*>* value);

    /**
     * @brief out
     * @return Représentation textuelle de la fiche
     */
    QString out() const;

};

#endif // FICHE_H
