#ifndef MAPPEURACTIONS_H
#define MAPPEURACTIONS_H

#include <QObject>

#include "Modeles/action.h"
#include "Modeles/ensembleactions.h"

#include <QSqlDatabase>
#include <QSqlRecord>

class MappeurActions : public QObject
{
    Q_OBJECT

    // Extrait des objets Action de la base de données

public:

    explicit MappeurActions(QObject* parent = 0);

    /**
     * @brief getAction
     * @param id Le numéro de l'action à mapper
     * @return L'action si elle existe, NULL autrement
     */
    Action* getAction(const int &id);

    /**
     * @brief getActions
     * @return La liste de toutes les actions de la base de données.
     */
    QList<Action*>* getActions();

    /**
     * @brief actionsDansEnsemble
     * Trouve les actions faisant partie d'un ensemble donné
     * @param idEnsemble L'id de l'ensemble à chercher
     * @return Toutes les actions qui font partie de l'ensemble
     */
    QList<Action*>* actionsDansEnsemble(const int &idEnsemble);

    /**
     * @brief actionsHorsEnsemble
     * Trouve les actions ne faisant pas partie d'un ensemble donné
     * @param idEnsemble L'id de l'ensemble à chercher
     * @return Toutes les actions qui ne font pas partie de l'ensemble
     */
    QList<Action*>* actionsHorsEnsemble(const int &idEnsemble);

    /**
     * @brief mettreAJour
     * Met à jour une action dans la base de données
     * @param action L'action à mettre à jour
     * @return Succès de l'écriture
     */
    bool mettreAJour(const Action* action) const;

    /**
     * @brief inserer
     * Inscrit une nouvelle action dans la base de données
     * @param action L'action à inscrire
     * @return Succès de l'écriture
     */
    bool inserer(const Action *action) const;

private:

    /**
     * @brief mapper
     * Extrait les informations d'un résultat d'une requête vers une action
     * @param ligne La ligne de la base de données à mapper en action
     * @return L'action
     */
    Action* mapper(const QSqlRecord &ligne);

    /**
     * @brief mapper
     * Construit toutes les actions se retrouvant dans les résultats d'une requête SQL
     * @param requete La requête à mapper
     * @return Les actions présentes dans la requête
     */
    QList<Action*>* mapper(QSqlQuery &requete);

    /**
     * @brief preparerRequete Assigne les valeurs d'une action à une requête préparée
     * @param action L'action source
     * @param commande La commande SQL à préparer
     * @return La commande préparée
     */
    QSqlQuery* preparerRequete(const Action* action, const QString &commande) const;

    /**
     * @brief ecrire
     * Effectue une opération SQL à l'intérieur d'une transaction
     * La transaction est annulée si l'opération échoue et validée autrement
     * @param action L'action à inclure dans l'opération SQL
     * @param commande La commande à exécuter
     * @return Succès de l'opération
     */
    bool ecrire(const Action* action, const QString &commande) const;

};

#endif // MAPPEURACTIONS_H
