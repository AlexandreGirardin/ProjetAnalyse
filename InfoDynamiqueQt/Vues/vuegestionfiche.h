#ifndef GESTIONFICHE_H
#define GESTIONFICHE_H

#include <QDialog>

namespace Ui {
class VueGestionFiche;
}

class VueGestionFiche : public QDialog
{
    Q_OBJECT

    // Vue servant à modifier les informations générales d'une fiche

public:
    explicit VueGestionFiche(QWidget* parent = 0);
    ~VueGestionFiche();

private:
    Ui::VueGestionFiche* ui;
};

#endif // GESTIONFICHE_H
