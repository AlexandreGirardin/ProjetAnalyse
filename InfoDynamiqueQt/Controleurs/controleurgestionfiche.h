#ifndef CONTROLEURGESTIONFICHE_H
#define CONTROLEURGESTIONFICHE_H

#include <QObject>

#include "Vues/vuegestionfiche.h"

class ControleurGestionFiche : public QObject
{
    Q_OBJECT

public:
    explicit ControleurGestionFiche(QObject *parent = 0);

    // La vue utilisée pour editer une fiche
    VueGestionFiche* vueGestionFiche;

signals:

public slots:

    /**
     * @brief ajouterFiche Lance la création d'une nouvelle fiche
     */
    void ajouterFiche();

};

#endif // CONTROLEURGESTIONFICHE_H
