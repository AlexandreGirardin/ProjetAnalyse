#ifndef VUEGESTIONACTION_H
#define VUEGESTIONACTION_H

#include <QDialog>

namespace Ui {
class vuegestionaction;
}

class vuegestionaction : public QDialog
{
    Q_OBJECT

public:
    explicit vuegestionaction(QWidget *parent = 0);
    ~vuegestionaction();

private:
    Ui::vuegestionaction *ui;
};

#endif // VUEGESTIONACTION_H
