#ifndef FRAGMENT_H
#define FRAGMENT_H

#include <QWidget>

namespace Ui {
class VueFragment;
}

class VueFragment : public QWidget
{
    Q_OBJECT

public:
    explicit VueFragment(QWidget *parent = 0);
    ~VueFragment();

private:
    Ui::VueFragment *ui;


public slots:
    void changerEtiquette();

signals:
    void clicCreer(void);
    void clicEditer(void);
    void clicVoir(void);
    void caseCochee(void);
    void caseDecochee(void);
    void rechercher(void);

};

#endif // FRAGMENT_H
