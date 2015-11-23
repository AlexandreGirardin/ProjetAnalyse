#ifndef EDITIONFICHE_H
#define EDITIONFICHE_H

#include <QWidget>

namespace Ui {
class editionFiche;
}

class editionFiche : public QWidget
{
    Q_OBJECT

public:
    explicit editionFiche(QWidget *parent = 0);
    ~editionFiche();

private:
    Ui::editionFiche *ui;
};

#endif // EDITIONFICHE_H
