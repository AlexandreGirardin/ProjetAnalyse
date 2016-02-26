#ifndef TESTS_H
#define TESTS_H

#include <QMainWindow>

namespace Ui {
class tests;
}

class tests : public QMainWindow
{
    Q_OBJECT

public:
    explicit tests(QWidget *parent = 0);
    ~tests();

private:
    Ui::tests *ui;
};

#endif // TESTS_H
