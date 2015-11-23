#ifndef GESTIONCLIENT_H
#define GESTIONCLIENT_H

#include <QDialog>

namespace Ui {
class gestionClient;
}

class gestionClient : public QDialog
{
    Q_OBJECT

public:
    explicit gestionClient(QWidget *parent = 0);
    ~gestionClient();

private:
    Ui::gestionClient *ui;
};

#endif // GESTIONCLIENT_H
