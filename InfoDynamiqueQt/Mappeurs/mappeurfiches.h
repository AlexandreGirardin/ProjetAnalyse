#ifndef MAPPEURFICHES
#define MAPPEURFICHES

#include <QObject>

#include "Modeles/fiche.h"

#include <QSqlDatabase>
#include <QSqlRecord>

class MappeurFiches : public QObject
{
    Q_OBJECT

public:

    /**
     * @brief MappeurFiches
     * @param a_bd La base de données à utiliser
     * @param parent
     */
    explicit MappeurFiches(QObject* parent = 0);

    /**
     * @brief getFiche
     * @param id Le numéro de la fiche à mapper
     * @return le fabricant s'il existe, NULL autrement
     */
    Fiche* getFiche(const int &id);

    /**
     * @brief inserer
     * Insère une nouvelle fiche dans la base de données
     * @param fiche La fiche à ajouter
     * @return Succès
     */
    bool inserer(const Fiche* fiche) const;

    /**
     * @brief mettreAJour
     * Met à jour une fiche dans la base de données
     * @param appareil La fiche à mettre à jour
     * @return Succès
     */
    bool mettreAJour(const Fiche* fiche) const;

private:

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en pièce
     * @return Le fiche
     */
    Fiche* mapper(const QSqlRecord &ligne);

    /**
     * @brief preparerRequete Assigne les valeurs d'une fiche à une requête préparée
     * @param fiche La fiche source
     * @param commande La commande SQL à préparer
     * @return La commande préparée
     */
    QSqlQuery* preparerRequete(const Fiche* fiche, const QString &commande) const;

    /**
     * @brief derniereInsertion
     * @return L'id de la dernière fiche entré
     */
    int derniereInsertion() const;

    /**
     * @brief ecrire
     * @param fiche
     * @param commande
     * @return
     */
    bool ecrire(const Fiche* fiche, const QString &commande) const;

};

#endif // MAPPEURFICHES

