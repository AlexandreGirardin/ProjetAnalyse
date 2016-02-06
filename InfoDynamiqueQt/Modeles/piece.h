#ifndef PIECE_H
#define PIECE_H

#include "Modeles/modelebd.h"

class Piece : public ModeleBD
{
    Q_OBJECT

    // Pièce utilisée pour réaliser les tâches d'une fiche de maintenance

private:

    // Le nom de la pièce
    QString m_nom;

    // La description de la pièce
    QString m_description;

    // Le prix de la pièce, en sous
    int m_prix;

public:

    /**
     * @brief Piece
     * @param parent
     */
    explicit Piece(QObject* parent = 0);

    /**
     * @brief Piece
     * @param a_id L'id à donner à la pièce
     * @param a_nom Le nom à donner à la pièce
     * @param a_description La description à donner à la pièce
     * @param a_prix Le prix à donner à la pièce
     * @param parent
     */
//    Piece(const int &a_id, const QString &a_nom, const QString &a_description, const int &a_prix, QObject* parent = 0);

    /**
     * @brief getNom
     * @return Le nom de la pièce
     */
    QString nom() const;

    /**
     * @brief setNom
     * @param value Le nom à assigner à la pièce
     */
    void setNom(const QString &value);

    /**
     * @brief getDescription
     * @return La description de la pièce
     */
    QString description() const;

    /**
     * @brief setDescription
     * @param value La description à assigner à la pièce
     */
    void setDescription(const QString &value);

    /**
     * @brief getPrixInt
     * @return Le prix de la pièce, en sous
     */
    int prixInt() const;

    /**
     * @brief getPrixDouble
     * @return Le prix de la pièce, en dollars et sous
     */
    double prixDouble() const;

    /**
     * @brief setPrix
     * @param value Le prix à assigner à la pièce, en sous
     */
    void setPrix(const int &value);

    /**
     * @brief out
     * @return La chaîne imprimable correspondant à la pièce
     */
    QString out() const;

};

#endif // PIECE_H
