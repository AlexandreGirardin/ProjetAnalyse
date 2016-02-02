#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include "Modeles/modelebd.h"

class Technicien : public ModeleBD
{
    Q_OBJECT

    // Employé de l'entreprise qui effectue des tâches sur les appareils

private:

    // L'id du technicien
    int id;

    // Le nom du technicien
    QString nom;

public:

    /**
     * @brief Technicien
     * @param parent
     */
    explicit Technicien(QObject* parent = 0);

    /**
     * @brief Technicien
     * @param a_id L'id à assigner au technicien
     * @param a_nom Le nom à assigner au technicien
     * @param parent
     */
    Technicien(const int &a_id, const QString &a_nom, QObject* parent = 0);

    /**
     * @brief getId
     * @return L'id du technicien
     */
    int getId() const;

    /**
     * @brief setId
     * @param value L'id à assigner au technicien
     */
    void setId(const int &value);

    /**
     * @brief getNom
     * @return Le nom du technicien
     */
    QString getNom() const;

    /**
     * @brief setNom
     * @param value Le nom à assigner au technicien
     */
    void setNom(const QString &value);

    /**
     * @brief out
     * @return Représentation textuelle du technicien
     */
    QString out();

};

#endif // TECHNICIEN_H
