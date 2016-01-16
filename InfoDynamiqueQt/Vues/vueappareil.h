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

    QString getType();
    QString getFabricant();
    QString getMotDePasse();
    QString getDescription();

    void setType(QString value);
    void setFabricant(QString value);
    void setMotDePasse(QString value);
    void setDescription(QString value);

private:
    Ui::VueAppareil *ui;
};

#endif // VUEAPPAREIL_H
