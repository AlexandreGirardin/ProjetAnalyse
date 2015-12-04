#ifndef FRAGMENT_H
#define FRAGMENT_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QTableWidget>

namespace Ui {
class VueFragment;
}

class VueFragment : public QWidget
{
    Q_OBJECT

public:
    explicit VueFragment(QWidget *parent = 0);
    ~VueFragment();

    QLabel *getEtiquette() const;
    QPushButton *getBouton1() const;
    QPushButton *getBouton2() const;
    QPushButton *getBouton3() const;
    QCheckBox *getCaseCocher() const;
    QLineEdit *getChamp() const;
    QTableWidget *getTableau() const;

private:
    Ui::VueFragment *ui;

public slots:

signals:
    void clicCreer(void);
    void clicEditer(void);
    void clicVoir(void);
    void caseCochee(void);
    void caseDecochee(void);
    void rechercher(void);

};
#endif // FRAGMENT_H
