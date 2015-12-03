#ifndef VUESECONDAIRE_H
#define VUESECONDAIRE_H

#include <QWidget>

namespace Ui {
class VueSecondaire;
}

class VueSecondaire : public QWidget
{
    Q_OBJECT

public:
    explicit VueSecondaire(QWidget *parent = 0);
    ~VueSecondaire();

    Ui::VueSecondaire *getUi() const;

private:
    Ui::VueSecondaire *ui;
};

#endif // VUESECONDAIRE_H
