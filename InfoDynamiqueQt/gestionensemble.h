#ifndef GESTIONENSEMBLE_H
#define GESTIONENSEMBLE_H

#include <QDialog>

namespace Ui {
class gestionEnsemble;
}

class gestionEnsemble : public QDialog
{
    Q_OBJECT

public:
    explicit gestionEnsemble(QWidget *parent = 0);
    ~gestionEnsemble();

private:
    Ui::gestionEnsemble *ui;
};

#endif // GESTIONENSEMBLE_H
