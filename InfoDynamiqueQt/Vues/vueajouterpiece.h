#ifndef VUEAJOUTERPIECE_H
#define VUEAJOUTERPIECE_H

#include <QDialog>

namespace Ui {
class VueAjouterPiece;
}

class VueAjouterPiece : public QDialog
{
    Q_OBJECT

public:
    explicit VueAjouterPiece(QWidget *parent = 0);
    ~VueAjouterPiece();

private:
    Ui::VueAjouterPiece *ui;
};

#endif // VUEAJOUTERPIECE_H
