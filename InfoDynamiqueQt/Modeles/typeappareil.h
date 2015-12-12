#ifndef TYPEAPPAREIL_H
#define TYPEAPPAREIL_H

#include <QObject>

class TypeAppareil : public QObject {
    Q_OBJECT

    // Type d'un appareil (ex. portable, bureau)

private:

    // L'id du type d'appareil
    int id;

    // Le nom du type d'appareil
    QString nom;

public:

    /**
     * @brief TypeAppareil
     * @param a_id L'id à assigner au type
     * @param a_nom Le nom à assigner au nom
     * @param parent
     */
    explicit TypeAppareil(int a_id, QString a_nom, QObject *parent = 0);

    /**
     * @brief getId
     * @return L'id du type d'appareil
     */
    int getId() const;

    /**
     * @brief setId
     * @param value L'id à assigner au type d'appareil
     */
    void setId(int value);

    /**
     * @brief getNom
     * @return Le nom du type d'appareil
     */
    QString getNom() const;

    /**
     * @brief setNom
     * @param value Le nom à assigner au type d'appareil
     */
    void setNom(const QString &value);

    /**
     * @brief out
     * @return Représentation textuelle du type d'appareil
     */
    QString out(void);

};

#endif // TYPEAPPAREIL_H
