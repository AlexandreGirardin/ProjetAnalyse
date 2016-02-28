#ifndef CLIENT_H
#define CLIENT_H

#include <Modeles/modelebd.h>

class Appareil;

class Client : public ModeleBD {

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

    // Adresse électronique du client
    QString m_courriel;

public:

    explicit Client(QObject* parent = 0);

    /**
     * @brief prenom
     * @return Le prénom du client
     */
    QString prenom() const;

    /**
     * @brief setPrenom
     * @param value Le prénom à assigner au client
     */
    void setPrenom(const QString &value);

    /**
     * @brief nom
     * @return Le nom du client
     */
    QString nom() const;

    /**
     * @brief setNom
     * @param value Le nom à assigner au client
     */
    void setNom(const QString &value);

    /**
     * @brief telephone
     * @return Le numéro de téléphone du client
     */
    QString telephone() const;

    /**
     * @brief setTelephone
     * @param value Le numéro de téléphone à assigner au client
     */
    void setTelephone(const QString &value);

    /**
     * @brief adresse
     * @return L'adresse résidentielle du client
     */
    QString adresse() const;

    /**
     * @brief setAdresse
     * @param value L'adresse résidentielle à assigner au client
     */
    void setAdresse(const QString &value);

    /**
     * @brief courriel
     * @return L'adresse électronique du client
     */
    QString courriel() const;

    /**
     * @brief setCourriel
     * Assigne une adresse électronique au client
     * @param courriel La valeur à assigner
     */
    void setCourriel(const QString &courriel);

    /**
     * @brief out
     * @return Représentation textuelle du client
     */
    QString out() const;

};

#endif // CLIENT_H
