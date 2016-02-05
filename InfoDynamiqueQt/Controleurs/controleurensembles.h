#ifndef CONTROLEURGESTIONENSEMBLE_H
#define CONTROLEURGESTIONENSEMBLE_H

#include <QObject>

class ControleurGestionEnsemble : public QObject
{
    Q_OBJECT

public:

    explicit ControleurGestionEnsemble(QObject* parent = 0);

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
