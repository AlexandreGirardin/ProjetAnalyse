#ifndef GESTIONTACHE_H
#define GESTIONTACHE_H

#include <QDialog>

namespace Ui {
class VueGestionTache;
}

class VueGestionTache : public QDialog
{
    Q_OBJECT

    // Vue servant à créer, visualiser et modifier une tâche

public:

    /**
     * @brief VueGestionTache
     * Le constructeur de la vue
     * @param parent Le widget parent de la vue
     */
    explicit VueGestionTache(QWidget* parent = 0);

    ~VueGestionTache();

private:

    Ui::VueGestionTache* ui;

};

#endif // GESTIONTACHE_H
