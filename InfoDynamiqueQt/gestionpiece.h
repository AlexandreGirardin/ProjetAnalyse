#ifndef GESTIONPIECE_H
#define GESTIONPIECE_H

#include <QDialog>

namespace Ui {
class gestionPiece;
}

class gestionPiece : public QDialog
{
    Q_OBJECT

public:
    explicit gestionPiece(QWidget *parent = 0);
    ~gestionPiece();

private:
    Ui::gestionPiece *ui;
};

#endif // GESTIONPIECE_H
