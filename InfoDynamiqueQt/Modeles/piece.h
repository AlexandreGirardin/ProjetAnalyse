#ifndef PIECE_H
#define PIECE_H

#include "Modeles/modelebd.h"

class Piece : public ModeleBD
{
    Q_OBJECT

    // Pièce utilisée pour réaliser les tâches d'une fiche de maintenance

private:

    // L'identifiant unique de la pièce
    int id;

    // Le nom de la pièce
    QString nom;

    // La description de la pièce
    QString description;

    // Le prix de la pièce, en sous
    int prix;

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
    Piece(int a_id, QString a_nom, QString a_description, int a_prix, QObject* parent = 0);

    /**
     * @brief getId
     * @return L'id de la pièce
     */
    int getId() const;

    /**
     * @brief setId
     * @param value L'id à assigner à la pièce
     */
    void setId(const int &value);

    /**
     * @brief getNom
     * @return Le nom de la pièce
     */
    QString getNom() const;

    /**
     * @brief setNom
     * @param value Le nom à assigner à la pièce
     */
    void setNom(const QString &value);

    /**
     * @brief getDescription
     * @return La description de la pièce
     */
    QString getDescription() const;

    /**
     * @brief setDescription
     * @param value La description à assigner à la pièce
     */
    void setDescription(const QString &value);

    /**
     * @brief getPrixInt
     * @return Le prix de la pièce, en sous
     */
    int getPrixInt() const;

    /**
     * @brief getPrixDouble
     * @return Le prix de la pièce, en dollars et sous
     */
    double getPrixDouble() const;

    /**
     * @brief setPrix
     * @param value Le prix à assigner à la pièce, en sous
     */
    void setPrix(const int &value);

    /**
     * @brief out
     * @return La chaîne imprimable correspondant à la pièce
     */
    QString out();

};

#endif // PIECE_H
