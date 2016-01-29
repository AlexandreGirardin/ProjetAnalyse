#ifndef CONTROLEURGESTIONENSEMBLE_H
#define CONTROLEURGESTIONENSEMBLE_H

#include <QObject>

class ControleurGestionEnsemble : public QObject
{
    Q_OBJECT

public:

    explicit ControleurGestionEnsemble(QObject* parent = 0);

signals:

public slots:

    void modifierEnsemble();

};

#endif // CONTROLEURGESTIONENSEMBLE_H
