#ifndef MODELEBD_H
#define MODELEBD_H

#include <QObject>

class ModeleBD : public QObject
{

    // Parent abstrait des autres modèle

protected:

    // L'identifiant unique du modèle dans une table de la BD
    int m_id;

public:

    explicit ModeleBD(QObject *parent = 0);

    /**
     * @brief getId
     * @return L'identifiant unique du modèle dans une table de la BD
     */
    int id() const;

    /**
     * @brief setId
     * @param value La valeur à assigner à id
     */
    void setId(const int &value);

    /**
     * @brief out
     * @return Représentation textuelle du client
     */
    QString out() const;

};

#endif // MODELEBD_H
