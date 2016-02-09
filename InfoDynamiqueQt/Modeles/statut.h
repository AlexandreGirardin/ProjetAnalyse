#ifndef STATUT_H
#define STATUT_H

#include "Modeles/modelebd.h"

class Statut : public ModeleBD
{
    Q_OBJECT

    // Statut d'une fiche ou d'une tâche

private:

    // Le nom du statut
    QString m_nom;

public:

    /**
     * @brief Statut
     * @param parent
     */
    explicit Statut(QObject* parent = 0);

    /**
     * @brief Statut
     * @param a_id L'id du statut
     * @param a_nom Le nom du statut
     * @param parent
     */
    explicit Statut(const int &a_id, const QString &a_nom, QObject* parent = 0);

    /**
     * @brief getNom
     * @return Le nom du Statut
     */
    QString nom() const;

    /**
     * @brief setNom
     * @param value Le nom du statut
     */
    void setNom(const QString &value);

    /**
     * @brief out
     * @return La chaîne imprimable correspondant à la pièce
     */
    QString out() const;

};

#endif // STATUT_H
