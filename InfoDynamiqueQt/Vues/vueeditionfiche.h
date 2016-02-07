#ifndef EDITIONFICHE_H
#define EDITIONFICHE_H

#include <QDialog>

#include "Vues/fragment.h"

namespace Ui {
class VueEditionFiche;
}

class VueEditionFiche : public QDialog
{
    Q_OBJECT

    // Vue permettant d'éditer en détails une fiche déjà créée

public:
    explicit VueEditionFiche(QWidget* parent = 0);
    ~VueEditionFiche();

private:
    Ui::VueEditionFiche* ui;

    Fragment* fragmentTaches;

    Fragment* fragmentPieces;

    void configurerFragmentTaches();
    void configurerFragmentPieces();
};

#endif // EDITIONFICHE_H
