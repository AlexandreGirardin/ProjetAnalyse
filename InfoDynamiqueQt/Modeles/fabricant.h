#ifndef FABRICANT_H
#define FABRICANT_H

#include "Modeles/modelebd.h"

class Fabricant : public ModeleBD {

    // Marque du constructeur d'un appareil permettant de l'identifier

private:

    // Le nom du fabricant
    QString m_nom;

public:

    /**
     * @brief Fabricant
     * Le constructeur de l'objet
     * @param parent L'objet parent
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
     * @brief getNom
     * @return Le nom du fabricant
     */
    QString nom() const;

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
