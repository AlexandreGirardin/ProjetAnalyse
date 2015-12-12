#ifndef APPAREIL_H
#define APPAREIL_H

#include <QObject>

#include "Modeles/fabricant.h"
#include "Modeles/typeappareil.h"

class Appareil : public QObject {
    Q_OBJECT

    // Appareil électronique d'un client

private:

    // L'id de l'appareil
    int id;

    // Le frabricant de l'appareil
    Fabricant *fabricant;

    // Le type de l'appareil
    TypeAppareil* type;

public:

    /**
     * @brief Appareil
     * @param parent
     */
    explicit Appareil(QObject *parent = 0);

    /**
     * @brief getId
     * @return L'id de l'appareil
     */
    int getId() const;

    /**
     * @brief setId
     * @param value L'id à assigner à l'appareil
     */
    void setId(int value);

    /**
     * @brief getFabricant
     * @return Le fabricant de l'appareil
     */
    Fabricant *getFabricant() const;

    /**
     * @brief setFabricant
     * @param value Le fabricant à assigner à l'appareil
     */
    void setFabricant(Fabricant *value);

    /**
     * @brief getType
     * @return Le type de l'appareil
     */
    TypeAppareil *getType() const;

    /**
     * @brief setType
     * @param value Le type à assigner à l'appareil
     */
    void setType(TypeAppareil *value);

    /**
     * @brief out
     * @return Représentation textuelle de l'appareil
     */
    QString out(void);

};

#endif // APPAREIL_H
