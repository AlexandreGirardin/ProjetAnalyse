#ifndef EDITIONFICHE_H
#define EDITIONFICHE_H

#include <QWidget>

namespace Ui {
class VueEditionFiche;
}

class VueEditionFiche : public QWidget
{
    Q_OBJECT

    // Vue permettant d'éditer en détails une fiche déjà créée

public:
    explicit VueEditionFiche(QWidget *parent = 0);
    ~VueEditionFiche();

private:
    Ui::VueEditionFiche *ui;
};

#endif // EDITIONFICHE_H
