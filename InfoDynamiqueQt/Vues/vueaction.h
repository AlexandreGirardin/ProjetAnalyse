#ifndef VUEACTION_H
#define VUEACTION_H

#include <QDialog>

namespace Ui {
class VueAction;
}

class VueAction : public QDialog
{
    Q_OBJECT

public:
    explicit VueAction(QWidget *parent = 0);
    ~VueAction();

    void setNom(const QString &nom);

    void setDescription(const QString &description);

private:
    Ui::VueAction *ui;
};

#endif // VUEACTION_H
