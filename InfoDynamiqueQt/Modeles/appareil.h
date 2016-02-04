#ifndef APPAREIL_H
#define APPAREIL_H

#include "Modeles/modelebd.h"

#include "Modeles/fabricant.h"
#include "Modeles/typeappareil.h"

class Appareil : public ModeleBD {
    Q_OBJECT

    // Appareil électronique d'un client

private:

    // L'id de l'appareil
    int m_id;

    // Le frabricant de l'appareil
    Fabricant* m_fabricant;

    // Le type de l'appareil
    TypeAppareil* m_type;

    // Le mot de passe de l'appareil
    QString m_motDePasse;

    // La description de l'appareil
    QString m_description;

    // Le propriétaire de l'appareil
    int m_idClient;

public:

    /**
     * @brief Appareil
     * @param parent
     */
    explicit Appareil(QObject* parent = 0);

    /**
     * @brief getId
     * @return L'id de l'appareil
     */
    int id() const;

    /**
     * @brief setId
     * @param value L'id à assigner à l'appareil
     */
    void setId(const int &value);

    /**
     * @brief getFabricant
     * @return Le fabricant de l'appareil
     */
    Fabricant* fabricant() const;

    /**
     * @brief getNomFabricant
     * Le nom du fabricant, s'il est défini
     * @return Le nom du fabricant ou une chaîne vide
     */
    QString nomFabricant() const;

    /**
     * @brief setFabricant
     * @param value Le fabricant à assigner à l'appareil
     */
    void setFabricant(Fabricant* value);

    /**
     * @brief getType
     * @return Le type de l'appareil
     */
    TypeAppareil* type() const;

    /**
     * @brief getNomType
     * Le nom du type, s'il est défini
     * @return Le nom du type ou une chaîne vide
     */
    QString nomType() const;

    /**
     * @brief setType
     * Assigne un type à l'appareil
     * @param value Le type à assigner à l'appareil
     */
    void setType(TypeAppareil* value);

    /**
     * @brief getMotDePasse
     * @return Le mot de passe de l'appareil
     */
    QString motDePasse() const;

    /**
     * @brief setMotDePasse
     * Assigne un mot de passe à l'appareil
     * @param value Le mot de passe à assigner
     */
    void setMotDePasse(const QString &value);

    /**
     * @brief getDescription
     * @return La description de l'appareil
     */
    QString description() const;

    /**
     * @brief setDescription
     * Assigne une description à l'appareil
     * @param value La description à assigner
     */
    void setDescription(const QString &value);

    /**
     * @brief getIdClient
     * @return L'id du propriétaire de l'appareil
     */
    int idClient() const;

    /**
     * @brief setIdClient
     * Assigne l'id du propriétaire de l'appareil
     * @param value L'id du propriétaire à assigner à l'appareil
     */
    void setIdClient(const int &value);

    /**
     * @brief out
     * @return Représentation textuelle de l'appareil
     */
    QString out() const;
};

#endif // APPAREIL_H
