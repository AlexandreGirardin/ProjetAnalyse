#ifndef GESTIONPIECE_H
#define GESTIONPIECE_H

#include <QDialog>

class ChampFormulaire;

namespace Ui {
class VueGestionPiece;
}

class VueGestionPiece : public QDialog
{
    Q_OBJECT

    // Vue servant à créer, visualiser et modifier une pièce

public:
    explicit VueGestionPiece(QWidget* parent = 0);
    ~VueGestionPiece();

    /**
     * @brief getNom
     * @return Le nom actuel
     */
    QString getNom() const;

    /**
     * @brief setNom
     * Assigne un nom à la pièce
     * @param nom Le nom à assigner
     */
    void setNom(const QString &valeur);

    /**
     * @brief getDescription
     * @return La description de la pièce
     */
    QString getDescription() const;

    /**
     * @brief setDescription
     * Assigne une description à la pièce
     * @param description La description à assigner
     */
    void setDescription(const QString &description);

    /**
     * @brief getPrix
     * @return Le prix de la pièce, en dollars
     */
    double getPrix() const;

    /**
     * @brief setPrix
     * Assigne un prix à la pièce
     * @param prix Le prix à assigner
     */
    void setPrix(const double &prix);

    /**
     * @brief getPrixInt
     * @return  Le prix de la pièce, en sous
     */
    int getPrixInt() const;
private:
    Ui::VueGestionPiece* ui;

    ChampFormulaire* nom;

private slots:

    /**
     * @brief verifierNom
     * Vérifie si la valeur actuelle du champ Nom est valide
     */
    void verifierNom();

    /**
     * @brief verifierOk
     * Vérifie l'état d'activation du bouton de confirmation
     */
    void verifierOk();

};

#endif // GESTIONPIECE_H
