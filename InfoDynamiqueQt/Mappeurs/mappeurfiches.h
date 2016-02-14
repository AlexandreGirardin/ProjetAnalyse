#ifndef MAPPEURFICHES
#define MAPPEURFICHES

#include "Modeles/fiche.h"

#include <QSqlQuery>
#include <QSqlRecord>

class MappeurFiches {

    // Lit et écrit des objets Fiches dans la base de données

public:

    /**
     * @brief getFiche
     * @param id Le numéro de la fiche à mapper
     * @return le fabricant s'il existe, NULL autrement
     */
    static Fiche* getFiche(const int &id);

    /**
     * @brief fichesPourAppareil
     * Retourne les fiches associées à un appareil donné
     * @param idAppareil L'id de l'appareil à chercher
     * @return Les fiches de l'appareil
     */
    static QList<Fiche*>* fichesPourAppareil(const int &idAppareil);

    /**
     * @brief nombreFiches
     * Retourne le nombre de fiches associées à un appareil donné
     * @param idAppareil L'id de l'appareil à chercher
     * @return Le nombre de fiches de l'appareil
     */
    static int nombreFiches(const int &idAppareil);

    /**
     * @brief inserer
     * Insère une nouvelle fiche dans la base de données
     * @param fiche La fiche à ajouter
     * @return Succès
     */
    static bool inserer(Fiche* fiche);

    /**
     * @brief mettreAJour
     * Met à jour une fiche dans la base de données
     * @param appareil La fiche à mettre à jour
     * @return Succès
     */
    static bool mettreAJour(const Fiche* fiche);

private:

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en pièce
     * @return Le fiche
     */
    static Fiche* mapper(const QSqlRecord &ligne);

    /**
     * @brief mapper
     * Construit toutes les fiches se retrouvant dans les résultats d'une requête SQL
     * @param requete La requête à mapper
     * @return Les fiches présentes dans la requête
     */
    static QList<Fiche*>* mapper(QSqlQuery &requete);

    /**
     * @brief preparerRequete Assigne les valeurs d'une fiche à une requête préparée
     * @param fiche La fiche source
     * @param commande La commande SQL à préparer
     * @return La commande préparée
     */
    static QSqlQuery* preparerRequete(const Fiche* fiche, const QString &commande);

    /**
     * @brief derniereInsertion
     * @return L'id de la dernière fiche entré
     */
    static int derniereInsertion();

    /**
     * @brief ecrire
     * Effectue une opération SQL à l'intérieur d'une transaction
     * La transaction est annulée si l'opération échoue et validée autrement
     * @param appareil La fiche à inclure dans l'opération SQL
     * @param commande La commande à exécuter
     * @return Succès de l'opération
     */
    static bool ecrire(const Fiche* fiche, const QString &commande);
};

#endif // MAPPEURFICHES

