#ifndef GESTIONAPPAREIL_H
#define GESTIONAPPAREIL_H

#include <QDialog>

namespace Ui {
class VueGestionAppareil;
}

class VueGestionAppareil : public QDialog
{
    Q_OBJECT

public:
    explicit VueGestionAppareil(QWidget *parent = 0);
    ~VueGestionAppareil();

private:
    Ui::VueGestionAppareil *ui;
};

#endif // GESTIONAPPAREIL_H
