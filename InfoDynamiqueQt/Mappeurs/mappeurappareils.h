#ifndef MAPPEURAPPAREILS_H
#define MAPPEURAPPAREILS_H

#include <QObject>

#include "Mappeurs/mappeurtypeappareils.h"

#include "Modeles/action.h"
#include "Modeles/appareil.h"
#include "Modeles/client.h"

#include <QSqlDatabase>
#include <QSqlRecord>

class MappeurAppareils : public QObject
{
    Q_OBJECT

    // Extrait des objets Appareil de la base de données

public:

    /**
     * @brief MappeurAppareils
     * @param a_bd La base de données à utiliser
     * @param parent
     */
    explicit MappeurAppareils(QObject* parent = 0);

    /**
     * @brief getAppareil
     * @param id Le numéro de l'appareil à mapper
     * @return L'appareil s'il existe, NULL autrement
     */
    Appareil* getAppareil(const int &id);

    /**
     * @brief appareilsPourClient
     * Trouve les appareils appartenant à un client
     * @param client Le client cible
     * @return La liste des appareils appartenant au client
     */
    QList<Appareil*>* appareilsPourClient(const int &idClient);

    /**
     * @brief mettreAJour
     * Met à jour un appareil dans la base de données
     * @param appareil L'appareil à mettre à jour
     * @return Succès
     */
    bool mettreAJour(const Appareil* appareil) const;

    /**
     * @brief inserer
     * Insère un nouvel appareil dans la base de données
     * @param appareil L'appareil à ajouter
     * @return Succès
     */
    bool inserer(const Appareil* appareil) const;

private:

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en appareil
     * @return L'appareil
     */
    Appareil* mapper(const QSqlRecord &ligne);

    /**
     * @brief preparerRequete Assigne les valeurs d'un appareil à une requête préparée
     * @param appareil L'appareil source
     * @param commande La commande SQL à préparer
     * @return La commande préparée
     */
    QSqlQuery* preparerRequete(const Appareil* appareil, const QString &commande) const;

    QList<Appareil*>* mapper(QSqlQuery &requete);

    bool ecrire(const Appareil* appareil, const QString &commande) const;

};

#endif // MAPPEURAPPAREILS_H
