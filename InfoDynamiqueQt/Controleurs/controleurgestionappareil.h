#ifndef CONTROLEURGESTIONAPPAREIL_H
#define CONTROLEURGESTIONAPPAREIL_H

#include <QObject>

#include "Vues/vuegestionappareil.h"

class ControleurGestionAppareil : public QObject
{
    Q_OBJECT

    // Contrôle l'exécution de la création, de la lecture et de la mise à jour des appareils

public:

    /**
     * @brief ControleurGestionAppareil
     * @param parent
     */
    explicit ControleurGestionAppareil(QObject* parent = 0);

    // La vue utilisée pour modifier un appareil
    VueGestionAppareil* vueGestionAppareil;

public slots:

    /**
     * @brief ajouterAppareil Lance la création d'un nouvel appareil
     */
    void ajouterAppareil();

};

#endif // CONTROLEURGESTIONAPPAREIL_H
