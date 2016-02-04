#ifndef GESTIONAPPAREIL_H
#define GESTIONAPPAREIL_H

#include <QDialog>

#include "Modeles/typeappareil.h"
#include "Modeles/fabricant.h"

namespace Ui {
class VueGestionAppareil;
}

class VueGestionAppareil : public QDialog
{
    Q_OBJECT

    // Vue servant à créer, visualiser et modifier un appareil

public:

    explicit VueGestionAppareil(QWidget* parent = 0);

    ~VueGestionAppareil();

    /**
     * @brief setTypes
     * Assigne la liste des types d'appareil
     * @param a_types La liste des types à présenter
     */
    void setTypes(QList<TypeAppareil*>* a_types);

    /**
     * @brief setTypes
     * Assigne la liste des types d'appareil et en sélectionne un
     * @param a_types La liste des types à présenter
     * @param a_type Le nom du type à sélectionner initialement
     */
    void setTypes(QList<TypeAppareil*>* a_types, const QString &a_type);

    /**
     * @brief setType
     * Sélectionne un type
     * @param a_type Le nom du type à sélectionner initialement
     */
    void setType(const QString &a_type);

    /**
     * @brief getType
     * @return Le type actuellement sélectionné
     */
    TypeAppareil* getType() const;

    /**
     * @brief setFabricants
     * Assigne la liste des fabricants
     * @param a_fabricants La liste des fabricant à présenter
     */
    void setFabricants(QList<Fabricant *> *a_fabricants);

    /**
     * @brief setFabricants
     * Assigne la liste des fabricants et en sélectionne un
     * @param a_fabricants La liste des fabricants à présenter
     * @param a_fabricant Le nom du fabricant à sélectionner initialement
     */
    void setFabricants(QList<Fabricant*>* a_fabricants, const QString &a_fabricant);

    /**
     * @brief setFabricant
     * Sélectionne un fabricant
     * @param a_fabricant
     */
    void setFabricant(const QString &a_fabricant);

    /**
     * @brief getFabricant
     * @return Le fabricant actuellement sélectionné
     */
    Fabricant* getFabricant() const;

    /**
     * @brief setMotDePasse
     * Assigne un mot de passe
     * @param a_motDePasse Le mot de passe à assigner
     */
    void setMotDePasse(const QString &a_motDePasse);

    /**
     * @brief getMotDePasse
     * @return Le mot de passe actuel
     */
    QString getMotDePasse() const;

    /**
     * @brief setDescription
     * Assigne une description
     * @param a_description La description à assigner
     */
    void setDescription(const QString &a_description);

    /**
     * @brief getDescription
     * @return La description actuelle
     */
    QString getDescription() const;

private:

    Ui::VueGestionAppareil* ui;

    /**
     * @brief types
     * La liste des types permettant de retourner l'objet Type sélectionné
     */
    QList<TypeAppareil*>* types;

    /**
     * @brief types
     * La liste des fabricants permettant de retourner l'objet Fabricant sélectionné
     */
    QList<Fabricant*>* fabricants;
};

#endif // GESTIONAPPAREIL_H
