#ifndef VUEAPPAREIL_H
#define VUEAPPAREIL_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>

namespace Ui {
class VueAppareil;
}

class VueAppareil : public QDialog
{
    Q_OBJECT

public:
    explicit VueAppareil(QWidget *parent = 0);
    ~VueAppareil();

    QLineEdit* getChampType() const;
    QLineEdit* getChampFabricant() const;
    QLineEdit* getChampMotDePasse() const;
    QTextEdit* getChampDescription() const;

private:
    Ui::VueAppareil *ui;
};

#endif // VUEAPPAREIL_H
