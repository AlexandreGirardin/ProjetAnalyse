#ifndef AIDEMAPPEURS_H
#define AIDEMAPPEURS_H

class QDateTime;

class AideMappeurs
{

    // Fonctions utiles à tous les mappeurs

public:

    /**
     * @brief derniereInsertion
     * Retourne l'id de la dernière insertion dans la base de données
     * @return L'id de la dernière insertion
     */
    static int derniereInsertion();

    static void noterModification();

    static QDateTime* derniereModification();
};

#endif // AIDEMAPPEURS_H
