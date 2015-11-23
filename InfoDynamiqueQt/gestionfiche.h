#ifndef GESTIONFICHE_H
#define GESTIONFICHE_H

#include <QDialog>

namespace Ui {
class gestionFiche;
}

class gestionFiche : public QDialog
{
    Q_OBJECT

public:
    explicit gestionFiche(QWidget *parent = 0);
    ~gestionFiche();

private:
    Ui::gestionFiche *ui;
};

#endif // GESTIONFICHE_H
