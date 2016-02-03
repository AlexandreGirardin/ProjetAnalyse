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

public slots:

    /**
     * @brief modifierEnsemble
     * Lance l'édition de l'ensemble actuellement sélectionné
     */
    void modifierEnsemble();

};

#endif // CONTROLEURGESTIONENSEMBLE_H
