#ifndef VUEGESTIONACTION_H
#define VUEGESTIONACTION_H

#include <QDialog>

namespace Ui {
class VueGestionAction;
}

class VueGestionAction : public QDialog
{
    Q_OBJECT

public:

    explicit VueGestionAction(QWidget *parent = 0);

    ~VueGestionAction();

    /**
     * @brief setLectureSeule
     * Rend les champs de la vue non éditables
     * @param value
     */
    void setLectureSeule(const bool value);

    /**
     * @brief getNom
     * @return La valeur actuelle du champ Nom
     */
    QString getNom() const;

    /**
     * @brief setNom
     * Assigne une valeur au nom
     * @param value La valeur à assigner
     */
    void setNom(const QString &value);

    /**
     * @brief getDescription
     * @return La valeur actuelle de la description
     */
    QString getDescription() const;

    /**
     * @brief setDescription
     * Assigne une valeur à la description
     * @param value La valeur à assigner
     */
    void setDescription(const QString &value);

    /**
     * @brief getEtat
     * @return La valeur actuelle de l'état
     */
    bool getEtat() const;

    /**
     * @brief setEtat
     * Assigne une valeur à l'état
     * @param value La valeur à assigner
     */
    void setEtat(const bool &value);

private:
    Ui::VueGestionAction *ui;
};

#endif // VUEGESTIONACTION_H
