#ifndef STATUT_H
#define STATUT_H

#include <QObject>

class Statut : public QObject
{
    Q_OBJECT

private:

    // L'identifiant unique du statut
    int id;

    // Le nom du statut
    QString nom;

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
    explicit Statut(int a_id, QString a_nom, QObject *parent = 0);

    /**
     * @brief getId
     * @return L'id du statut
     */
    int getId() const;

    /**
     * @brief setId
     * @param value L'id à assigner pour le statut
     */
    void setId(int value);

    /**
     * @brief getNom
     * @return Le nom du Statut
     */
    QString getNom() const;

    /**
     * @brief setNom
     * @param value Le nom du statut
     */
    void setNom(const QString &value);

    /**
     * @brief out
     * @return La chaîne imprimable correspondant à la pièce
     */
    QString out(void);

signals:

public slots:

};

#endif // STATUT_H