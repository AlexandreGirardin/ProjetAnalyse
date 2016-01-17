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

    // Vue servant à créer, visualiser et modifier un client

public:

    explicit VueGestionClient(QWidget* parent = 0);
    ~VueGestionClient();

    QLineEdit* getChampPrenom() const;
    QLineEdit* getChampNom() const;
    QLineEdit* getChampTelephone() const;
    QLineEdit* getChampCourriel() const;

public slots:

    /**
     * @brief setLectureSeule
     * Rend la vue non éditable
     */
    void setLectureSeule();

    /**
     * @brief setEditable
     * Rend la vue éditable
     */
    void setEditable();

private:

    Ui::VueGestionClient* ui;
};

#endif // GESTIONCLIENT_H
