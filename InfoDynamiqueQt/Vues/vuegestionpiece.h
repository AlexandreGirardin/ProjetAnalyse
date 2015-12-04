#ifndef GESTIONPIECE_H
#define GESTIONPIECE_H

#include <QDialog>

namespace Ui {
class VueGestionPiece;
}

class VueGestionPiece : public QDialog
{
    Q_OBJECT

public:
    explicit VueGestionPiece(QWidget *parent = 0);
    ~VueGestionPiece();

    QString getNom() const;
    void setNom(const QString &);

    QString getDescription() const;
    void setDescription(const QString &);

    double getPrix() const;
    void setPrix(double);

private:
    Ui::VueGestionPiece *ui;
};

#endif // GESTIONPIECE_H
