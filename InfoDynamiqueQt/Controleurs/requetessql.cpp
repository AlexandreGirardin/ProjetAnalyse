#include "requetessql.h"

RequetesSQL::RequetesSQL(QObject *parent) :
    QObject(parent)
{
}

QString* RequetesSQL::afficherAppareils =
        new QString(
            "SELECT\
                a.id AS '#',\
                c.telephone AS 'Client',\
                t.nom as 'Type',\
                f.nom AS 'Fabricant',\
                COALESCE(fi.nbO, 0) as 'Fiches',\
                a.description AS 'Description'\
            FROM\
                appareils a\
            LEFT OUTER JOIN\
                (select id, nom from fabricants) f\
            ON\
                a.idFabricant = f.id\
            LEFT OUTER JOIN\
                (select idAppareil, count(id) as 'nbO' from fiches group by idAppareil) fi\
            ON\
                a.id = fi.idAppareil\
            LEFT OUTER JOIN\
                (select id, telephone from clients) c\
            ON\
                a.idClient = c.id\
            LEFT OUTER JOIN\
                (select id, nom from types) t\
            ON\
                a.idType = t.id");

QString* RequetesSQL::filtrerAppareils =
        new QString(*afficherAppareils +
                     QString(" WHERE c.telephone LIKE :filtre\
                             OR t.nom LIKE :filtre\
                             OR f.nom LIKE :filtre\
                             OR a.description LIKE :filtre"));

QString* RequetesSQL::afficherToutesActions =
        new QString("SELECT\
                        id,\
                        nom as 'Action',\
                        description as 'Description',\
                        IF (etat < 1, '', '✓') as 'Activée'\
                    FROM actions");

QString* RequetesSQL::afficherActionsActives =
        new QString("SELECT\
                         id,\
                         nom as 'Action',\
                         description as 'Description'\
                     FROM actions\
                     WHERE etat = 1");

QString* RequetesSQL::filtrerToutesActions =
        new QString(*afficherToutesActions
                      + QString(" WHERE id LIKE :filtre\
                                    OR nom LIKE :filtre\
                                    OR description LIKE :filtre"));

QString* RequetesSQL::filtrerActionsActives =
        new QString(*afficherActionsActives
                      + QString(" HAVING id LIKE :filtre\
                                    OR nom LIKE :filtre\
                                    OR description LIKE :filtre"));

QString* RequetesSQL::afficherEnsembles =
        new QString("SELECT\
                        e.id,\
                        a.nb as 'Nb. actions',\
                        nom as 'Ensemble',\
                        description as 'Description'\
                    FROM ensembles e\
                    LEFT OUTER JOIN\
                        (SELECT\
                            e.id as 'id', count(e.id) as 'nb'\
                        FROM\
                            ensembles e\
                        LEFT OUTER JOIN\
                            ensemblesActions ea\
                        ON\
                            e.id = ea.idEnsemble\
                        GROUP BY e.id) a\
                    ON\
                        a.id = e.id");
