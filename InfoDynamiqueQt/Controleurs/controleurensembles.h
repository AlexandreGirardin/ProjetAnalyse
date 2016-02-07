#ifndef CONTROLEURGESTIONENSEMBLE_H
#define CONTROLEURGESTIONENSEMBLE_H

#include <QObject>

#include "Vues/vueensemble.h"
#include "Vues/vuegestionensemble.h"

class ControleurGestionEnsemble : public QObject
{
    Q_OBJECT

public:

    explicit ControleurGestionEnsemble(QObject* parent = 0);

private:

    /**
     * @brief assignerEnsemble
     * Insère les informations d'un ensemble dans les champs d'une fiche de gestion
     * @param vue La vue cible
     * @param ensemble L'ensemble source
     */
    void assignerEnsemble(VueGestionEnsemble* vue, const EnsembleActions* ensemble) const;

    /**
     * @brief assignerEnsemble
     * Insère les informations d'un ensemble dans les champs d'une fiche d'affichage
     * @param vue La vue cible
     * @param ensemble L'ensemble source
     */
    void assignerEnsemble(VueEnsemble *vue, const EnsembleActions *ensemble) const;

    /**
     * @brief extraireEnsemble
     * Transfère la valeur des champs d'une vue dans un ensemble
     * @param ensemble L'ensemble cible
     * @param vue La vue source
     */
    void extraireEnsemble(EnsembleActions* ensemble, const VueGestionEnsemble* vue) const;

public slots:

    /**
     * @brief creerEnsemble
     * Lance la création d'un nouvel ensemble
     */
    void creerEnsemble();

    /**
     * @brief modifierEnsemble
     * Lance l'édition de l'ensemble actuellement sélectionné
     */
    void modifierEnsemble(const int &idEnsemble);

    /**
     * @brief voirEnsemble
     * Lance la visualisation de l'ensemble donné
     * @param idEnsemble L'id de l'ensemble à afficher
     */
    void voirEnsemble(const int &idEnsemble) const;

    /**
     * @brief supprimerEnsemble
     * Lance la suppression de l'ensemble donné
     * @param idEnsemble L'id de l'ensemble à supprimer
     */
    void supprimerEnsemble(const int &idEnsemble);

signals:

    /**
     * @brief ensemblesModifies
     * Émis lorsqu'il y a eu une modification dans la base de données
     */
    void ensemblesModifies();

};

#endif // CONTROLEURGESTIONENSEMBLE_H
