#ifndef VUEENSEMBLE_H
#define VUEENSEMBLE_H

#include <QDialog>

class Action;

class QStandardItemModel;

namespace Ui {
class VueEnsemble;
}

class VueEnsemble : public QDialog
{
    Q_OBJECT
    
    // Vue servant à créer, visualiser et modifier un ensemble

public:
    /**
     * @brief VueEnsemble
     * Constructeur de la vue
     * @param parent Le widget parent de la vue
     */
    explicit VueEnsemble(QWidget *parent = 0);
    
    ~VueEnsemble();

    /**
     * @brief setNom
     * Assigne le nom de l'ensemble
     * @param nom Le nom à assigner
     */
    void setNom(const QString &nom);

    /**
     * @brief setDescription
     * Assigne la description de l'ensemble
     * @param description La description à assigner
     */
    void setDescription(const QString &description);

    /**
     * @brief setActions
     * Assigne les actions à l'ensemble
     * @param actions La liste d'actions à assigner
     */
    void setActions(const QList<Action*>* actions);

private:

    // Interface utilisée pour la vue
    Ui::VueEnsemble *ui;

    /**
     * @brief listeVersModele
     * @param liste La liste d'actions à convertir en modèle affichable dans un tableau
     * @return Le modèle affichable dans un tableau
     */
    QStandardItemModel *listeVersModele(const QList<Action*>* liste);
};

#endif // VUEENSEMBLE_H
