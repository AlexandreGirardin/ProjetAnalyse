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

    // L'action à accomplir
    Action* m_action;

    // Le statut de la tâche
    Statut* m_statut;

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
     * @brief out
     * @return Représentation textuelle de la tâche
     */
    QString out() const;

};

#endif // TACHE_H
