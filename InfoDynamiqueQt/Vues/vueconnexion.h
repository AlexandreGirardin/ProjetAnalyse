#ifndef VUECONNEXION_H
#define VUECONNEXION_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>

namespace Ui {
class VueConnexion;
}

class VueConnexion : public QDialog
{
    Q_OBJECT

public:
    explicit VueConnexion(QWidget *parent = 0);
    ~VueConnexion();

    QString getHote();
    int getPort();
    QString getUsager();
    QString getMotDePasse();

    void setHote(QString value);
    void setPort(int value);
    void setUsager(QString value);
    void setMotDePasse(QString value);
private:
    Ui::VueConnexion *ui;
};

#endif // VUECONNEXION_H
