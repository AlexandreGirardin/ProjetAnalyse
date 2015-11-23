#ifndef FRAGMENT_H
#define FRAGMENT_H

#include <QWidget>

namespace Ui {
class Fragment;
}

class Fragment : public QWidget
{
    Q_OBJECT

public:
    explicit Fragment(QWidget *parent = 0);
    ~Fragment();

private:
    Ui::Fragment *ui;
};

#endif // FRAGMENT_H
