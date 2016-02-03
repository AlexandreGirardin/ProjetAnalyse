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

    /**
     * @brief MappeurActions
     * @param a_bd La base de données à utiliser
     * @param parent
     */
    explicit MappeurActions(QObject* parent = 0);

    /**
     * @brief getAction
     * @param id Le numéro de l'action à mapper
     * @return L'action si elle existe. NULL autrement
     */
    Action* getAction(const int &id);

    /**
     * @brief getActions
     * @return La liste de toutes les actions de la base de données.
     */
    QList<Action*>* getActions();

    /**
     * @brief mettreAJour
     * Met à jour une action dans la base de données
     * @param action L'action à mettre à jour
     * @return Succès
     */
    bool mettreAJour(const Action* action) const;

    QList<Action*>* actionsDansEnsemble(const int &idEnsemble);

    QList<Action*>* actionsHorsEnsemble(const int &idEnsemble);

private:

    /**
     * @brief mapper Transfert les données d'une entrée de bd dans une action
     * @param ligne La ligne de la base de données à mapper en pièce
     * @return l'Action
     */
    Action* mapper(const QSqlRecord &ligne);

    QList<Action*>* mapper(QSqlQuery &requete);

    /**
     * @brief preparerRequete Assigne les valeurs d'une action à une requête préparée
     * @param action L'action source
     * @param commande La commande SQL à préparer
     * @return La commande préparée
     */
    QSqlQuery* preparerRequete(const Action* action, const QString &commande) const;

    bool ecrire(const Action* action, const QString &commande) const;

};

#endif // MAPPEURACTIONS_H
