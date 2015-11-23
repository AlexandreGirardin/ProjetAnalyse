#ifndef GESTIONAPPAREIL_H
#define GESTIONAPPAREIL_H

#include <QDialog>

namespace Ui {
class gestionAppareil;
}

class gestionAppareil : public QDialog
{
    Q_OBJECT

public:
    explicit gestionAppareil(QWidget *parent = 0);
    ~gestionAppareil();

private:
    Ui::gestionAppareil *ui;
};

#endif // GESTIONAPPAREIL_H
