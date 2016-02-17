#ifndef TACHE_H
#define TACHE_H

#include "Modeles/modelebd.h"

#include "Modeles/action.h"
#include "Modeles/statut.h"

class Tache : public ModeleBD
{
    Q_OBJECT

    // Exécution d'une action sur un appareil dans le cadre d'une fiche de maintenance

private:

    // La fiche à laquelle appartient la tâche
    int m_idFiche;

    // L'action à accomplir
    Action* m_action;

    // Le statut de la tâche
    Statut* m_statut;

    // Commentaire facultatif sur l'état d'avancement de la tâche
    QString m_commentaire;

public:

    /**
     * @brief Tache
     * @param parent
     */
    explicit Tache(QObject* parent = 0);

    /**
     * @brief getAction
     * @return L'action à accomplir
     */
    Action* action() const;

    /**
     * @brief setAction
     * @param value L'action à assigner à la tâche
     */
    void setAction(Action* value);

    /**
     * @brief getStatut
     * @return Le statut de la tâche
     */
    Statut* statut() const;

    /**
     * @brief setStatut
     * @param value Le statut à assigner à la tâche
     */
    void setStatut(Statut* value);

    /**
     * @brief idFiche
     * @return L'id de la fiche à laquelle la tâche est associée
     */
    int idFiche() const;

    /**
     * @brief setIdFiche
     * Assigne l'id de la fiche à laquelle la tâche est associée
     * @param idFiche L'id de la tâche à assigner
     */
    void setIdFiche(const int &idFiche);

    /**
     * @brief getCommentaire
     * @return Le commentaire de la tâche
     */
    QString commentaire() const;

    /**
     * @brief setCommentaire
     * Assigne un commentaire à la tâche
     * @param value Le commentaire à assigner
     */
    void setCommentaire(const QString &value);

    /**
     * @brief out
     * @return Représentation textuelle de la tâche
     */
    QString out() const;
};

#endif // TACHE_H
