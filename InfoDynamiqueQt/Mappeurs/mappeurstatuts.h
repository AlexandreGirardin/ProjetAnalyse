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
    static Statut* getStatutFiche(const int &idStatut);

    /**
     * @brief getStatutsFiche
     * @return La liste de tous les statuts des fiches
     */
    static QList<Statut*>* getStatutsFiche();

    /**
     * @brief getStatutAction
     * @param id Le numéro du statutAction à mapper
     * @return Le statut s'il existe, NULL autrement
     */
    static Statut* getStatutAction(const int &idStatut);

    /**
     * @brief getStatutsAction
     * @return La liste de tous les statuts des actions
     */
    static QList<Statut*>* getStatutsAction();

private:

    /**
     * @brief mapper
     * @param ligne La ligne de la base de données à mapper en pièce
     * @return La pièce
     */
    static Statut* mapper(const QSqlRecord &ligne);

    static QList<Statut*>* mapper(QSqlQuery &requete);
    static Statut *getStatut(const int &idStatut, const QString &commande);
};

#endif // MAPPEURSTATUTS_H
