#ifndef CLIENT_H
#define CLIENT_H

#include <Modeles/modelebd.h>
#include "Modeles/appareil.h"

class Client : public ModeleBD {
    Q_OBJECT

    // Personne qui fait affaire avec l'entreprise

private:

    // Prénom du client
    QString m_prenom;

    // Nom de famille du client
    QString m_nom;

    // Numéro de téléphone du client
    QString m_telephone;

    // Adresse du client
    QString m_adresse;

    // Liste des appareils du client
    QList<Appareil*>* m_appareils;

public:

    /**
     * @brief Client
     * @param parent
     */
    explicit Client(QObject* parent = 0);

    ~Client();

    /**
     * @brief getPrenom
     * @return Le prénom du client
     */
    QString prenom() const;

    /**
     * @brief setPrenom
     * @param value Le prénom à assigner au client
     */
    void setPrenom(const QString &value);

    /**
     * @brief getNom
     * @return Le nom du client
     */
    QString nom() const;

    /**
     * @brief setNom
     * @param value Le nom à assigner au client
     */
    void setNom(const QString &value);

    /**
     * @brief getTelephone
     * @return Le numéro de téléphone du client
     */
    QString telephone() const;

    /**
     * @brief setTelephone
     * @param value Le numéro de téléphone à assigner au client
     */
    void setTelephone(const QString &value);

    /**
     * @brief getAdresse
     * @return L'adresse résidentielle du client
     */
    QString adresse() const;

    /**
     * @brief setAdresse
     * @param value L'adresse résidentielle à assigner au client
     */
    void setAdresse(const QString &value);

    /**
     * @brief getAppareils
     * @return La liste des appareils du client
     */
    QList<Appareil*>* appareils() const;

    /**
     * @brief setAppareils
     * @param value La liste d'appareils à assigner au client
     */
    void setAppareils(QList<Appareil*>* value);

    /**
     * @brief out
     * @return Représentation textuelle du client
     */
    QString out() const;

};

#endif // CLIENT_H
