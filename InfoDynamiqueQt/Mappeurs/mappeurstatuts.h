#ifndef MAPPEURSTATUTS_H
#define MAPPEURSTATUTS_H

#include <QObject>

#include "Modeles/statut.h"

#include <QSqlDatabase>
#include <QSqlRecord>

class MappeurStatuts : public QObject
{
    Q_OBJECT

    // Extrait des objets Statut (fiches ou pièces) de la base de données

public:

    /**
     * @brief MappeurStatuts
     * @param a_bd La base de données à utiliser
     * @param parent
     */
    explicit MappeurStatuts(QObject* parent = 0);

    /**
     * @brief getStatutFiche
     * @param id Le numéro du statutFiche à mapper
     * @return Le statut si elle existe. NULL autrement
     */
    Statut* getStatutFiche(const int &idStatut);

    /**
     * @brief getStatutsFiche
     * @return La liste de tous les statuts des fiches
     */
    QList<Statut*>* getStatutsFiche();

    /**
     * @brief getStatutTache
     * @param id Le numéro du statutAction à mapper
     * @return Le statut s'il existe, NULL autrement
     */
    Statut* getStatutTache(const int &idStatut);

    /**
     * @brief getStatutsTache
     * @return La liste de tous les statuts des actions
     */
    QList<Statut*>* getStatutsTache();

private:

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en pièce
     * @return La pièce
     */
    Statut* mapper(const QSqlRecord &ligne);

    /**
     * @brief mapper
     * Construit tous les statuts se retrouvant dans les résulats d'une requête SQL
     * @param requete La requête à mapper
     * @return Les statuts présents dans la requête
     */
    QList<Statut*>* mapper(QSqlQuery &requete);

    /**
     * @brief getStatut
     * Fonction interne retournant un statut générique
     * @param idStatut L'id du statut à construire
     * @param commande La commande permettant d'obtenir le statut
     * @return Le statut (tâches ou fiches)
     */
    Statut* getStatut(const int &idStatut, const QString &commande);
};

#endif // MAPPEURSTATUTS_H
