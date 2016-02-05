#ifndef CONTROLEURGESTIONENSEMBLE_H
#define CONTROLEURGESTIONENSEMBLE_H

#include <QObject>

class ControleurGestionEnsemble : public QObject
{
    Q_OBJECT

private:

//    VueFragment

public:

    explicit ControleurGestionEnsemble(QObject* parent = 0);

signals:

    void ensemblesModifies();

public slots:

    void creerEnsemble();

    /**
     * @brief modifierEnsemble
     * Lance l'édition de l'ensemble actuellement sélectionné
     */
    void modifierEnsemble(const int &idEnsemble);

    void voirEnsemble(const int &idEnsemble);

    void supprimerEnsemble(const int &idEnsemble);

};

#endif // CONTROLEURGESTIONENSEMBLE_H
