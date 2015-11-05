#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "action.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    explicit Dialog(QWidget *parent, Action *a_action);
    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
