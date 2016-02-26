#ifndef TYPEAPPAREIL_H
#define TYPEAPPAREIL_H

#include "Modeles/modelebd.h"

class TypeAppareil : public ModeleBD {

    Q_OBJECT

    // Type d'un appareil (ex. portable, bureau)

private:

    // Le nom du type d'appareil
    QString m_nom;

public:

    /**
     * @brief TypeAppareil
     * @param parent
     */
    explicit TypeAppareil(QObject* parent = 0);

    /**
     * @brief getNom
     * @return Le nom du type d'appareil
     */
    QString nom() const;

    /**
     * @brief setNom
     * @param value Le nom à assigner au type d'appareil
     */
    void setNom(const QString &value);

    /**
     * @brief out
     * @return Représentation textuelle du type d'appareil
     */
    QString out() const;

};

#endif // TYPEAPPAREIL_H
