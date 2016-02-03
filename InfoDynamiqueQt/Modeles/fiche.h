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
    int id;

    // La priorité de la fiche
    int priorite;

    // Le commentaire facultatif sur la fiche
    QString commentaire;

    // Le statut de la fiche
    Statut* statut;

    // La liste des tâches de la fiche
    QList<Tache*>* taches;

    // La liste des pièces utilisées pour la fiche
    QList<Piece*>* pieces;

    // La liste des techniciens ayant travaillé sur la fiche
    QList<Technicien*>* techniciens;

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
    int getId() const;

    /**
     * @brief setId
     * @param value L'id à assigner à la fiche
     */
    void setId(const int &value);

    /**
     * @brief getPriorite
     * @return La priorité de la fiche
     */
    int getPriorite() const;

    /**
     * @brief setPriorite
     * @param value La priorité à assigner à la fiche
     */
    void setPriorite(const int &value);

    /**
     * @brief getCommentaire
     * @return Le commentaire de la fiche
     */
    QString getCommentaire() const;

    /**
     * @brief setCommentaire
     * @param value Le commentaire à assigner à la fiche
     */
    void setCommentaire(const QString &value);

    /**
     * @brief getStatut
     * @return Le statut de la fiche
     */
    Statut *getStatut() const;

    /**
     * @brief setStatut
     * @param value Le statut à assigner à la fiche
     */
    void setStatut(Statut* value);

    /**
     * @brief getTaches
     * @return La liste des tâches de la fiche
     */
    QList<Tache*>* getTaches() const;

    /**
     * @brief setTaches
     * @param value La liste des tâches à assigner à la fiche
     */
    void setTaches(QList<Tache*>* value);

    /**
     * @brief getPieces
     * @return La liste de pièces de la fiche
     */
    QList<Piece*>* getPieces() const;

    /**
     * @brief setPieces
     * @param value La liste de pièces à assigner à la fiche
     */
    void setPieces(QList<Piece*>* value);

    /**
     * @brief getTechniciens
     * @return La liste des techniciens associés à la fiche
     */
    QList<Technicien*>* getTechniciens() const;

    /**
     * @brief setTechniciens
     * @param value La liste de techniciens à assigner à la fiche
     */
    void setTechniciens(QList<Technicien*>* value);

    /**
     * @brief out
     * @return Représentation textuelle de la fiche
     */
    QString out();

};

#endif // FICHE_H
