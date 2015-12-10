#ifndef GESTIONCLIENT_H
#define GESTIONCLIENT_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class VueGestionClient;
}

class VueGestionClient : public QDialog
{
    Q_OBJECT

public:
    explicit VueGestionClient(QWidget *parent = 0);
    ~VueGestionClient();

    QLineEdit* getChampPrenom() const;
    QLineEdit* getChampNom() const;
    QLineEdit* getChampTelephone() const;
    QLineEdit* getChampCourriel() const;

private slots:

public slots:
    void setLectureSeule();

    void setEditable();

private:
    Ui::VueGestionClient *ui;
};

#endif // GESTIONCLIENT_H
