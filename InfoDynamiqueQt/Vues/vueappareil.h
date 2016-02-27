#ifndef VUEAPPAREIL_H
#define VUEAPPAREIL_H

#include <QDialog>

class QLineEdit;
class QTextEdit;

namespace Ui {
class VueAppareil;
}

class VueAppareil : public QDialog
{
    Q_OBJECT

public:
    explicit VueAppareil(QWidget *parent = 0);
    ~VueAppareil();

    QString getType() const;
    QString getFabricant() const;
    QString getMotDePasse() const;
    QString getDescription() const;

    void setType(const QString &value);
    void setFabricant(const QString &value);
    void setMotDePasse(const QString &value);
    void setDescription(const QString &value);

private:
    Ui::VueAppareil *ui;
};

#endif // VUEAPPAREIL_H
