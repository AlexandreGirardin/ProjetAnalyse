#ifndef VUERAPPORT_H
#define VUERAPPORT_H

#include <QDialog>

namespace Ui {
class vueRapport;
}

class vueRapport : public QDialog
{
    Q_OBJECT

public:
    explicit vueRapport(QWidget *parent = 0);
    ~vueRapport();

private:
    Ui::vueRapport *ui;
};

#endif // VUERAPPORT_H
