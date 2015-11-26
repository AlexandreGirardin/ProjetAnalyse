#ifndef GESTIONTACHE_H
#define GESTIONTACHE_H

#include <QDialog>

namespace Ui {
class VueGestionTache;
}

class VueGestionTache : public QDialog
{
    Q_OBJECT

public:
    explicit VueGestionTache(QWidget *parent = 0);
    ~VueGestionTache();

private:
    Ui::VueGestionTache *ui;
};

#endif // GESTIONTACHE_H
