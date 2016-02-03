#include "requetessql.h"

QString const * const RequetesSQL::afficherClients =
        new QString(
            "SELECT\
                  c.id as '#',\
                  c.telephone as 'Téléphone',\
                  COALESCE(a.nb,0) as 'Nb. appareils',\
                  CONCAT(c.nom, ', ', c.prenom) as 'Nom'\
             FROM\
                  clients c\
             LEFT OUTER JOIN\
                  (SELECT idClient, count(id) as 'nb' FROM appareils GROUP BY idClient) a\
             ON\
                  c.id = a.idClient");

QString const * const RequetesSQL::filtrerClients =
        new QString (*afficherClients +
                        QString(" WHERE c.id LIKE :filtre\
                                OR CONCAT(c.nom, ', ', c.prenom) LIKE :filtre\
                                OR c.telephone LIKE :filtre\
                                OR c.adresse LIKE :filtre"));

QString const * const RequetesSQL::appareilsPourClient =
        new QString(
            "SELECT\
                a.id AS '#',\
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
                (select id, nom from types) t\
            ON\
                a.idType = t.id\
            WHERE\
                a.idClient = :idClient");

QString const * const RequetesSQL::toutesFichesPourAppareil =
        new QString("SELECT\
                        f.id,\
                        f.priorite as 'Priorité',\
                        t.nom as 'Technicien',\
                        s.nom as 'Statut',\
                        f.commentaire as 'Commentaire'\
                    FROM\
                        fiches f\
                    LEFT OUTER JOIN\
                        techniciens t\
                    ON\
                        f.idTechnicien = t.id\
                    LEFT OUTER JOIN\
                        statutsFiche s\
                    ON\
                        f.idStatut = s.id\
                    WHERE f.idAppareil=:idAppareil");

QString const * const RequetesSQL::fichesActivesPourAppareil =
        new QString(*toutesFichesPourAppareil +
                    QString(" AND f.idStatut <> 5"));

QString const * const RequetesSQL::afficherAppareils =
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

QString const * const RequetesSQL::filtrerAppareils =
        new QString(*afficherAppareils +
                     QString(" WHERE c.telephone LIKE :filtre\
                             OR t.nom LIKE :filtre\
                             OR f.nom LIKE :filtre\
                             OR a.description LIKE :filtre"));

QString const * const RequetesSQL::afficherToutesActions =
        new QString("SELECT\
                        id,\
                        nom as 'Action',\
                        description as 'Description',\
                        IF (etat < 1, '', '✓') as 'Activée'\
                    FROM actions");

QString const * const RequetesSQL::afficherActionsActives =
        new QString("SELECT\
                         id,\
                         nom as 'Action',\
                         description as 'Description'\
                     FROM actions\
                     WHERE etat = 1");

QString const * const RequetesSQL::filtrerToutesActions =
        new QString(*afficherToutesActions
                      + QString(" WHERE id LIKE :filtre\
                                    OR nom LIKE :filtre\
                                    OR description LIKE :filtre"));

QString const * const RequetesSQL::filtrerActionsActives =
        new QString(*afficherActionsActives
                      + QString(" HAVING id LIKE :filtre\
                                    OR nom LIKE :filtre\
                                    OR description LIKE :filtre"));

QString const * const RequetesSQL::afficherEnsembles =
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

QString const * const RequetesSQL::afficherFiches =
        new QString("SELECT\
                        f.id,\
                        c.telephone as 'Client',\
                        f.priorite as 'Priorité',\
                        s.nom as 'Statut',\
                        f.commentaire as 'Commentaire'\
                    FROM\
                        fiches f\
                    LEFT OUTER JOIN\
                        statutsFiche s\
                    ON\
                        f.idStatut = s.id\
                    LEFT OUTER JOIN\
                        appareils a\
                    ON\
                        f.idAppareil = a.id\
                    LEFT OUTER JOIN\
                        clients c\
                    ON\
                        a.idClient = c.id");

QString const * const RequetesSQL::filtrerFiches =
        new QString(*afficherFiches +
                    QString(" WHERE c.telephone LIKE :filtre\
                                OR f.priorite LIKE :filtre\
                                OR s.nom LIKE :filtre\
                                OR f.commentaire LIKE :filtre"));

const QString* RequetesSQL::listerBD =
        new QString("show databases");
