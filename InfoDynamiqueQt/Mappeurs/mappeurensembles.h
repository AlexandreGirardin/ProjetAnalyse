#ifndef MAPPEURENSEMBLES_H
#define MAPPEURENSEMBLES_H

#include <QObject>

#include "Modeles/ensembleactions.h"

#include <QSqlQuery>

class MappeurEnsembles : public QObject
{
    Q_OBJECT

public:

    explicit MappeurEnsembles(QObject *parent = 0);

    /**
     * @brief getEnsemble
     * Construit un ensemble donné
     * @param id Le numéro de l'ensemble à mapper
     * @return L'ensemble s'il existe, NULL autrement
     */
    EnsembleActions* getEnsemble(const int &id);

    /**
     * @brief getActions
     * Construit tous les ensembles de la base de données
     * @return La liste de tous les ensembles de la base de données.
     */
    QList<EnsembleActions*>* getEnsembles();

    /**
     * @brief inserer
     * Inscrit un nouvel ensemble dans la base de données
     * @param ensemble L'ensemble à inscrire
     * @return Succès de l'écriture
     */
    bool inserer(EnsembleActions* ensemble) const;

    /**
     * @brief mettreAJour
     * Met à jour un ensemble dans la base de données
     * @param action L'ensemble à mettre à jour
     * @return Succès de l'écriture
     */
    bool mettreAJour(const EnsembleActions* ensemble) const;

    /**
     * @brief supprimer
     * Retire un ensemble de la base de données
     * @param ensemble L'ensemble à effacer
     * @return Succès de la suppression
     */
    bool supprimer(EnsembleActions* ensemble) const;

private:

    /**
     * @brief mapper
     * Extrait les informations d'un résultat d'une requête vers un ensemble
     * @param ligne La ligne de la base de données à mapper en ensemble
     * @return L'ensemble
     */
    EnsembleActions* mapper(const QSqlRecord &ligne);

    /**
     * @brief mapper
     * Construit tous les ensembles se retrouvant dans les résultats d'une requête SQL
     * @param requete La requête à mapper
     * @return Les ensembles présents dans la requête
     */
    QList<EnsembleActions*>* mapper(QSqlQuery &requete);

    /**
     * @brief preparerRequete Assigne les valeurs d'un ensemble à une requête préparée
     * @param ensemble L'ensemble source
     * @param commande La commande SQL à préparer
     * @return La commande préparée
     */
    QSqlQuery* preparerRequete(const EnsembleActions* ensemble, const QString &commande) const;

    /**
     * @brief ecrire
     * Effectue une opération SQL à l'intérieur d'une transaction
     * La transaction est annulée si l'opération échoue et validée autrement
     * @param ensemble L'ensemble à inclure dans l'opération SQL
     * @param commande La commande à exécuter
     * @return Succès de l'opération
     */
    bool ecrire(const EnsembleActions* ensemble, const QString &commande) const;

    /**
     * @brief ecrireActions
     * Effectue une opération SQL sur toutes les actions d'un ensemble données
     * @param ensemble L'ensemble à traiter
     * @param commande L'opération SQL à exécuter sur chacune des actions
     * @return Succès de l'opération
     */
    bool ecrireActions(const EnsembleActions* ensemble, const QString &commande) const;

    /**
     * @brief derniereInsertion
     * Retourne l'id de la dernière insertion dans la base de données
     * Permet l'inscription des actions d'un ensemble nouvellement créé
     * @return L'id de la dernière insertion
     */
    int derniereInsertion() const;
};

#endif // MAPPEURENSEMBLES_H
