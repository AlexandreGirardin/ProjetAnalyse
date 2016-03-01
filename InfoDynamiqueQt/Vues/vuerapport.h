#ifndef VUERAPPORT_H
#define VUERAPPORT_H

class Client;
class Appareil;
class Tache;
class Piece;

#include <QDialog>

namespace Ui {
class vueRapport;
}

class VueRapport : public QDialog
{
    Q_OBJECT

public:
    explicit VueRapport(QWidget *parent = 0);
    ~VueRapport();

    void setInformations(const Client *client, const Appareil *appareil);

    void setDescription(const QString &description);

    void setTaches(const QList<Tache*>* taches);

    void setPieces(const QList<Piece*>* pieces);

private:
    Ui::vueRapport *ui;
};

#endif // VUERAPPORT_H
