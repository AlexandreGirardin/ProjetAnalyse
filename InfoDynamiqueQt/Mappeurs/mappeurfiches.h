#ifndef MAPPEURFICHES
#define MAPPEURFICHES

#include "Modeles/fiche.h"

#include <QSqlDatabase>
#include <QSqlRecord>

class MappeurFiches {

public:

    /**
     * @brief getFiche
     * @param id Le numéro de la fiche à mapper
     * @return le fabricant s'il existe, NULL autrement
     */
    static Fiche* getFiche(const int &id);

    static QList<Fiche*>* fichesPourAppareil(const int &idAppareil);

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
     * @param fiche
     * @param commande
     * @return
     */
    static bool ecrire(const Fiche* fiche, const QString &commande);

    static QList<Fiche*>* mapper(QSqlQuery &requete);
};

#endif // MAPPEURFICHES

