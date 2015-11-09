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
    ~Dialog();
    void setNom(QString a_nom);
    QString getNom();
    void setDescription(QString a_description);
    QString getDescription();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
