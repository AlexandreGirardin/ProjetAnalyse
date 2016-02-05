#ifndef VUEENSEMBLE_H
#define VUEENSEMBLE_H

#include <QDialog>

namespace Ui {
class VueEnsemble;
}

class VueEnsemble : public QDialog
{
    Q_OBJECT

public:
    explicit VueEnsemble(QWidget *parent = 0);
    ~VueEnsemble();

private:
    Ui::VueEnsemble *ui;
};

#endif // VUEENSEMBLE_H
