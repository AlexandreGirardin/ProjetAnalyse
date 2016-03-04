#ifndef VUEAJOUTERTACHE_H
#define VUEAJOUTERTACHE_H

#include <QDialog>

class Action;
class Statut;

namespace Ui {
class VueAjouterTache;
}

class VueAjouterTache : public QDialog
{
    Q_OBJECT

    //

public:

    /**
     * @brief VueAjouterTache
     * Le constructeur de la vue
     * @param parent
     */
    explicit VueAjouterTache(QWidget *parent = 0);

    ~VueAjouterTache();

    /**
     * @brief setActions
     * Assigne les actions au menu déroulant actions
     * @param actions La liste des actions à assigner
     */
    void setActions(const QList<Action*>* actions);

    /**
     * @brief getAction
     * @return L'id de l'action actuellement sélectionnée
     */
    int getAction() const;

    /**
     * @brief setStatuts
     * Assigne les statuts au menu déroulant statuts
     * @param statuts La liste des statuts à assigner
     */
    void setStatuts(const QList<Statut*>* statuts);

    /**
     * @brief getStatut
     * @return L'id du statuts actuellement sélectionné
     */
    int getStatut() const;

    /**
     * @brief setCommentaire
     * Assigne une valeur au champ commentaire
     * @param commentaire La valeur à assigner
     */
    void setCommentaire(const QString commentaire);

    /**
     * @brief getCommentaire
     * @return La valeur du champ commentaire
     */
    QString getCommentaire() const;

private:

    Ui::VueAjouterTache *ui;

};

#endif // VUEAJOUTERTACHE_H
