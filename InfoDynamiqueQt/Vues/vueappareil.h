#ifndef VUEAPPAREIL_H
#define VUEAPPAREIL_H

#include <QDialog>

class QLineEdit;
class QTextEdit;

namespace Ui {
class VueAppareil;
}

class VueAppareil : public QDialog
{
    Q_OBJECT

    // Vue permettant de voir les informations d'un appareil

public:

    /**
     * @brief VueAppareil
     * Le constructeur de la vue
     * @param parent Le widget parent de la vue
     */
    explicit VueAppareil(QWidget *parent = 0);
    
    ~VueAppareil();

    /**
     * @brief getType
     * Retourne la valeur du champ type
     * @return Le type de l'appareil
     */
    QString getType() const;

    /**
     * @brief getFabricant
     * Retourne la valeur du champ fabricant
     * @return Le fabricant de l'appareil
     */
    QString getFabricant() const;

    /**
     * @brief getMotDePasse
     * Retourne la valeur du champ appareil
     * @return Le mot de passe de l'appareil
     */
    QString getMotDePasse() const;

    /**
     * @brief getDescription
     * Retourne la valeur du champ description
     * @return La ddescrition de l'appareil
     */
    QString getDescription() const;

    /**
     * @brief setType
     * Assigne une valeur au champ type
     * @param value La valeur à assigner
     */
    void setType(const QString &value);

    /**
     * @brief setFabricant
     * Assigne une valeur au champ fabricant
     * @param value La valeur à assigner
     */
    void setFabricant(const QString &value);

    /**
     * @brief setMotDePasse
     * Assigne une valeur au champ mot de passe
     * @param value La valeur à assigner
     */
    void setMotDePasse(const QString &value);

    /**
     * @brief setDescription
     * Assigne une valeur au champ description
     * @param valueLa valeur à assigner
     */
    void setDescription(const QString &value);

private:

    // Interface utilisée pour la vue
    Ui::VueAppareil *ui;

};

#endif // VUEAPPAREIL_H
