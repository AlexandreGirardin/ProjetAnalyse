#ifndef GESTIONENSEMBLE_H
#define GESTIONENSEMBLE_H

#include <QDialog>

namespace Ui {
class VueGestionEnsemble;
}

class VueGestionEnsemble : public QDialog
{
    Q_OBJECT

public:
    explicit VueGestionEnsemble(QWidget *parent = 0);
    ~VueGestionEnsemble();

private:
    Ui::VueGestionEnsemble *ui;
};

#endif // GESTIONENSEMBLE_H
