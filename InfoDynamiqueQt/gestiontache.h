#ifndef GESTIONTACHE_H
#define GESTIONTACHE_H

#include <QDialog>

namespace Ui {
class gestionTache;
}

class gestionTache : public QDialog
{
    Q_OBJECT

public:
    explicit gestionTache(QWidget *parent = 0);
    ~gestionTache();

private:
    Ui::gestionTache *ui;
};

#endif // GESTIONTACHE_H
