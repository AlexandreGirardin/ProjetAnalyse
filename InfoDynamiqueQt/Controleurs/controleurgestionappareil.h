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

public slots:

    /**
     * @brief ajouterAppareil
     * Lance la création d'un nouvel appareil
     * @param idClient L'id du client
     */
    void ajouterAppareil(const int &idClient);

    /**
     * @brief modifierAppareil
     * Lance la modification de l'appareil
     * @param idAppareil L'id de l'appareil à modifier
     */
    void modifierAppareil(const int &idAppareil);

    /**
     * @brief voirAppareil
     * Lance la visualisation de l'appareil
     * @param idAppareil L'id de l'appareil à visualiser
     */
    void voirAppareil(const int &idAppareil);

signals:

    /**
     * @brief donneesModifiees
     * Lancé lorsque les valeurs du tableau ont été modifiées
     */
    void donneesModifiees();
};

#endif // CONTROLEURGESTIONAPPAREIL_H
