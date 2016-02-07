#ifndef VUECLIENT_H
#define VUECLIENT_H

#include <QDialog>

namespace Ui {
class VueClient;
}

class VueClient : public QDialog
{
    Q_OBJECT

public:
    explicit VueClient(QWidget *parent = 0);
    ~VueClient();

    void setPrenom(const QString &prenom);

    void setNom(const QString &nom);

    void setTelephone(const QString &telephone);

    void setAdresse(const QString &adresse);

private:
    Ui::VueClient *ui;
};

#endif // VUECLIENT_H
