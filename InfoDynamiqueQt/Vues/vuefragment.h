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
    QPushButton *getBoutonAjouter() const;
    QPushButton *getBoutonModifier() const;
    QPushButton *getBoutonVoir() const;
    QCheckBox *getCaseCocher() const;
    QLineEdit *getChamp() const;
    QTableView *getTableau() const;
    void setModele(QAbstractTableModel*);
    int getId(QModelIndex);

private:
    Ui::VueFragment *ui;

public slots:
    void relacherModele();
    void activerBoutonsModele();
    void desactiverBoutonsModele();

private slots:
    void signalerCase(bool);
    void signalerSelection(QModelIndex, QModelIndex);

signals:
    void clicCreer();
    void clicEditer();
    void clicVoir();
    void caseCochee();
    void caseDecochee();
    void rechercher();
    void nouvelleSelection(QModelIndex);

};
#endif // FRAGMENT_H
