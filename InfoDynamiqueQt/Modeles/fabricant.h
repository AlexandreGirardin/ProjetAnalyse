#ifndef FABRICANT_H
#define FABRICANT_H

#include "Modeles/modelebd.h"

class Fabricant : public ModeleBD {
    Q_OBJECT

    // Marque du constructeur d'un appareil permettant de l'identifier

private:

    // L'id du fabricant
    int id;

    // Le nom du fabricant
    QString nom;

public:

    /**
     * @brief Fabricant
     * @param parent
     */
    explicit Fabricant(QObject* parent = 0);

    /**
     * @brief Fabricant
     * @param a_id L'id à assigner au fabricant
     * @param a_nom Le nom à assigner au fabricant
     * @param parent
     */
    explicit Fabricant(const int &a_id, const QString &a_nom, QObject* parent = 0);

    /**
     * @brief getId
     * @return L'id du fabricant
     */
    int getId() const;

    /**
     * @brief setId
     * @param value L'id à assigner au fabricant
     */
    void setId(const int &value);

    /**
     * @brief getNom
     * @return Le nom du fabricant
     */
    QString getNom() const;

    /**
     * @brief setNom
     * @param value Le nom à assigner au fabricant
     */
    void setNom(const QString &value);

    /**
     * @brief out
     * @return Représentation textuelle du fabricant
     */
    QString out() const;

};

#endif // FABRICANT_H
