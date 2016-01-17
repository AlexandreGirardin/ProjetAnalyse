#ifndef CLIENT_H
#define CLIENT_H

#include <Modeles/modelebd.h>
#include "Modeles/appareil.h"

class Client : public ModeleBD {
    Q_OBJECT

    // Personne qui fait affaire avec l'entreprise

private:

    // Prénom du client
    QString prenom;

    // Nom de famille du client
    QString nom;

    // Numéro de téléphone du client
    QString telephone;

    // Adresse du client
    QString adresse;

    // Liste des appareils du client
    QList<Appareil*>* appareils;

public:

    /**
     * @brief Client
     * @param parent
     */
    explicit Client(QObject* parent = 0);

    /**
     * @brief getPrenom
     * @return Le prénom du client
     */
    QString getPrenom() const;

    /**
     * @brief setPrenom
     * @param value Le prénom à assigner au client
     */
    void setPrenom(const QString &value);

    /**
     * @brief getNom
     * @return Le nom du client
     */
    QString getNom() const;

    /**
     * @brief setNom
     * @param value Le nom à assigner au client
     */
    void setNom(const QString &value);

    /**
     * @brief getTelephone
     * @return Le numéro de téléphone du client
     */
    QString getTelephone() const;

    /**
     * @brief setTelephone
     * @param value Le numéro de téléphone à assigner au client
     */
    void setTelephone(const QString &value);

    /**
     * @brief getAdresse
     * @return L'adresse du client
     */
    QString getCourriel() const;

    /**
     * @brief setAdresse
     * @param value L'adresse à assigner au client
     */
    void setCourriel(const QString &value);

    /**
     * @brief getAppareils
     * @return La liste des appareils du client
     */
    QList<Appareil*>* getAppareils() const;

    /**
     * @brief setAppareils
     * @param value La liste d'appareils à assigner au client
     */
    void setAppareils(const QList<Appareil*> &value);

    /**
     * @brief out
     * @return Représentation textuelle du client
     */
    QString out();

};

#endif // CLIENT_H
