#ifndef VUEAUTHENTIFICATION_H
#define VUEAUTHENTIFICATION_H

#include <QDialog>

namespace Ui {
class VueAuthentification;
}

class VueAuthentification : public QDialog
{
    Q_OBJECT

public:
    explicit VueAuthentification(QWidget *parent = 0);
    ~VueAuthentification();

private:
    Ui::VueAuthentification *ui;
};

#endif // VUEAUTHENTIFICATION_H
