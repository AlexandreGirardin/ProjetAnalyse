#ifndef MAPPEURENSEMBLES_H
#define MAPPEURENSEMBLES_H

#include "Modeles/ensembleactions.h"

#include <QSqlQuery>

class MappeurEnsembles {

public:

    /**
     * @brief getEnsemble
     * Construit un ensemble donné
     * @param id Le numéro de l'ensemble à mapper
     * @return L'ensemble s'il existe, NULL autrement
     */
    static EnsembleActions* getEnsemble(const int &id);

    /**
     * @brief getActions
     * Construit tous les ensembles de la base de données
     * @return La liste de tous les ensembles de la base de données.
     */
    static QList<EnsembleActions*>* getEnsembles();

    /**
     * @brief inserer
     * Inscrit un nouvel ensemble dans la base de données
     * @param ensemble L'ensemble à inscrire
     * @return Succès de l'écriture
     */
    static bool inserer(EnsembleActions* ensemble);

    /**
     * @brief mettreAJour
     * Met à jour un ensemble dans la base de données
     * @param action L'ensemble à mettre à jour
     * @return Succès de l'écriture
     */
    static bool mettreAJour(const EnsembleActions* ensemble);

    /**
     * @brief supprimer
     * Retire un ensemble de la base de données
     * @param ensemble L'ensemble à effacer
     * @return Succès de la suppression
     */
    static bool supprimer(const EnsembleActions* ensemble);

private:

    /**
     * @brief mapper
     * Extrait les informations d'un résultat d'une requête vers un ensemble
     * @param ligne La ligne de la base de données à mapper en ensemble
     * @return L'ensemble
     */
    static EnsembleActions* mapper(const QSqlRecord &ligne);

    /**
     * @brief mapper
     * Construit tous les ensembles se retrouvant dans les résultats d'une requête SQL
     * @param requete La requête à mapper
     * @return Les ensembles présents dans la requête
     */
    static QList<EnsembleActions*>* mapper(QSqlQuery &requete);

    /**
     * @brief preparerRequete Assigne les valeurs d'un ensemble à une requête préparée
     * @param ensemble L'ensemble source
     * @param commande La commande SQL à préparer
     * @return La commande préparée
     */
    static QSqlQuery* preparerRequete(const EnsembleActions* ensemble, const QString &commande);

    /**
     * @brief ecrire
     * Effectue une opération SQL à l'intérieur d'une transaction
     * La transaction est annulée si l'opération échoue et validée autrement
     * @param ensemble L'ensemble à inclure dans l'opération SQL
     * @param commande La commande à exécuter
     * @return Succès de l'opération
     */
    static bool ecrire(const EnsembleActions* ensemble, const QString &commande);

    /**
     * @brief ecrireActions
     * Effectue une opération SQL sur toutes les actions d'un ensemble données
     * @param ensemble L'ensemble à traiter
     * @param commande L'opération SQL à exécuter sur chacune des actions
     * @return Succès de l'opération
     */
    static bool ecrireActions(const EnsembleActions* ensemble, const QString &commande);
};

#endif // MAPPEURENSEMBLES_H
